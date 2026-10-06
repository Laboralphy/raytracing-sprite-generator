#!/usr/bin/env python3
"""
Writes sprites/CATALOG.md: for every sprite sheet (sprites/*.json), its
animations, their directions, where their tiles start in the strip, and what
each pose is (the comment under its #case in inc/frames/<character>.inc).

Usage:
    tools/catalog.py

tools/sprites.py also rewrites it after every sheet. The tile indexes come
from sprites.build_layout, so they are the ones of the generated strip.
"""

import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from sprites import DEFAULT_FRAME, DIRECTION_COUNT, ROOT, build_layout, normalize_pose  # noqa: E402

CATALOG = os.path.join(ROOT, "sprites", "CATALOG.md")


def frames_file(scene):
    """The pose file included by the scene (inc/frames/<character>.inc), or None."""
    with open(os.path.join(ROOT, scene)) as f:
        m = re.search(r'#include\s+"(inc/frames/[^"]+)"', f.read())
    return m.group(1) if m else None


def pose_labels(path):
    """{pose number: comment under its #case}. Consecutive #case share the comment."""
    labels = {}
    pending = []
    with open(os.path.join(ROOT, path)) as f:
        for line in f:
            line = line.strip()
            m = re.match(r"#case\s*\(\s*(\d+)\s*\)", line)
            if m:
                pending.append(int(m.group(1)))
            elif pending:
                text = line[2:].strip() if line.startswith("//") else ""
                for n in pending:
                    labels[n] = text
                pending = []
    return labels


def short(label):
    """"WALK 2: lifts its back..." -> "WALK 2"."""
    return label.split(":")[0].strip()


def pose_text(pose, labels):
    a, b, blend = normalize_pose(pose)
    if blend == 0:
        name = short(labels.get(a, ""))
        return f"{a} {name}".strip()
    return f"{a}→{b} ({blend:.0%})"


def starts_text(starts, directions, view):
    if directions == 1:
        return f"{starts[0]} (vue {view})"
    step = starts[1] - starts[0]
    return f"{starts[0]} + {step}·d"


def sprite_section(spec_path):
    with open(spec_path) as f:
        spec = json.load(f)
    name = spec.get("name") or os.path.splitext(os.path.basename(spec_path))[0]
    frame = {**DEFAULT_FRAME, **spec.get("frame", {})}
    tiles, defs = build_layout(spec["animations"])
    frames = frames_file(spec["scene"])
    labels = pose_labels(frames) if frames else {}

    out = [f"## {name}", ""]
    source = f"Scène `{spec['scene']}`" + (f", poses `{frames}`" if frames else "")
    out.append(f"{source}. Cadre {frame['width']}×{frame['height']}, "
               f"{len(tiles)} image{'s' if len(tiles) > 1 else ''} ({len(tiles) * frame['width']} px de large).")
    out.append("")
    out.append("| Animation | Images | Directions | Première tuile | Durée | Boucle | Poses |")
    out.append("|---|---|---|---|---|---|---|")
    for anim, d in zip(spec["animations"], defs):
        directions = anim.get("directions", DIRECTION_COUNT)
        extra = []
        if anim.get("camera_elevation"):
            extra.append(f"caméra {anim['camera_elevation']}°")
        if anim.get("shift_x"):
            extra.append(f"shift_x {anim['shift_x']}")
        dirs = f"{directions}" + (f" ({', '.join(extra)})" if extra else "")
        poses = " · ".join(pose_text(p, labels) for p in anim["poses"])
        loop = d["loop"].replace("@LOOP_", "")
        out.append(f"| `{d['id']}` | {d['length']} | {dirs} | "
                   f"{starts_text(d['start'], directions, anim.get('view', 4))} | "
                   f"{d['duration']} ms | {loop} | {poses} |")
    out.append("")
    used = sorted({normalize_pose(p)[i] for a in spec["animations"] for p in a["poses"] for i in (0, 1)})
    if labels:
        out.append("<details><summary>Poses</summary>")
        out.append("")
        for n in sorted(labels):
            mark = "" if n in used else " *(inutilisée)*"
            out.append(f"- **{n}** : {labels[n] or '—'}{mark}")
        out.append("")
        out.append("</details>")
        out.append("")
    return name, len(tiles), frame, [d["id"] for d in defs], out


def write_catalog():
    sections = [sprite_section(p) for p in sorted(glob.glob(os.path.join(ROOT, "sprites", "*.json")))]
    lines = [
        "# Catalogue des sprites",
        "",
        "> Généré par `tools/catalog.py` (et à chaque `tools/sprites.py`) depuis `sprites/*.json`",
        "> et les commentaires des `#case` de `inc/frames/*.inc`. Ne pas éditer à la main.",
        "",
        "- **Directions** (moteur) : `d` = 0 dos, 2 nez vers la droite de l'écran, 4 face, 6 nez vers la gauche.",
        "  Une animation à 8 directions a sa première tuile en `début + longueur·d` ; une animation à 1 direction",
        "  est rendue sous la vue indiquée et sert pour les 8.",
        "- **Tuile** : index dans la bande `output/<sprite>.png` (x = index × largeur du cadre).",
        "- **Poses** : `n NOM` = pose n de `inc/frames/` ; `a→b (x %)` = pose a mélangée vers b.",
        "",
        "| Sprite | Cadre | Images | Animations |",
        "|---|---|---|---|",
    ]
    for name, count, frame, ids, _ in sections:
        lines.append(f"| [{name}](#{name}) | {frame['width']}×{frame['height']} | {count} | "
                     + ", ".join(f"`{i}`" for i in ids) + " |")
    lines.append("")
    for *_, out in sections:
        lines.extend(out)
    with open(CATALOG, "w") as f:
        f.write("\n".join(lines))
    return CATALOG


if __name__ == "__main__":
    print(write_catalog())
