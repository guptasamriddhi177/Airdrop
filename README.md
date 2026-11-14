# AIRDROP_Environmental_Node

**Draft KiCad project; not production-ready.** This package is based on `AIRDROP_Custom_BOM_USD.csv` and your approved assumptions. It is intended as an editable starting point to share by AirDrop.

## Included concept

- Oversized 170 x 75 mm four-layer carrier PCB to provide room for three HC-SR04 modules, ESP32-WROOM-32, BME680, MPU6050, leak electrodes, power input, and wearable alert features.
- One ESP32-WROOM-32 populated; second BOM quantity treated as spare.
- Three HC-SR04 modules represented by 1x4 headers and nominal module placement space.
- BME680 and MPU6050 locations shown as placeholder package footprints.
- Airflow sensor left as an explicit placeholder because the BOM has no manufacturer/model.
- Leak sensor implemented as exposed PCB electrodes; wearable section represented by button and vibration motor connection.
- Gerber ZIP is a preliminary geometry/placement export only.

## Important engineering status

The current schematic is a functional block-diagram note, not a connected symbol-level schematic. The PCB is a placement skeleton: there is no electrical routing, power tree, actual sensor pin mapping, ESP32 RF clearance validation, DRC, ERC, or verified vendor land patterns. Gerbers are **not** suitable for ordering a working board. Before fabrication, a hardware designer must select exact airflow and regulator parts, verify the HC-SR04 board dimensions/mounting, replace all placeholder footprints with datasheet-verified footprints, complete the schematic and routing, and run KiCad ERC/DRC.

The three ultrasonic modules are module-board assemblies mounted on the same carrier PCB via headers; they are not bare transducers integrated into the carrier.
