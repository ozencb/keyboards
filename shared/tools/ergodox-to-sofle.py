#!/usr/bin/env python3
"""Copy the ErgoDox EZ Vial layout back onto the wired Sofle one.

Inverse of sofle-to-ergodox.py. Usage: python3 shared/tools/ergodox-to-sofle.py
"""
import importlib.util
import json
from pathlib import Path

spec = importlib.util.spec_from_file_location("s2e", Path(__file__).with_name("sofle-to-ergodox.py"))
s2e = importlib.util.module_from_spec(spec)
spec.loader.exec_module(s2e)

SRC, DST, REPO = s2e.DST, s2e.SRC, s2e.REPO


def convert(ergo, sofle):
    out = [list(row) for row in sofle]
    for row in range(4):
        for i in range(6):
            out[row][i] = ergo[i][row]
            out[row + 5][i] = ergo[13 - i][row]
    for i, (left, right) in s2e.THUMBS.items():
        out[4][i] = ergo[left[0]][left[1]]
        out[9][i] = ergo[right[0]][right[1]]
    return out


def main():
    ergo = json.loads(SRC.read_text())
    data = json.loads(DST.read_text())
    if len(ergo["layout"]) != len(data["layout"]):
        raise SystemExit("layer count differs")
    data["layout"] = [convert(e, s) for e, s in zip(ergo["layout"], data["layout"])]
    DST.write_text(json.dumps(data))
    print(f"wrote {DST.relative_to(REPO)}")


if __name__ == "__main__":
    main()
