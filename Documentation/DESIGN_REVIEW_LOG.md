# Design Review Log — Rev-A

## Selected
- Single integrated controller/interface PCB.
- ESP32-WROOM-32E module, not bare SoC.
- All sensor categories included.
- I2C shared bus planned for BME680, MPU6050 and indoor airflow sensor.
- Outdoor anemometer pulse input.
- Three leak-probe inputs.
- Two ultrasonic distance channels with provisional echo dividers.

## Added to the placement draft
- ESP32 module pad/net assignments for selected GPIOs.
- Sensor and field connector footprints.
- Two provisional 10k/20k ultrasonic echo divider pairs.
- Three 10k leak input pull-ups.
- One 10k wind pulse pull-up.
- Four-layer copper layer definitions.
- Native KiCad project, schematic block diagram and PCB placement file.

## Critical review findings
- PCB tracks are not routed.
- Schematic is a block diagram, not a pin-level electrical schematic.
- Power tree is not designed. The draft exposes +5 V and +3.3 V rails; a commercial board needs an integrated, reviewed regulator/protection design.
- ESP32 module land pattern and antenna keep-out are provisional; compare against the official module datasheet and recommended land pattern.
- Generic headers are engineering placeholders, not production connectors.
- BME680, MPU6050 and indoor airflow are currently external modules on connectors; the final commercial design must select exact sensor implementations.
- Outdoor anemometer signal conditioning depends on reed/Hall/open-collector output type.
- Leak probe polarity and interface need to be defined; GPIO pull-ups alone do not establish a safe/robust leak interface.
- No ERC, DRC, 3D assembly, Gerber or independent engineering review has been completed.
