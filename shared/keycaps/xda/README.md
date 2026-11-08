# XDA Keycaps

XDA-style keycaps with a **flat top** (no spherical dish), uniform height, and an MX stem.

The stem's outer cylinder is Ø5.5 mm (MX standard; it was Ø6.0, which could rub in the switch). It has a 0.3 mm chamfer on the bottom outer edge to absorb elephant's foot.

## Files

| File | Description |
|---|---|
| `XDA Keycap blank` (`.stl`, `.3mf`) | 1U blank. 18 × 18 mm base, 9.1 mm tall, ~12 × 12 mm flat top. |
| `XDA Keycap 1.5U blank` (`.stl`, `.3mf`) | 1.5U blank. 27.5 × 18 mm base, 9.1 mm tall. |
| `XDA Keycap bar` (`.stl`, `.3mf`) | 1U homing key with a raised bar, 0.5 mm above the top. |
| `XDA Keycap dot` (`.stl`, `.3mf`) | 1U homing key with a raised dot, 0.6 mm above the top. |
| `XDA Keycaps.f3d` | Fusion 360 source. |

Exported as modeled: top up, centered on Z = 0. The slicer drops them onto the bed.

## Printing (OrcaSlicer, PLA)

The goal is the smoothest, most injection-molded-looking finish.

### Filament

- Use **matte PLA**. It hides layer lines and looks like molded PBT/ABS. Silk and glossy PLA show every flaw.
- Run Orca's **Flow rate** and **Pressure Advance** calibrations for this filament and nozzle first.

### Orientation

- **Upright with ironing** works for all four caps.
- **Face-down on textured PEI** works for the blanks only. The top sits on the bed and comes out with a matte grain close to molded PBT, with no supports needed.
  - On smooth PEI or glass, the top comes out semi-gloss instead.
  - Face-down, the rounded top edge prints as a near-flat overhang in the first layers, so it may droop slightly.
  - Elephant foot compensation matters more here, because that edge is the visible one.
  - `bar` and `dot` can't print face-down, because their bumps would be on the bed.
- Print 4–8 caps at once. A single cap overheats.
- Try one blank each way and compare them.

### Settings

| Setting | 0.4 nozzle | 0.2 nozzle |
|---|---|---|
| Layer height | 0.08–0.12 | 0.06–0.08 |
| First layer | 0.2 | 0.1–0.12, line width ~0.25 |
| Line width | default | 0.22 |
| Walls | 3–4 | 5–6 |
| Top shells | 6+ | 10–12 |
| Max volumetric speed | filament default | ~2–3 mm³/s |
| Retraction | tuned | ~20–30% shorter |
| Support top Z distance | 0.2 | 0.1 |

For the 0.2 nozzle, pick its printer profile in Orca first, so the defaults reset. Recalibrate Pressure Advance, since it changes a lot with nozzle size.

These settings are the same for both nozzles:
- **Walls**: wall order inner/outer/inner, Precise wall on.
- **Seam**: Scarf joint on, placed at the rear (back face of the cap).
- **Top surface pattern**: Monotonic line.
- **Ironing**: type "Topmost surface", flow 10–15%, spacing 0.1 mm, 30 mm/s. Only matters when printing upright. On `bar` and `dot`, it irons the flat area only.
- **Speed**: outer wall 30–40 mm/s, top surface 30 mm/s. Acceleration ~1000–1500 on the outer wall, ~1000 on the top surface.
- **Travel**: avoid crossing walls on, wipe on.
- **Cooling**: fan 100%.
- **Temperature**: 200–205 °C, the low end.
- **Elephant foot compensation**: 0.1–0.15.
- **Supports**: none at first, because the inside of the top usually bridges. If it sags, use tree supports touching the build plate only.

### 0.2 nozzle and matte PLA

The chalk-like fillers in matte PLA are the main cause of clogs in a 0.2 nozzle. If you get clogs or under-extrusion:
- Print 5–10 °C hotter (205–215 °C).
- Run a cold pull now and then.
- Or switch to regular PLA and give it a matte finish afterward.

Expect print times 3–4× longer than with the 0.4 nozzle.

### Post-processing

FDM won't fully match a molded part. To close the gap, wet-sand 400 → 800 → 1500, then apply a matte clear coat, or filler primer and paint. A resin printer gets close without sanding.
