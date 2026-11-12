# Tools

Scripts shared across boards. Run them from the repo root with `python3`; they need only the standard library.

| Script | What it does |
|---|---|
| `sofle-to-ergodox.py` | Generates `boards/ergodox-ez/firmware/vial.vil` from `boards/sofle-v2-handwired-wired/firmware/vial.vil`. |
| `vil-to-keymap.py` | Rewrites the `keymaps[]` array in a `keymap.c` from a `.vil`, so a firmware or EEPROM reset gives the current layout. |

## sofle-to-ergodox.py

```bash
python3 shared/tools/sofle-to-ergodox.py
```

- Main 4×6 block per half is copied as is, on every layer.
- Sofle thumb row: Space/Enter → main big thumb keys; outer thumb keys → second big thumb keys; Ctrl/Alt/Gui → bottom row, same columns.
- ErgoDox-only keys (inner column, small thumb keys, outer two bottom-row keys) are `KC_NO` on layer 0 and `KC_TRNS` above.
- Sets the ErgoDox Vial UID; everything else (macros, combos, settings) is copied unchanged.
- The ErgoDox build has `QMK_SETTINGS` off, so tap-hold and mouse settings must also be mirrored by hand in `boards/ergodox-ez/firmware/vial/config.h`.

## vil-to-keymap.py

```bash
python3 shared/tools/vil-to-keymap.py <layout.vil> <keymap.c>
```

- Replaces only the `keymaps[]` block; the rest of `keymap.c` is kept.
- Layers are written in raw matrix order, as stored in the `.vil`, so no `LAYOUT` macro is needed.
- Vial's legacy keycode names are translated with `~/vial-qmk/quantum/vial_ensure_keycode.h`, so that checkout must exist.
- Macros, tap dances, combos and QMK settings are not carried over.
- Sofle: the repo `keymaps/vial/` is a copy of `~/vial-qmk/keyboards/sofle_handwired/keymaps/vial/`. Write the `~/vial-qmk` file, then copy it into the repo. ErgoDox: the repo folder is symlinked, so write the repo file directly.

## Typical flow after a layout change

1. In Vial, export the Sofle layout over `boards/sofle-v2-handwired-wired/firmware/vial.vil`.
2. `python3 shared/tools/sofle-to-ergodox.py`
3. Run `vil-to-keymap.py` for both boards (see above).
4. Load `boards/ergodox-ez/firmware/vial.vil` on the ErgoDox in Vial.
