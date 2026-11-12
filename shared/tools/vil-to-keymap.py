#!/usr/bin/env python3
"""Rewrite the keymaps[] array in a keymap.c from a Vial .vil export.

Usage: python3 shared/tools/vil-to-keymap.py <layout.vil> <keymap.c>

Only the keymaps[] block is replaced; the rest of keymap.c is kept. Layers are
written in raw matrix order (as stored in the .vil), so no LAYOUT macro is needed.
Vial's legacy keycode names are translated with ~/vial-qmk/quantum/vial_ensure_keycode.h.
Macros, tap dances, combos and QMK settings in the .vil are not carried over.
"""
import json
import re
import sys
from pathlib import Path

ALIASES = Path.home() / "vial-qmk/quantum/vial_ensure_keycode.h"
START = "const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {"


def load_aliases():
    aliases = {}
    for line in ALIASES.read_text().splitlines():
        m = re.match(r"#define\s+(\w+)\s+(\w+)\s*$", line)
        if m and m.group(1) != m.group(2):
            aliases[m.group(1)] = m.group(2)
    return aliases


def to_c(key, aliases):
    if key == -1:
        return "KC_NO"
    key = re.sub(r"\bLT(\d+)\(", r"LT(\1, ", key)

    def resolve(m):
        name = m.group(0)
        seen = set()
        while name in aliases and name not in seen:
            seen.add(name)
            name = aliases[name]
        return name

    return re.sub(r"\b[A-Za-z_]\w*\b", resolve, key)


def render(layers, aliases):
    out = [START]
    for n, layer in enumerate(layers):
        out.append(f"    [{n}] = {{")
        for row in layer:
            out.append("        {" + ", ".join(to_c(k, aliases) for k in row) + "},")
        out.append("    },")
    out.append("};")
    return "\n".join(out)


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    vil, keymap = Path(sys.argv[1]), Path(sys.argv[2])
    layers = json.loads(vil.read_text())["layout"]
    src = keymap.read_text()
    start = src.index(START)
    end = src.index("\n};", start) + len("\n};")
    keymap.write_text(src[:start] + render(layers, load_aliases()) + src[end:])
    print(f"wrote {len(layers)} layers to {keymap}")


if __name__ == "__main__":
    main()
