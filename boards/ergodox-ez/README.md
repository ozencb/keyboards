# ErgoDox EZ

Store-bought ZSA ErgoDox EZ, v3 batch 3a. No CAD here, keymaps only.

| Folder | Contents |
|---|---|
| `firmware/oryx/` | Last Oryx layout (pNENG/or7XKD): source, `.hex` (rollback), and README with the Oryx link. |
| `firmware/vial/` | Vial keymap (Oryx layout ported; reset default). Symlinked into `~/vial-qmk/keyboards/ergodox_ez/base/keymaps/ozenc`. |
| `firmware/build/` | Local builds (gitignored). |

Base model (PID `0x4974`, ATmega32U4, HalfKay). Flashed with Vial on 2026-11-08.

Build and flash:

```bash
cd ~/vial-qmk && PATH=/opt/homebrew/opt/avr-gcc@8/bin:/opt/homebrew/opt/avr-binutils/bin:$PATH make ergodox_ez/base:ozenc
teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_base_ozenc.hex
```

Bootloader: reset pinhole, or hold `;` + top-right key (`QK_BOOT` on layer 3). Vial unlock: hold left top-left (Esc) + right home-row outer key (`'`).
