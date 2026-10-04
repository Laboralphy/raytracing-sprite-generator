#!/usr/bin/env python3
"""
Generates a sprite sheet for raycaster-386 from a character scene.

Usage:
    tools/sprites.py sprites/zombie.json [--preview] [--jobs N]

The spec (JSON) gives the scene to render, the frame size and the animations.
Output, in output/:
    <name>.png          one horizontal strip of frames, as raycaster-386 slices it
    <name>.json         the tileset fragment (width, height, animations) to paste in a level
    <name>.preview.png  (with --preview) a grid for checking: one row per animation and direction

An animation may set "camera_elevation" (degrees above the horizon, default 0),
for example to see a corpse on the ground from slightly above, and "shift_x"
(POV-Ray units, default 0) to move the character right in the frame, for
example when a fallen body sticks out of it.

"shadow" (optional, for the whole sheet): {"radius": 0.8, "height": 0.1,
"opacity": 0.45}, a translucent ellipse on the ground under the character
(POV-Ray units).

Strip order: animation, then direction, then frame. An animation with
"directions": 1 is rendered once and its start is repeated for all 8 facings;
it is seen from engine direction "view" (default 4: facing the camera; 3 or 5:
three-quarter front, for a body falling backward).

Directions follow raycaster-386 (src/render/spriteFacing.ts):
    0 = back, 2 = nose to the right of the screen, 4 = face, 6 = nose to the left.
In the POV-Ray scenes, direction 0 is the face and `rotate y` turns the nose to
the left, hence pov_direction = (engine_direction + 4) mod 8.

A pose is a pose number of the character (inc/frames/<character>.inc), or
[from, to, blend] for a pose interpolated by inc/Pose.inc (blend 0 = from, 1 = to).

The character scenes are not modified: a wrapper includes the scene, then
declares an orthographic camera, which replaces the one in inc/Camera.inc (the
last camera declared wins).
"""

import argparse
import json
import math
import os
import shutil
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DIRECTION_COUNT = 8

DEFAULT_FRAME = {
    "width": 64,          # pixels
    "height": 96,         # pixels
    "units_height": 6.0,  # POV-Ray units covered by the frame height (sets the scale)
    "baseline": 0.1,      # POV-Ray units between the bottom of the frame and the feet (y = 0)
}


def pov_direction(engine_direction):
    return (engine_direction + 4) % DIRECTION_COUNT


def normalize_pose(pose):
    """A pose as (from, to, blend)."""
    if isinstance(pose, (int, float)):
        return (pose, pose, 0)
    if isinstance(pose, list) and len(pose) == 3:
        return tuple(pose)
    raise ValueError(f"invalid pose {pose!r}: a number, or [from, to, blend]")


def clock_value(pov_dir, pose):
    # Decoded by inc/Animation.inc: direction = clock / 100, frame = clock mod 100.
    return pov_dir * 100 + int(pose[0])


def shadow_pov(shadow):
    """
    A translucent black ellipse on the ground under the character. Flat, it
    would be invisible from a camera at eye level, so it is a squashed
    sphere: its front half passes in front of the feet. A ray crosses two
    surfaces, hence the transmit of each one: sqrt(1 - opacity).
    """
    radius = shadow.get("radius", 0.8)
    height = shadow.get("height", 0.1)
    transmit = math.sqrt(1 - shadow.get("opacity", 0.45))
    return (
        "sphere {\n"
        "\t0, 1\n"
        f"\tscale <{radius}, {height}, {radius}>\n"
        f"\tpigment {{ rgbt <0, 0, 0, {transmit}> }}\n"
        "\tfinish { ambient 0 diffuse 0 }\n"
        "\tno_shadow\n"
        "}\n"
    )


def write_wrapper(path, scene, frame, elevation=0, shift_x=0, shadow=None):
    """
    elevation: camera angle above the horizon, in degrees. The ground point
    under the character (origin) stays on the baseline of the frame.
    shift_x: moves the character to the right in the frame, in POV-Ray units.
    shadow: {"radius", "height", "opacity"} for a shadow on the ground, or None.
    """
    units_w = frame["units_height"] * frame["width"] / frame["height"]
    e = math.radians(elevation)
    # Ground point at frame["baseline"] above the bottom of the frame: the
    # look_at point, on the vertical axis, projects to the centre.
    look_y = (frame["units_height"] / 2 - frame["baseline"]) / math.cos(e)
    loc = (100 * math.sin(e) + look_y, -100 * math.cos(e))
    with open(path, "w") as f:
        f.write(
            f'#include "{scene}"\n'
            "camera {\n"
            "\torthographic\n"
            f"\tlocation <{-shift_x}, {loc[0]}, {loc[1]}>\n"
            f"\tlook_at <{-shift_x}, {look_y}, 0>\n"
            f"\tright x * {units_w}\n"
            f"\tup y * {frame['units_height']}\n"
            "}\n"
        )
        if shadow:
            f.write(shadow_pov(shadow))


def render(wrapper, frame, pov_dir, pose, out_png):
    clock = clock_value(pov_dir, pose)
    cmd = [
        "povray", f"+I{wrapper}", f"+L{ROOT}", f"+O{out_png}",
        f"+W{frame['width']}", f"+H{frame['height']}",
        "+UA", "+A0.1", "+R3", "+Q9", f"+K{clock}",
        "-D", "-GA", "+WT1",
        f"Declare=N_Pose_From={pose[0]}", f"Declare=N_Pose_To={pose[1]}", f"Declare=N_Pose_Blend={pose[2]}",
    ]
    result = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if result.returncode != 0 or not os.path.exists(out_png):
        raise RuntimeError(f"povray failed (direction {pov_dir}, pose {pose}):\n{result.stderr[-2000:]}")


def build_layout(animations):
    """Lists the tiles in strip order and the tileset animations that index them."""
    tiles = []      # (pov_dir, pose, (camera elevation, shift_x)) per tile
    defs = []
    for anim in animations:
        poses = [normalize_pose(p) for p in anim["poses"]]
        directions = anim.get("directions", DIRECTION_COUNT)
        if directions not in (1, DIRECTION_COUNT):
            raise ValueError(f'animation "{anim["id"]}": directions must be 1 or {DIRECTION_COUNT}')
        starts = []
        for d in range(directions):
            starts.append(len(tiles))
            pov_dir = pov_direction(d if directions > 1 else anim.get("view", 4))
            camera = (anim.get("camera_elevation", 0), anim.get("shift_x", 0))
            tiles.extend((pov_dir, pose, camera) for pose in poses)
        if directions == 1:
            starts = starts * DIRECTION_COUNT
        defs.append({
            "id": anim["id"],
            "start": starts,
            "length": len(poses),
            "duration": anim.get("duration", 150),
            "loop": anim.get("loop", "@LOOP_FORWARD"),
        })
    return tiles, defs


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("spec")
    parser.add_argument("--preview", action="store_true", help="also write a grid for checking")
    parser.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    parser.add_argument("--out", default=os.path.join(ROOT, "output"))
    args = parser.parse_args()

    with open(args.spec) as f:
        spec = json.load(f)
    name = spec.get("name") or os.path.splitext(os.path.basename(args.spec))[0]
    frame = {**DEFAULT_FRAME, **spec.get("frame", {})}
    tiles, defs = build_layout(spec["animations"])

    os.makedirs(args.out, exist_ok=True)
    work = tempfile.mkdtemp(prefix=f"sprites-{name}-")
    try:
        wrappers = {}
        for camera in sorted({t[2] for t in tiles}):
            wrappers[camera] = os.path.join(work, f"wrapper_{len(wrappers)}.pov")
            write_wrapper(wrappers[camera], spec["scene"], frame, *camera, shadow=spec.get("shadow"))

        # Several tiles may share a pose and a direction: render each once.
        unique = sorted(set(tiles))
        pngs = {key: os.path.join(work, f"tile_{i}.png") for i, key in enumerate(unique)}
        print(f"{name}: {len(tiles)} tiles, {len(unique)} renders, {frame['width']}x{frame['height']}")
        with ThreadPoolExecutor(max_workers=args.jobs) as pool:
            jobs = [pool.submit(render, wrappers[key[2]], frame, key[0], key[1], pngs[key]) for key in unique]
            for job in jobs:
                job.result()

        sheet = os.path.join(args.out, f"{name}.png")
        subprocess.run(
            ["convert", *[pngs[t] for t in tiles], "-background", "none", "+append", "+repage", sheet],
            check=True,
        )
        tileset = {"width": frame["width"], "height": frame["height"], "animations": defs}
        with open(os.path.join(args.out, f"{name}.json"), "w") as f:
            json.dump(tileset, f, indent=2)
            f.write("\n")
        print(f"  {sheet} ({len(tiles) * frame['width']}x{frame['height']})")

        if args.preview:
            preview = os.path.join(args.out, f"{name}.preview.png")
            rows = []
            for anim, d in zip(spec["animations"], defs):
                n = d["length"]
                starts = d["start"] if anim.get("directions", DIRECTION_COUNT) > 1 else d["start"][:1]
                for i, s in enumerate(starts):
                    row = os.path.join(work, f"row_{d['id']}_{i}.png")
                    subprocess.run(
                        ["convert", *[pngs[t] for t in tiles[s:s + n]], "-background", "none", "+append", "+repage", row],
                        check=True,
                    )
                    rows.append(row)
            subprocess.run(
                ["convert", *rows, "-background", "none", "-gravity", "west", "-append", "+repage",
                 "-background", "#6a8a7a", "-flatten", "-scale", "200%", preview],
                check=True,
            )
            print(f"  {preview}")
    finally:
        shutil.rmtree(work, ignore_errors=True)


if __name__ == "__main__":
    sys.exit(main())
