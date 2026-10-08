#!/usr/bin/env python3
"""
Thumbnails of the sprite sheets, for the documentation (documentation/*.md).

Usage:
    tools/thumbnails.py                  every sheet of sprites/*.json
    tools/thumbnails.py goblin witch     only these sheets

Reads output/<name>.png and output/<name>.json (made by tools/sprites.py, run
it first) and writes documentation/img/<name>.png:
    - a creature (c_*.pov): the first frame of its first animation (idle),
      from 4 directions side by side: face, three-quarter, side, back;
    - a prop (p_*.pov): its first frame.
On a solid background, scaled up without smoothing.

Options:
    --scale 2              enlargement (default 2)
    --background '#3a3632' background colour
"""

import argparse
import glob
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUTPUT = os.path.join(ROOT, "output")
IMG = os.path.join(ROOT, "documentation", "img")
# engine directions (src/render/spriteFacing.ts): 4 face, 3 three-quarter, 2 side, 0 back
VIEWS = [4, 3, 2, 0]


def thumbnail(name, scale, background):
    with open(os.path.join(ROOT, "sprites", f"{name}.json")) as f:
        spec = json.load(f)
    sheet = os.path.join(OUTPUT, f"{name}.png")
    tileset = os.path.join(OUTPUT, f"{name}.json")
    if not (os.path.exists(sheet) and os.path.exists(tileset)):
        print(f"  {name}: no sheet in output/, run tools/sprites.py sprites/{name}.json first", file=sys.stderr)
        return False
    with open(tileset) as f:
        ts = json.load(f)
    w, h = ts["width"], ts["height"]
    start = ts["animations"][0]["start"]
    is_prop = os.path.basename(spec["scene"]).startswith("p_")
    tiles = [start[0]] if is_prop or len(set(start)) == 1 else [start[d] for d in VIEWS]
    crops = []
    for t in tiles:
        crops += ["(", sheet, "-crop", f"{w}x{h}+{t * w}+0", "+repage", ")"]
    out = os.path.join(IMG, f"{name}.png")
    subprocess.run(
        ["convert", *crops, "+append", "-background", background, "-alpha", "remove",
         "-alpha", "off", "-scale", f"{scale * 100}%", out],
        check=True,
    )
    print(f"  {os.path.relpath(out, ROOT)}")
    return True


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("names", nargs="*")
    parser.add_argument("--scale", type=int, default=2)
    parser.add_argument("--background", default="#3a3632")
    args = parser.parse_args()
    names = args.names or sorted(
        os.path.splitext(os.path.basename(p))[0] for p in glob.glob(os.path.join(ROOT, "sprites", "*.json"))
    )
    os.makedirs(IMG, exist_ok=True)
    ok = all([thumbnail(n, args.scale, args.background) for n in names])
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
