# Sofle v2 Handwired Case — Wireless variant (nRF52840 + ZMK)

Wireless (BLE split) version of the handwired Sofle v2, derived from `../../sofle-v2-handwired-wired/case/`, itself a remix of the [Sofle v2 keyboard case](https://www.printables.com/model/614157-sofle-v2-keyboard-case) on Printables. Only the electronics bay (the strip beside the keys) changed; outline, plate, wrist-rest magnets, screws and stand are as in the wired case. Fusion cloud doc: *Sofle V2 Remix Wireless* (copied from *Sofle V2 Remix Uni* on 2026-11-08).

## Files

| File | Description |
|---|---|
| `Top_L` / `Top_R` (`.stl`, `.3mf`) | Frame + plate with the new bay. Exported as modeled: open side down, bezel up. |
| `Bottom_L` / `Bottom_R` (`.stl`, `.3mf`) | Bottom plate with XIAO pads and battery fences. Exported outer face down. |
| `Stand_*`, `WristRest_*` | Unchanged; copies of the `../../sofle-v2-handwired-wired/case/` exports. |
| `Sofle V2 Remix Wireless.f3d` | Fusion source. Hidden fit-check bodies: `REF_XIAO_*`, `REF_Battery_*`, `REF_Switch_*`, `REF_Rod_*`. |

## Electronics bay

Coordinates are left-half model coordinates (mm): X toward the inner (right-half) side, Y toward the back wall, z = 0 near the plate, case bottom z −14.46, floor top z −11.46, strip cover underside z 4.3, bezel top z 8.73. The right half mirrors about X = 105 except where noted.

Timeline (all at the end): `WirelessBayTools` (base feature with every tool and REF body), then per half `WL_TopCleanup`, `WL_TopJoin`, `WL_TopCuts`, `WL_BotCleanup`, `WL_BotJoin`, and `WL_Remove_REF_Pico` / `WL_Remove_REF_RJ9_DS1132`.

1. **Removed**: the Pico corner legs, the Pico hold-down leg, the RJ9 jack walls (frame), and the Pico pads and RJ9 cradle stubs (bottom plate). Cut boxes stay inside the bay and don't touch the walls, strip wall or cover.
2. **RJ9 opening and pocket filled** flush with the inner side wall (outer face X 72.76), from the floor to the cover.
3. **XIAO nRF52840**: components up, USB-C toward the back wall, centered on the existing USB-C opening (12.6 × 7.4 mm, X 52.6–65.2, z −10.96 to −3.56), which is reused unchanged.
   - Board X 50.14–67.92, Y 27.95–48.90, underside z −9.86 (same as the Pico). Board edge is 2 mm short of the back wall; the USB-C shell front sits about 1 mm inside the wall.
   - Held by 4 corner legs hanging from the cover, touching the board top only in the corner areas outside the castellated pads, RGB/charge LEDs and reset button. Lips 1 mm deep around each corner (0.1 mm clearance) locate the board in X and Y.
   - Two pads on the bottom plate (5.5 × 2.4 mm at the far end, 4.5 × 6 mm in the middle) push the board up against the legs. They avoid the BAT/GND pads, the NFC pads, the test points and the USB-C shell tabs. They are **not mirrored** on the right half, because the XIAO is the same way up on both halves.
   - Legs assume a **1.6 mm** PCB (Seeed's KiCad stack-up). A thinner board leaves a gap: put foam or double-sided tape on the bottom pads.
4. **Light pipe** (Ø3 mm acrylic rod) over the onboard RGB LED: Ø3.2 mm bore through the strip cover at X 65.23, Y 46.10, with a sleeve (Ø5.2 mm OD) hanging down to z −4.5 to keep light from leaking into the case. The rod runs from the bezel top (z 8.73) to 0.5 mm above the LED: **cut it to ~15.9 mm**. Right half: X 157.17 (not mirrored, same LED position on the board).
5. **Power switch** on the back wall, above the USB-C opening:
   - Pocket for an SS12D00 body (8.5 × 3.5 × 3.5 mm, plus 0.1 mm per side) against the inside of the back wall, z −2.6 to 1.1, open toward the bay (−Y) for the pins. A floor under the pocket carries the switch.
   - Lever slot through the wall: 6.0 × 2.6 mm, centered at z −0.75. The wall is 2.14 mm, so a 5 mm lever sticks out ~3 mm.
   - Left switch centered at X 57.5; right at X 150.25 (not mirrored, to clear the right-half light pipe).
   - Body size is typical SS12D00, not measured: check against the real part and widen the pocket if needed.
6. **Battery** (20 × 30 × 4 mm LiPo) lies on the floor in the old RJ9 area and in front of the XIAO: X 49.95–69.95, Y −4.2 to 25.8. Low fences (2 mm tall) on the bottom plate at the front, back and keys side; the thinned side wall is the fourth side. Stick it down with double-sided tape.

## Assembly

1. With the frame open side up, slide the power switch into its pocket from the bay side, lever into the wall slot. Glue the body in place.
2. Push the light-pipe rod down through the bezel bore until it's flush on top; glue from inside if loose.
3. Solder the matrix wires to the XIAO edge pads and the battery leads (through the switch) to the BAT+/BAT− pads on its underside.
4. Drop the XIAO into the 4 corner legs, components facing down (toward the cover), USB-C toward the back-wall opening.
5. Tape the battery onto the bottom plate between its fences, then close the case. The bottom pads clamp the board against the legs.

## Printing

Same as `../../sofle-v2-handwired-wired/case/`. The new legs, sleeve and switch bracket hang from the cover, so the Top needs supports there too (they touch only hidden faces).

## Decisions

| Area | Decision | Status |
|---|---|---|
| Controller | Seeed XIAO nRF52840 (plain, not Sense): genuine, local stock, onboard RGB LED and reset button, 21×17.5 mm. All 11 edge GPIO (D0–D10) go to the matrix; battery, charging and LED use dedicated pads/internal pins. NFC pads P0.09/P0.10 are the only spares | Fixed |
| Firmware | ZMK (no BLE in QMK/Vial); ZMK Studio for live remapping | Proposed |
| Split link | BLE between halves; RJ9 jack and cable dropped | Proposed |
| Key switches | TTC Silent Bluish White (MX-style, plate mount, 14 mm cutout), replacing the wired build's Outemu Lemon v3 | Fixed |
| Matrix | Unchanged: 5 rows × 6 cols per half, `COL2ROW`; 11 GPIO per half | Fixed |
| Battery | Single-cell LiPo with protection board, charged by the controller's onboard charger | Proposed |
| Power switch | SS12D00G5 mini slide switch (SPDT, through-hole, 5 mm lever), in series with B+ (battery charges only while on) | Fixed |
| Status LED | XIAO onboard RGB LED via `zmk-rgbled-widget` (BT profile/connection, battery on boot), shown through a Ø3 mm clear acrylic rod light pipe | Fixed |

## Parts list (per keyboard, wireless additions)

Other matrix parts (diodes, wire, inserts, magnets, feet) as in `../../sofle-v2-handwired-wired/case/README.md`. RJ9 jacks and cable not needed. Prices from Trendyol, 2026-11-07.

| Qty | Part | Notes | Link |
|---|---|---|---|
| 58 | TTC Silent Bluish White switches | 29 per half | |
| 2 | Seeed XIAO nRF52840 (not Sense) | ~1,094 TL on Trendyol; ~772 TL at Robotistan | [Trendyol](https://www.trendyol.com/seeedstudio/seeed-studio-xiao-nrf52840-bluetooth-5-0-gelistirme-karti-p-655340118), [Robotistan](https://www.robotistan.com/seeed-studio-xiao-nrf52840-bluetooth-50-development-board) |
| 2 | LiPo 3.7 V 250 mAh, 20×30×4 mm | Thinnest 250 mAh found. ~700 TL | [Trendyol](https://www.trendyol.com/bns/20x30mm-lipo-pil-20x30-lipo-pil-4mm-kalinlik-20mmx30mm-3-7v-250mah-lipo-pil-3-7v-lipo-pil-p-1136469564) |
| | Alt: LiPo 3.7 V 300 mAh, 25×30×4 mm (402530) | ~610 TL | [Trendyol](https://www.trendyol.com/bns/25x30mm-lipo-pil-30x25mm-lipo-pil-402530-lipo-pil-4mm-kalinlik-402530-3-7v-300mah-lipo-pil-yalova-bensu-elektronik-p-1201635785) |
| | Alt: LiPo 3.7 V 150 mAh, 402025 | Smallest; ~245 TL | [Trendyol](https://www.trendyol.com/efcell/lipo-402025p-3-7v-150mah-polimer-batarya-saat-ve-kulaklik-pili-p-331776265) |
| | Alt: LiPo 3.7 V 250 mAh, 502030 (5 mm) | Cheapest 250 mAh but 5 mm thick; ~350 TL | [Trendyol](https://www.trendyol.com/sertec/lipo-polimer-502030-3-7v-250mah-lityum-polimer-pil-p-681708228) |
| 2 | SS12D00G5 mini slide switch (SPDT, through-hole, 5 mm lever) | Power switch in series with B+. ~152 TL each | [Trendyol](https://www.trendyol.com/labshop41/ss12d00g5-mini-swich-anahtar-5mm-x-1-adet-rf020-p-743659759) |
| 1 | Acrylic round rod, clear, Ø3 mm × 70 cm | Light pipe stock; cut ~15–18 mm pieces, polish LED end, frost visible end | [Trendyol](https://www.trendyol.com/ipeksi-pleksi/akrilik-yuvarlak-cubuk-seffaf-3-mm-70-cm-p-747240345?boutiqueId=61&merchantId=787834&filterOverPriceListings=false&sav=true) |

## Open questions

- Not test-printed yet. Check the XIAO PCB thickness, switch body size, lever slot and rod length against the real parts.
