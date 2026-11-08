# Sofle v2 Row Wire Bending Jig

A bending jig for the row wires of the handwired Sofle v2 (`../case/`). Press 1 mm bare copper wire into a groove, and it takes the exact row shape, including the column stagger and the angled thumb keys. Lift it out, lay it on the switch pins, and solder.

## Files

| File | Description |
|---|---|
| `WireJig_L` (`.stl`, `.3mf`) | Jig for the left half: 5 grooved ribs (rows 1–4 + thumb row) joined by 3 cross bars. |
| `WireJig_R` (`.stl`, `.3mf`) | Jig for the right half. Not a mirror of `WireJig_L`: the switch layout is mirrored, but the switches still face north, so the pins aren't. The contact pin sits 5.08 mm further along each switch, and the transitions are re-routed to match. |
| `WireJig_FitTest` (`.stl`, `.3mf`) | 46 × 22 × 4 mm strip with 5 test grooves. Print it first. |
| `Sofle Wire Jig.f3d` | Fusion 360 source, with the full timeline. |

All parts are exported in print orientation: flat side on Z = 0, grooves up.

## Geometry

- Ribs are 7 mm wide and 4 mm tall. Cross bars are 6 mm wide.
- An "L" or "R" is engraved 0.6 mm deep on the outer cross bar, between rows 2 and 3.
- Grooves are 1.05 mm wide and 1.0 mm deep, so the wire sits flush with the top.
- Bends are rounded to r2.0 mm so the copper doesn't kink. The radius is smaller where segments are short.
- Every row runs 8 mm past the first and last switch and out the open end of the rib. You can lift the wire from the end, and the extra length is there to trim or to route to the Pico.
- A half-round notch (Ø1.6) beside the groove marks each solder point.
- Each jig is drawn mirrored, as seen from **under** the plate. With the plate face down and the pins up, the bent wire drops onto the pins without flipping.
- Switch positions come from the switch-plate cutouts of `Top_L` in `../case/Sofle V2 Remix.f3d`. The right half is an exact mirror.
- A wire bent on one jig and flipped over gives the mirror shape, which is **not** the other half's wire. Use the jig that matches the half.

### Wire position

- Switches are assumed to be **north-facing**, with the LED window toward the number row. The metal pins are assumed to sit on the side opposite the LED window, as on standard MX switches.
- Looking from the top, with switch center at (0, 0) and +Y toward the number row:
  - The row wire touches the pin at (−2.54, −5.08) on its south side. The wire centerline is at y = −6.08.
  - The other pin, at (+3.81, −2.54), stays ≥ 1 mm clear.
- Stagger transitions are routed around the plate's 11 support legs and every other switch pin, with ≥ 0.3 mm clearance.
- Row 3 has a near-90° jog between columns 2 and 3 to pass a leg (left jig).
- Row 2 on the right jig has a 73° jog between columns 5 and 6. It passes over a leg (0.33 mm clear) and then has to drop before the next switch's other pin.

## Use

1. Print `WireJig_FitTest`. The grooves are 0.95 / 1.0 / 1.05 / 1.1 / 1.15 mm wide, marked by 1–5 dots. Push wire into each one.
   - The right fit needs a firm press and then holds the wire.
   - The jig uses 1.05 mm (3 dots). If a different groove fits best, change the groove sketches in the `.f3d` and re-export.
2. Print `WireJig_L` and `WireJig_R`. PLA is fine, with no supports.
3. Straighten the wire by stretching it slightly, or by rolling it between two flat surfaces.
4. Start at one end and press the wire into the groove along its whole length. Run a fingernail or a flat tool over the bends.
5. Lift the wire out from the open end of the rib and peel it along the groove.
6. Put the plate face down with the switches fitted and the pins up. Lay the wire so it touches the pin marked by each notch, then solder.
7. If you also run the column wires in bare copper, insulate the crossings, or keep the diode legs between the row wire and the columns.

## Check before printing

- **Pin side:** hold one Outemu Lemon v3 with the LED window up, looking from above. Both metal pins should be in the lower half. If they're in the upper half, the switch pins sit 180° from what was assumed, and the jig has to be regenerated.
