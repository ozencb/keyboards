# Keyboard

Everything keyboard related: Fusion 360 sources (`.f3d`) with print-ready exports, firmware, datasheets.

## Layout

- `boards/<board>/`: one folder per keyboard (case variants, jigs, `firmware/`). New keyboard → new `boards/<name>/`.
- `shared/`: parts reused across boards (`keycaps/`, `datasheets/`, `tools/`).
- Folder names kebab-case. Binaries (`.f3d`, `.stl`, `.3mf`, images, PDFs) go through Git LFS (`.gitattributes`); `.uf2` builds are gitignored.

## Rules

- Always edit the design's cloud document directly (open it from the cloud, not by importing the local `.f3d`), and save a new cloud version after changes.
- Then export the source back to its local `.f3d` file (overwrite the one in the part's folder), so local and cloud copies match.
- After saving, re-export every affected body as both STL and 3MF so exports never lag the source.
- Scripts and tools go in `shared/tools/`. Adding, changing or removing one means updating `shared/tools/README.md` (purpose, usage, caveats) in the same commit.

## Export conventions

- One file per body/variant, named after the body: `<folder>/STL/<body>.stl` and `<folder>/3MF/<body>.3mf`.
- Binary STL, mesh refinement High, units mm.
- Case (`boards/sofle-v2-handwired-wired/case/`, cloud doc *Sofle V2 Remix Uni*): export in print orientation (see its `README.md`): Top as modeled (open side down), Bottom and WristRest as modeled but moved up to rest on Z=0, Stand rotated so its desk face is down. Skip `REF_*` bodies.
- Wireless case (`boards/sofle-v2-handwired-wireless/case/`, cloud doc *Sofle V2 Remix Wireless*): same orientation rules as the wired case; see its `README.md`.
- Keycaps (`shared/keycaps/`): export each root body as modeled.

## Commit messages

Conventional Commits: `<type>(<scope>): <summary>`. Summary is lowercase, imperative, no trailing period, ≤72 chars.

- Scope: the board or shared folder name, optionally with `/<part>`: `sofle-v2-handwired-wired/case`, `sofle-v2-handwired-wireless`, `keycaps/xda`, `datasheets`. Use `repo` for repo-wide changes (layout, LFS, ignores, AGENTS.md).
- Types:
  - `feat`: new part, body, variant, keymap or firmware feature
  - `fix`: fit, dimension or firmware bug fix
  - `refactor`: restructure with no physical or behavior change (rename bodies, move files)
  - `docs`: README, BOM, notes only
  - `chore`: tooling, config, or export-only refresh with no source change
- Source and its STL/3MF exports go in the same commit.
- For CAD changes, put the Fusion cloud doc name and version in the body when known, e.g. `Fusion: Sofle V2 Remix Uni v42`.
- A change that spans boards (e.g. a Stand edit copied into both cases) takes the scope of the board where the source changed, and the body lists the others.
- Example: `fix(sofle-v2-handwired-wireless/case): widen usb-c cutout by 0.4 mm`
