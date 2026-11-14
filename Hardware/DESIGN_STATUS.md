# KiCad Rev-A Design Status

Files present:
- `AirDrop.kicad_pro` — native KiCad project container.
- `AirDrop.kicad_sch` — native KiCad system block diagram, not a pin-level electrical schematic.
- `AirDrop.kicad_pcb` — native KiCad placement/net-assignment draft with provisional module footprint and generic connector footprints.

**Not fabrication-ready.** No routed tracks, completed power tree, protection networks, final sensor interfaces, copper zones, verified manufacturer footprints, ERC/DRC reports, or Gerber files are included.

The ESP32-WROOM-32E footprint pad geometry is a provisional engineering drawing and MUST be compared against Espressif's current recommended land pattern source before use. The antenna keep-out is only noted in text; it is not yet implemented as a verified copper/placement keep-out rule.

The board file should be opened in the target KiCad version, then inspected and repaired/updated as needed. Do not order this board for fabrication.
