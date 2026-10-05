#!/usr/bin/env python3
"""
Animated GIFs of a sprite sheet, to look at the animations outside the game.

Usage:
    tools/gifs.py zombie [witch ...]     sheets made by tools/sprites.py
    tools/gifs.py --all                  every sheet in output/

Reads output/<name>.png and output/<name>.json (the strip and its tileset,
like the engine does) and writes output/gif/<name>_<animation>.gif, one per
animation, facing the camera (engine direction 4).

- speed: the "duration" of the animation;
- @LOOP_YOYO: forth and back; @LOOP_NONE (attack, death): a pause on the last
  frame before starting again;
- a solid background (a GIF has no partial transparency: the shadow and the
  antialiased edges would be lost);
- scaled up, without smoothing.
"""

import argparse
import glob
import json
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUTPUT = os.path.join(ROOT, "output")
FACE = 4  # engine direction facing the camera (src/render/spriteFacing.ts)


def make_gifs(name, scale, background, hold):
    sheet = os.path.join(OUTPUT, f"{name}.png")
    with open(os.path.join(OUTPUT, f"{name}.json")) as f:
        tileset = json.load(f)
    w, h = tileset["width"], tileset["height"]
    os.makedirs(os.path.join(OUTPUT, "gif"), exist_ok=True)
    with tempfile.TemporaryDirectory() as work:
        for anim in tileset["animations"]:
            start = anim["start"][FACE] if isinstance(anim["start"], list) else anim["start"]
            frames = []
            for i in range(anim["length"]):
                tile = os.path.join(work, f"{anim['id']}_{i}.png")
                subprocess.run(
                    ["convert", sheet, "-crop", f"{w}x{h}+{(start + i) * w}+0", "+repage",
                     "-background", background, "-alpha", "remove", "-alpha", "off",
                     "-scale", f"{scale * 100}%", tile],
                    check=True,
                )
                frames.append(tile)
            delay = max(1, round(anim.get("duration", 150) / 10))  # centiseconds
            if anim.get("loop") == "@LOOP_YOYO" and len(frames) > 2:
                sequence = [(f, delay) for f in frames + frames[-2:0:-1]]
            else:
                sequence = [(f, delay) for f in frames]
            if anim.get("loop") == "@LOOP_NONE":
                sequence[-1] = (sequence[-1][0], hold)
            args = ["convert", "-loop", "0"]
            for frame, d in sequence:
                args += ["-delay", str(d), frame]
            out = os.path.join(OUTPUT, "gif", f"{name}_{anim['id']}.gif")
            subprocess.run(args + ["-layers", "Optimize", out], check=True)
            print(f"  {os.path.relpath(out, ROOT)} ({len(sequence)} images)")


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("names", nargs="*")
    parser.add_argument("--all", action="store_true", help="every sheet in output/")
    parser.add_argument("--scale", type=int, default=3)
    parser.add_argument("--background", default="#3a3632")
    parser.add_argument("--hold", type=int, default=100, help="pause on the last frame of a non looping animation, in 1/100 s")
    args = parser.parse_args()
    names = args.names
    if args.all:
        names = sorted(
            os.path.basename(p)[:-5] for p in glob.glob(os.path.join(OUTPUT, "*.json"))
            if os.path.exists(p[:-5] + ".png")
        )
    if not names:
        parser.print_help()
        return 1
    for name in names:
        print(name)
        make_gifs(name, args.scale, args.background, args.hold)
    return 0


if __name__ == "__main__":
    sys.exit(main())
