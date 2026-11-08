# Sofle v2 Handwired Case — Unibody variant (RP2040 Pico + RJ9)

The frame and switch plate are one solid (`Top_L` / `Top_R`) for a stiffer case, with the plate's support legs kept. The board and RJ9 jack mount in the frame; the bottom plate only supports them from below. Fusion cloud doc: *Sofle V2 Remix Uni*.

A remix of the PCB-based Sofle v2 3D-printed case ([Printables 614157](https://www.printables.com/model/614157-sofle-v2-keyboard-case)) for a **handwired** build: no PCB, no OLED, no rotary encoders, a Raspberry Pi Pico-format controller per half, and an RJ9 (4P4C) link between halves. Adds anti-flex legs under the plate, magnet pockets for a detachable wrist rest, and M3 hardware instead of M2.

## Files

| File | Description |
|---|---|
| `Top_L` / `Top_R` (`.stl`, `.3mf`) | Frame + switch plate (with support legs) as one body. Exported **as modeled**: open side down, bezel up. See *Unibody* below. |
| `Bottom_L` / `Bottom_R` (`.stl`, `.3mf`) | Bottom plate with support pads for the board and RJ9 jack. Exported outer face down. |
| `Stand_L` / `Stand_R` (`.stl`, `.3mf`) | Tenting stand (5°, parametric). A nest pocket holds the case and wrist rest together, so neither can slip. Exported desk face down. See *Tenting stand* below. |
| `Sofle V2 Remix.f3d` | Fusion 360 source, with the full timeline. Also contains reference bodies `REF_Pico` (board, USB-C and component envelope, no headers) and `REF_RJ9_DS1132` used for fit checks. |

The right half is an exact mirror of the left. Each `.3mf` contains the same mesh as its `.stl`, in millimetres and in the same print orientation.

## Parts list (per keyboard)

| Qty | Part | Notes |
|---|---|---|
| 58 | Outemu Lemon v3 silent switches | MX-style, plate mount (14 mm cutout); 29 per half |
| 2 | VCC-GND YD-RP2040 (Pico pinout, USB-C, 16 MB) | 53.34 × 22.86 mm, no mounting holes; the frame legs and bottom pads are built around it |
| 2 | CONNFLY DS1132-01 4P4C (RJ9) PCB jack | 11.18 W × 11.65 H × 18 D mm, right angle; [datasheet](https://en.connfly.com/list_112/1001.html) |
| 1 | 4P4C / RJ9 cable (handset type) | Plug must fit an 8.8 × 10.6 mm opening |
| 10 | M3 heat-set inserts | 5 per half; hole is Ø4.0 × 6 mm deep, so standard M3 inserts (OD ≈ 4.5, L ≤ 5.7) fit |
| 10 | M3 screws, 6–10 mm | 5 per half, bottom plate to frame. Button head sits flush; socket cap protrudes ~1.2 mm |
| 6+ | 6 × 1 mm neodymium magnets | 3 pockets per half; each pocket takes a stack of up to ~7. Match polarity with the wrist rest |
| 58 | Diodes (1N4148 or similar) | Handwired matrix |
| — | Wire, rubber feet (4 per half, Ø6 recesses exist) | |

The male/female precision headers and the 180° 4P4C jack were **not used**. Wires solder straight to the Pico pads, and the DS1132-01 is the jack the case is designed around.

## Unibody

- Timeline features at the end: `UniGapFillTools` (base feature) holds `UniFill_L/R`, which fill the ~0.25 mm plate-to-frame side gap (0.5 mm at the strip wall) over the full plate thickness (z −2.46 to 1.04). `JoinUni_L/R` combine frame + plate + fill into `Top_L/R`.
- The fill was computed as (slab over the plate thickness − frame − plate) ∩ (plate dilated 0.6 mm), keeping only the ring around the plate. It is a static base feature: if the frame or plate changes upstream, regenerate it.
- `UniLegFillTools` / `JoinLegFill_L/R` fill the 5 frame notches around the wall-side legs (the old PCB-standoff clearance grooves, ~0.8 mm gap around each Ø4.8 leg) from the leg foot (z −11.46) to the plate. Each leg becomes a flat pilaster flush with the inner wall (up to 0.4 mm proud where the wall isn't straight). Below z −11.46 the bottom plate already fills the notch. The 6th standoff leg (X 53, Y −34.8) stands free and the 5 middle legs are unchanged.
- The frame ledge sat 0.1 mm above the plate top (z 1.14 vs 1.04), leaving a slit visible at the ledge edge in the thumb area and around the 5 bezel-tab M2 holes. `PlateSeamFillTools` / `JoinPlateSeamFill_L/R` (last features) close it: the fill is (slab z 1.035–1.145 over the slit regions) ∩ (body shifted down) ∩ (body shifted up), dilated 0.03 mm in XY to avoid coincident faces, so a 0.03 × 0.1 mm bead remains in the plate/ledge corner. The same tool fills the 5 M2 holes (Ø3.2, z 1.04–7.84), which became sealed voids once the slit closed. Static base feature: regenerate if the frame or plate changes upstream.
- Switches clip in from the top, so wiring is done with the plate already in the case.

## Changes vs. the original Sofle v2 case

Coordinates below are for the left half in the Fusion model: z = 0 is near the plate, and the case bottom is at z = −14.46 mm.

### Frame (top case)
1. **Closed the OLED window and encoder hole.** Both are filled flush with the bezel top, including the original chamfers.
2. **Closed the TRRS hole** on the inner side wall, flush, including its countersink.
3. **Closed the old micro-USB slot** in the top wall.
4. **Case is 3 mm taller** for handwiring.
   - The lower part of the walls is stretched; total height is now 23.19 mm (was 20.3). The bezel top was shaved 0.11 mm (`TopShave`, last timeline feature) to remove sliver faces where the OLED-window fill sat 0.003 mm below the bezel. `EncoderSlitFill`/`EncoderPitFill` then close a hairline crescent slit (~1.6 mm³) left between the round encoder-hole fill and the faceted original hole wall.
   - Plate top to bottom-plate inner face is now **12.5 mm**, leaving room for switch pins (≈8.3 mm below the plate top), diodes and wires.
5. **New USB-C opening** in the top wall: 12.6 × 7.4 mm with r2.5 corners, centered on the Pico's USB-C port. It accepts cable overmolds up to ~12 × 6.5 mm.
6. **New RJ9 opening** in the inner side wall, where the encoder used to be: 8.8 × 10.6 mm, r1, matching the jack face.
   - Behind it, a 1.65 mm deep pocket the size of the jack body (+0.15 mm/side) lets the jack's front sit inside the wall; the wall in front of the jack is 1.8 mm. The pocket is open at the bottom, so the jack drops in from the open side of the frame (see item 15).
7. **Magnet pockets**: 3 × Ø6.3 mm bores in the front (wrist-side) wall.
   - The bores are drilled 7.5 mm deep from the inside and leave a 0.6 mm skin on the outside, so the magnets are hidden.
   - They sit on the front wall's straight section at model X = −16, −2.5 and +16 mm, 7.6 mm above the case bottom. The −2.5 position keeps clear of the screw boss at X = 5.3.
8. **M3 inserts for the bottom-plate screws.**
   - The 5 wall bosses are thickened to r3.6 (they were ~r2.2, too thin for M3).
   - Insert holes are Ø4.0 × 6 mm, with a Ø3.2 screw relief above.
9. **Small notch** in the corner block at the top of the strip, so the Pico can sit flush against the top wall.
10. **Closed the slot along the strip.** The original strip cover stopped 3.3 mm above the plate, leaving a see-through slot along the edge of the keys, where the OLED and Pro Micro used to sit.
    - A 1.6 mm wall now hangs from the cover down to the plate's bottom face (x 48.02–49.62, z −2.46 to 4.3).
    - Its face is flush with the strip's inner face, leaving the same 0.5 mm gap to the plate edge as the original case.
    - The original r1.0 corner fillet where the strip meets the top wall continues down the full height of the new wall.
    - Wires still pass under the plate into the strip.
11. **Pico hold-down leg**: a 6 × 4 mm leg hangs from the strip cover onto the board's USB-C shell, ending 0.5 mm above it. Stick ~1 mm foam tape on the leg tip (or shell) to take up the gap.
12. **Thinned the strip's outer (RJ9-side) wall** alongside the board, from 3.4 to 2.0 mm, from the bottom plate up to z −5. This lets the board sit 1.4 mm further toward that wall. The USB-C opening and the hold-down leg moved with the board. The board's edge is 0.3 mm from this wall.
13. The 6 small M2 insert holes in the bezel tabs above the plate are **unused** (5 of them are filled; see *Unibody*). They have only ~0.65 mm of wall and can't take M3 inserts, and they aren't needed because the legs clamp the plate.
14. **Board legs** (`BoardMountTools` / `JoinPicoLegs_L/R`): the board sits in the frame, buttons and USB-C facing the keys, on 4 corner legs that touch the board top (z −8.86) only outside the corner pin pads (≥ 0.4 mm clear of the pad rings).
    - USB end, keys side: hangs from the corner block. A 0.45 mm lip down the board's side edge locates it.
    - USB end, RJ9 side: block on the side/top wall corner.
    - Far end, keys side: hangs from the strip wall (item 10), with lips on the board's side and end edges.
    - Far end, RJ9 side: rib on the side wall, with a lip on the board's end edge.
    - Lips reach 1.0 mm below the board top. The top wall, the RJ9-side wall and the lips hold the board with ~0.15–0.3 mm play per side. No leg comes near the BOOT, USR or RESET buttons.
15. **RJ9 cradle walls** (`JoinJackWalls_L/R`), moved up from the bottom plate: two 1.6 mm side walls and a back stop hang from the strip cover (z 4.3) down to z −7.5, with the same footprint, clearances and 6 mm wire slot as before. The jack's position and orientation are unchanged; it drops into the frame and rests against the cover underside.

### Switch plate
1. **Rebuilt as a clean solid** from slices of the original STL, because the original mesh wasn't watertight.
   - Same outline and 29 switch cutouts: a 1.4 mm clip layer with 14 mm holes, then a 14.5 mm relief, 3.5 mm thick in total.
2. **Snugger fit**: the outline is enlarged by 0.25 mm per side. The plate-to-frame side gap is now ~0.25 mm, down from the original 0.5 mm, which left up to 1 mm of play in a test print.
3. **Removed** the 4 PCB-spacer nubs per switch and the 6 M2 PCB-standoff holes.
4. **Added 11 support legs**, 9.0 mm long, standing on the bottom plate.
   - 6 × Ø4.8 mm at the old PCB-standoff positions (the frame already has clearance notches there).
   - 5 × Ø5.0 mm in the middle of the plate, where flex is worst.
   - All legs sit in the gaps where switches meet, clear of the switch bodies and pin rows, so row and column wires can still run straight.
5. When the bottom plate is screwed on, the legs clamp the plate against the frame's top ledge, which removes flex.

### Bottom plate
1. **Flipped**, so the screw counterbores and rubber-foot recesses face outward. The original STL is meant to be flipped for one of the two halves.
2. **M3 holes**: Ø3.4 through, with a Ø6.2 × 1.8 mm counterbore.
3. **Filled** the old reset-button access hole, which is now under the Pico.
   - **Flat floor**: the converted mesh's floor sat at two heights 0.00004 mm apart (split at X≈8). That made slicers add a full layer to one half when a layer cut fell exactly on the floor. `FloorFlat_L` / `JoinFloorFlat_L` raise the whole floor to one plane at z −11.4599 (0.0001 mm up). `Bottom_R` is now `MirrorBottom_R`, a mirror of `Bottom_L` made at the end of the timeline; the old `Bottom_R` is removed (`RemoveOldBottom_R`), because joining a slab to it failed.
4. **Board supports**: three pads, all ending at the board's underside (z −9.86, 1.6 mm above the floor), press the board up against the frame legs (Frame 14). They sit between the pin rows, clear of the solder joints.
   - 6 × 2.4 mm under the USB-C connector, between its through-hole tabs.
   - 10 × 2 mm across the middle of the board.
   - 8 × 1.2 mm under the far end, in front of the SWD pads.
   - `CutOldCradles_L/R` removed the old back stop lip and the keys-side posts, which would block the bottom plate from closing over a board held in the frame.
   - Floor channels, 2.6 mm wide and 0.8 mm deep, remain under both pin rows and across the far end. They're no longer needed (no headers) but give solder joints extra room.
5. **RJ9 supports** for the DS1132-01: the old cradle is cut down to the jack's underside (z −7.7). Its walls moved to the frame (Frame 15).
   - Two support ribs avoid the jack's pins and plastic posts, and touch the jack's underside.
   - A 1.5 mm recess under the pins leaves space to solder wires.
   - The stubs of the old back stop and side walls remain below the jack, 0.2 mm under the frame walls. The 6 mm wire slot and the channel behind it (4.5 mm long, 1.5 mm deep) still guide the pin wires out backward.

## Printing

- **Top** (unibody): print as exported, open side down, bezel up. **Needs supports** under the plate (12 mm above the bed; the legs end 3 mm above it) and under the strip cover over the Pico, including the board legs and RJ9 walls hanging from it. Supports touch only hidden faces; the plate top and bezel print as top surfaces. Use tree supports and block them inside the switch holes if the slicer adds them there.
- **Bottom**: print outer face down, as exported. No supports.
- **Stand**: print desk face down, as exported. No supports. Solid body (~249 cm³ at 5°), so let the slicer hollow it (3 walls, 10–15% infill).
- All STLs are watertight. The parts don't overlap each other or the reference Pico/RJ9 bodies.

## Tenting stand

- Each half's case and wrist rest drop into one pocket (nest) on top of a wedge. The pocket wall holds their outer edges, so neither can slide downhill or apart. Nothing is changed on the case or wrist rest, and they lift straight out.
- The tilt is a pure roll about the outer edge. The inner edge (RJ9 side) rises; the stand is 19.7 mm tall there at 5°, and 5.0 mm at the outer edge.
- The rubber feet stay on. The case and wrist rest bottoms sit directly on the pocket floor. Each foot drops into a Ø`FootHoleD` through-hole, which also helps hold the part in place. The floor under the outer feet is only ~3 mm thick, so the holes go all the way through.
- The pocket outline is the frame and wrist-rest section at 2.4 mm above the case bottom. The faceted frame section was simplified to 75 segments (≤ 0.03 mm deviation), then offset in the sketch.
- User parameters, which drive the whole stand:

| Parameter | Default | Meaning |
|---|---|---|
| `TentAngle` | 5° | Tent angle |
| `NestClearance` | 0.4 mm | Gap from case/wrist rest to pocket wall |
| `NestWall` | 3 mm | Pocket wall thickness |
| `NestWallH` | 3 mm | Wall height above case bottom. The RJ9 opening starts 7.3 mm up, so keep this below ~7 mm. |
| `FootHoleD` | 7 mm | Through-hole diameter for each of the 8 rubber feet (Ø6 recesses) |
| `StandMinT` | 2 mm | Stand thickness at the low (outer) edge |

- After changing a parameter, re-export `Stand_L` and `Stand_R`. `Stand_R` is a mirror feature of `Stand_L`.

## Assembly notes

1. Heat-set the 5 M3 inserts into the frame bosses from the bottom.
2. Push the magnets to the far end of each front-wall bore and glue them. Check polarity against the wrist rest first.
3. Clip the switches into the plate and handwire the matrix. Pins point down toward the bottom plate.
4. With the frame open side up, pre-solder wires to the RJ9 jack pins and drop the jack between its frame walls, opening into the side-wall pocket, pins facing you.
5. Drop the board into its 4 frame legs, components and USB-C facing down (toward the keys), USB-C into the top-wall opening.
6. Close the case with the bottom plate and M3 screws. The bottom pads clamp the board against the legs and support the jack, and the plate is clamped on its legs.

## RJ9 link cable (as built)

A homemade cable made from a cut USB cable with 3 wires: red (thicker), white and green. The braid/shield is cut off flush. Both ends are crimped the same way, so the cable is straight-through (pin 1 to pin 1). The link is QMK half-duplex serial: VCC, GND and one data wire.

Slot order, with the plug held **gold contacts up, cable coming toward you**, from left to right:

| Slot | Wire | Signal | Pico pin (both halves) |
|---|---|---|---|
| 1 | Red | VCC | Vout (pin 40) |
| 2 | Red | VCC | Vout (pin 40) |
| 3 | White | GND | GND |
| 4 | Green | DATA | GP1 (split serial, same pin on both halves) |

- **This is not the planned order.** The plan was red, white, green, empty; the cable was crimped one slot over by mistake. It works because the jacks are wired to match it.
- **The thick red wire takes two slots.** It's crimped across contacts 1 and 2, so both carry VCC. At each jack, wire the pads for contacts 1 and 2 to Vout. One wire is enough, but the two pads must not go to anything else.
- **Use Vout, not Vin.** On the YD-RP2040, USB VBUS and Vin (pin 39) each feed Vout through a diode, so Vout is the equivalent of a Pico's VSYS. Vin can't carry power out, so a Vin link leaves the other half dead.
- **Wire both jacks the same way.** Don't mirror the right half: it's the same jack part on both sides.
- **The jack's pad numbering may not match the plug's slot order.** Find each pad by plugging in the cable and beeping each wire to the jack pads.
- **A new or replacement cable must use the same order**, or a ready-made cord must be checked with the meter first. Many store-bought handset cords are reversed (pin 1 to pin 4); with this pinout, that puts GND on Vout and Vout on GP1.
- Never plug or unplug the RJ9 while USB is connected. Only connect USB to one half.

## Check before printing

- **Board**: the frame legs fit a YD-RP2040 (53.34 × 22.86 mm per the [VCC-GND drawing](https://github.com/initdc/YD-RP2040)), with ~0.45 mm side play and ~0.36 mm lengthwise play. If yours measures 23 × 53.5, that's still within play. The board is assumed 1.0 mm thick and clamped with zero gap between legs and pads; a thicker board just flexes the bottom plate slightly. The middle and far-end pads assume a bare board underside (no components there).
- **Corner pins**: the legs leave ≥ 0.4 mm around the pad rings of pins 1, 20, 21 and 40. Keep those solder joints small and run their wires away from the corners.
- **RJ9 posts**: the jack's post and pin positions under the body come from the datasheet drawing (posts ≈10 mm from the back face, pins near the back). Check them against your actual jack.
- **Magnets**: 6 × 1 mm magnets are weak. Stack 2–3 per pocket for a firmer wrist-rest hold.

## How the model was made (technical)

- The original STLs were converted to solid bodies in Fusion with faceted conversion. Prismatic conversion needs the paid Design Extension. As a result, the frame and bottom are made of thousands of small flat faces. The geometry is accurate, but Fusion draws every triangle edge.
- STL orientation in the original files:
  - `top-left.stl` is the frame printed upside down; it was rotated 180° about Y.
  - `plate.stl` and `bottom.stl` are meant to be flipped for one half. For the left half they were mirrored in Z.
- The 3 mm height increase was applied to the frame mesh before conversion, by shifting every vertex below z = −7.5 mm down 3 mm. Doing it as a split-and-join in Fusion failed on the faceted body.
- All other changes are Fusion timeline features: base-feature tool bodies combined (join/cut) with the frame, plate and bottom, followed by a mirror for the right half.
- The original rotary-encoder knob STLs (`knob.stl`, `knob_tall.stl`) are not used.
