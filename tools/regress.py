#!/usr/bin/env python3
"""
Regression check for the base files: renders every character, every pose,
8 directions, and compares the result pixel by pixel with a reference.

Usage:
    tools/regress.py save      renders the reference into output/regress/ref
    tools/regress.py check     renders into output/regress/new and compares
    tools/regress.py check c_troll_1     only some scenes

Renders use the sprite camera of tools/sprites.py, without antialiasing so the
output is deterministic.
"""

import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from sprites import DEFAULT_FRAME, ROOT, write_wrapper  # noqa: E402

# Scene -> number of poses (integer poses 0..n-1).
SCENES = {
    "c_dummy": 6,
    "c_zombie_1": 6,
    "c_ghoul_1": 6,
    "c_skeleton_1": 6,
    "c_knight_mace": 6,
    "c_mummy_1": 7,
    "c_troll_1": 6,
    "c_witch_blue": 5,
}
FRAME = {**DEFAULT_FRAME, "width": 128, "height": 192}
BASE = os.path.join(ROOT, "output", "regress")


def render(scene, pose, pov_dir, out_dir):
    os.makedirs(out_dir, exist_ok=True)
    wrapper = os.path.join(out_dir, "wrapper.pov")
    out = os.path.join(out_dir, f"p{pose}_d{pov_dir}.png")
    cmd = [
        "povray", f"+I{wrapper}", f"+L{ROOT}", f"+O{out}",
        f"+W{FRAME['width']}", f"+H{FRAME['height']}",
        "+UA", "-A", f"+K{pov_dir * 100 + pose}", "-D", "-GA", "+WT1",
    ]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        raise RuntimeError(f"{scene} pose {pose} dir {pov_dir}:\n{r.stderr[-1500:]}")
    return out


def render_all(kind, scenes):
    jobs = []
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as pool:
        for scene in scenes:
            out_dir = os.path.join(BASE, kind, scene)
            os.makedirs(out_dir, exist_ok=True)
            write_wrapper(os.path.join(out_dir, "wrapper.pov"), f"{scene}.pov", FRAME)
            for pose in range(SCENES[scene]):
                for d in range(8):
                    jobs.append(pool.submit(render, scene, pose, d, out_dir))
        for j in jobs:
            j.result()
    return len(jobs)


def differing_pixels(a, b):
    r = subprocess.run(["compare", "-metric", "AE", a, b, "null:"], capture_output=True, text=True)
    return int(float(r.stderr.split()[0]))


def main():
    if len(sys.argv) < 2 or sys.argv[1] not in ("save", "check"):
        print(__doc__)
        return 1
    scenes = sys.argv[2:] or list(SCENES)
    if sys.argv[1] == "save":
        print(f"reference: {render_all('ref', scenes)} images")
        return 0
    n = render_all("new", scenes)
    failures = 0
    for scene in scenes:
        bad = []
        for pose in range(SCENES[scene]):
            for d in range(8):
                name = f"p{pose}_d{d}.png"
                diff = differing_pixels(os.path.join(BASE, "ref", scene, name), os.path.join(BASE, "new", scene, name))
                if diff:
                    bad.append(f"{name}:{diff}")
        failures += len(bad)
        print(f"{scene}: {'OK' if not bad else 'DIFFERENT ' + ' '.join(bad[:6]) + (' ...' if len(bad) > 6 else '')}")
    print(f"{n} images, {failures} different")
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
