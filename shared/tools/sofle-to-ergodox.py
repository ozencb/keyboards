#!/usr/bin/env python3
"""Generate the ErgoDox EZ Vial layout from the wired Sofle one.

Usage: python3 shared/tools/sofle-to-ergodox.py
"""
import json
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
SRC = REPO / "boards/sofle-v2-handwired-wired/firmware/vial.vil"
DST = REPO / "boards/ergodox-ez/firmware/vial.vil"

ERGODOX_UID = 5112003259555888239  # VIAL_KEYBOARD_UID in firmware/vial/config.h
ROWS, COLS = 14, 6  # ErgoDox matrix: row = physical column (0-6 left, 7-13 right)
MISSING = {(6, 2), (7, 2), (5, 4), (6, 4), (7, 4), (8, 4), (0, 5), (13, 5)}

# Sofle thumb row index -> ErgoDox position (left, right)
THUMBS = {
    0: ((2, 5), (11, 5)),  # outer thumb key -> second big thumb key
    2: ((2, 4), (11, 4)),  # Ctrl -> bottom row
    3: ((3, 4), (10, 4)),  # Alt
    4: ((4, 4), (9, 4)),   # Gui
    5: ((3, 5), (10, 5)),  # Space / Enter -> main big thumb key
}


def convert(layer, base):
    filler = "KC_NO" if base else "KC_TRNS"
    out = [[-1 if (r, c) in MISSING else filler for c in range(COLS)] for r in range(ROWS)]
    for row in range(4):
        for i in range(6):
            out[i][row] = layer[row][i]
            out[13 - i][row] = layer[row + 5][i]
    for i, (left, right) in THUMBS.items():
        out[left[0]][left[1]] = layer[4][i]
        out[right[0]][right[1]] = layer[9][i]
    return out


def main():
    data = json.loads(SRC.read_text())
    data["uid"] = ERGODOX_UID
    data["layout"] = [convert(layer, n == 0) for n, layer in enumerate(data["layout"])]
    data["encoder_layout"] = [[] for _ in data["layout"]]
    DST.write_text(json.dumps(data))
    print(f"wrote {DST.relative_to(REPO)}")


if __name__ == "__main__":
    main()
