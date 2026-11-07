# AirDrop — Environmental Safety Sensor Node

![Full 3D assembly](https://private-us-east-1.manuscdn.com/sessionFile/4vA7Ush93JtYcwiMFpgiii/sandbox/F0VCyMK39L4xFDEEGl2rhZ-images_1794068682982_na1fn_L2hvbWUvdWJ1bnR1L2FpcmRyb3AvZG9jcy9pbWFnZXMvZnVsbF8zZF9hc3NlbWJseQ.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNHZBN1VzaDkzSnRZY3dpTUZwZ2lpaS9zYW5kYm94L0YwVkN5TUszOUw0eEZERUVHbDJyaFotaW1hZ2VzXzE3OTQwNjg2ODI5ODJfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyRnBjbVJ5YjNBdlpHOWpjeTlwYldGblpYTXZablZzYkY4elpGOWhjM05sYldKc2VRLnBuZyIsIkNvbmRpdGlvbiI6eyJEYXRlTGVzc1RoYW4iOnsiQVdTOkVwb2NoVGltZSI6MTc5NjA4MzIwMH19fV19&Key-Pair-Id=K2QY5QTL8JSY6C&Signature=MEQCIEHNNiIHqngVoBS6QsanILRmfHGlbqm4WrIVY0cwMY~NAiAW0YFXGnNvs335smZ1rH3OJRth2mu~ai0BrC6sAUFPlA__)

AirDrop is an single-PCB ESP32-based environmental monitoring and early-warning prototype. It combines environmental sensing, motion/vibration, airflow, wind, leak and distance inputs into one connected sensor node. Measurements are processed locally, uploaded over Wi-Fi to Firebase Realtime Database, and displayed in a mobile-friendly dashboard.

> **Prototype note:** The repository is complete as a design package and starter implementation. Sensor thresholds, connector compatibility, power margins, antenna clearance, ERC/DRC, and field performance must be reviewed before using the device for safety-critical decisions.

## Why it was made

Hazards often develop as a combination of small changes: rising humidity, abnormal air movement, water presence, movement, or changing distance. AirDrop was made to combine those signals in one affordable, inspectable system instead of requiring separate disconnected instruments. The project also provides a path from a low-cost proof of concept to a single-PCB field node.

## How to use it

1. Open `pcb/AirDrop.kicad_pro` in KiCad 7 or later. The board is a 2-layer, 120 × 70 mm carrier PCB.
2. Review the signal map in [`docs/wiring_diagram.md`](docs/wiring_diagram.md), especially the 5 V ultrasonic echo divider and the power-input protection.
3. Open `cad/AirDropAssembly.FCStd` in FreeCAD. The enclosure and all modeled parts are also exported as STEP files in `cad/`.
4. Populate the single custom PCB with the selected controller, power and connector circuitry, then connect the external sensor harnesses through the documented connectors.
5. Flash `firmware/airdrop_firmware/airdrop_firmware.ino` after setting Wi-Fi and Firebase credentials.
6. Open the serial monitor at 115200 baud. The firmware prints sensor data once per second and uploads a compact JSON record every five seconds when connected.

## System overview

![Schematic / wiring](https://private-us-east-1.manuscdn.com/sessionFile/4vA7Ush93JtYcwiMFpgiii/sandbox/F0VCyMK39L4xFDEEGl2rhZ-images_1794068682982_na1fn_L2hvbWUvdWJ1bnR1L2FpcmRyb3AvZG9jcy9pbWFnZXMvc2NoZW1hdGljX3dpcmluZw.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNHZBN1VzaDkzSnRZY3dpTUZwZ2lpaS9zYW5kYm94L0YwVkN5TUszOUw0eEZERUVHbDJyaFotaW1hZ2VzXzE3OTQwNjg2ODI5ODJfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyRnBjbVJ5YjNBdlpHOWpjeTlwYldGblpYTXZjMk5vWlcxaGRHbGpYM2RwY21sdVp3LnBuZyIsIkNvbmRpdGlvbiI6eyJEYXRlTGVzc1RoYW4iOnsiQVdTOkVwb2NoVGltZSI6MTc5NjA4MzIwMH19fV19&Key-Pair-Id=K2QY5QTL8JSY6C&Signature=MEQCIDP59WtJy0kEdeVcdDPP4vSfvhGuRE~gaXTxZYk5xlVlAiBQx-HOxynhxZZbBduwbXQpPoee~Fdde1q7YuTCCfUAeg__)

The sensor node uses I2C for the BME680 and MPU6050, ADC input for indoor airflow, pulse input for the anemometer, three digital leak inputs, and two trigger/echo ultrasonic channels. The planned cloud record is documented in [`docs/firebase_schema.json`](docs/firebase_schema.json).

## PCB

![PCB layout](https://private-us-east-1.manuscdn.com/sessionFile/4vA7Ush93JtYcwiMFpgiii/sandbox/F0VCyMK39L4xFDEEGl2rhZ-images_1794068682982_na1fn_L2hvbWUvdWJ1bnR1L2FpcmRyb3AvZG9jcy9pbWFnZXMvcGNiX2xheW91dA.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNHZBN1VzaDkzSnRZY3dpTUZwZ2lpaS9zYW5kYm94L0YwVkN5TUszOUw0eEZERUVHbDJyaFotaW1hZ2VzXzE3OTQwNjg2ODI5ODJfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyRnBjbVJ5YjNBdlpHOWpjeTlwYldGblpYTXZjR05pWDJ4aGVXOTFkQS5wbmciLCJDb25kaXRpb24iOnsiRGF0ZUxlc3NUaGFuIjp7IkFXUzpFcG9jaFRpbWUiOjE3OTYwODMyMDB9fX1dfQ__&Key-Pair-Id=K2QY5QTL8JSY6C&Signature=MEUCIQCc37LpIUARpQ4KvfdlIaE~Qzn-AwRYUalKbMFdR~-1gAIgU8sPF-yOLWeqaexcFBibGtoRAVzRpqiLB0FYZ2kVOGA_)

The KiCad package includes the project file, board layout, schematic entry file, project-local preferences, and a Gerber archive. `gerbers.zip` contains copper, solder-mask, silkscreen, edge-cuts, and drill outputs. The readable signal-level schematic is also included as `pcb/AirDrop_legacy.sch`.

## CAD and modeled parts

![3D render](https://private-us-east-1.manuscdn.com/sessionFile/4vA7Ush93JtYcwiMFpgiii/sandbox/F0VCyMK39L4xFDEEGl2rhZ-images_1794068682982_na1fn_L2hvbWUvdWJ1bnR1L2FpcmRyb3AvZG9jcy9pbWFnZXMvZnVsbF8zZF9hc3NlbWJseQ.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNHZBN1VzaDkzSnRZY3dpTUZwZ2lpaS9zYW5kYm94L0YwVkN5TUszOUw0eEZERUVHbDJyaFotaW1hZ2VzXzE3OTQwNjg2ODI5ODJfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyRnBjbVJ5YjNBdlpHOWpjeTlwYldGblpYTXZablZzYkY4elpGOWhjM05sYldKc2VRLnBuZyIsIkNvbmRpdGlvbiI6eyJEYXRlTGVzc1RoYW4iOnsiQVdTOkVwb2NoVGltZSI6MTc5NjA4MzIwMH19fV19&Key-Pair-Id=K2QY5QTL8JSY6C&Signature=MEQCIEHNNiIHqngVoBS6QsanILRmfHGlbqm4WrIVY0cwMY~NAiAW0YFXGnNvs335smZ1rH3OJRth2mu~ai0BrC6sAUFPlA__)

The FreeCAD assembly contains the enclosure bottom, lid, and one integrated custom AirDrop PCB. It contains no ESP32 development board, sensor breakout board, daughterboard, or bonded sub-board. It was opened and verified in FreeCAD; `cad/verification.txt` records the check. STEP exports are included for the enclosure bottom, enclosure lid, and single PCB:

- `cad/EnclosureBottom.step`
- `cad/EnclosureLid.step`
- `cad/SingleAirDropPCB.step`

The parametric source is `cad/airdrop_enclosure.scad`; the FreeCAD export script is `cad/generate_freecad.py`.

## Pinout

![Pinout](https://private-us-east-1.manuscdn.com/sessionFile/4vA7Ush93JtYcwiMFpgiii/sandbox/F0VCyMK39L4xFDEEGl2rhZ-images_1794068682982_na1fn_L2hvbWUvdWJ1bnR1L2FpcmRyb3AvZG9jcy9pbWFnZXMvcGlub3V0.png?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvNHZBN1VzaDkzSnRZY3dpTUZwZ2lpaS9zYW5kYm94L0YwVkN5TUszOUw0eEZERUVHbDJyaFotaW1hZ2VzXzE3OTQwNjg2ODI5ODJfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyRnBjbVJ5YjNBdlpHOWpjeTlwYldGblpYTXZjR2x1YjNWMC5wbmciLCJDb25kaXRpb24iOnsiRGF0ZUxlc3NUaGFuIjp7IkFXUzpFcG9jaFRpbWUiOjE3OTYwODMyMDB9fX1dfQ__&Key-Pair-Id=K2QY5QTL8JSY6C&Signature=MEQCIFBwS-RRhomT46c6l6iGiaMQsRwJ8Xjhyu~c~69MLAYtAiBK6ZbZQ4MaVf7c91tQZVCdEYW6hRzzHi7lEpU6eW8cEg__)

The authoritative connector map is in `docs/wiring_diagram.md`. All interfaces terminate on the one custom PCB; external sensors are not modeled as separate boards.

## Firmware

The firmware is an Arduino/ESP32 starter implementation. Its risk score now consumes temperature, humidity, pressure, gas resistance, airflow ADC, wind pulses, accelerometer magnitude, all three leak zones, and both ultrasonic distance channels. It reads the BME680 and MPU6050, samples airflow, counts wind pulses, reads leak inputs, measures ultrasonic distance, calculates a transparent 0–100 indicator score, and uploads JSON to Firebase. The score is an indicator only; it is not a certified hazard detector.

## Bill of materials

The complete BOM is [`BOM.csv`](BOM.csv). The BOM intentionally contains one line only: one single custom AirDrop PCB assembly. It does not include an ESP32 development board, sensor breakout boards, or separate boards to be bonded together. The PCB exposes external sensor connectors. PCB fabrication pricing is not included; the fabrication outputs remain in `gerbers.zip` for owner fabrication.

## Repository layout

```text
├── BOM.csv
├── cad/
│   ├── AirDropAssembly.FCStd
│   ├── EnclosureBottom.step
│   ├── EnclosureLid.step
│   └── SingleAirDropPCB.step
│   ├── airdrop_enclosure.scad
│   └── generate_freecad.py
├── docs/
│   ├── images/
│   ├── firebase_schema.json
│   └── wiring_diagram.md
├── firmware/
│   ├── airdrop_firmware/airdrop_firmware.ino
│   └── platformio.ini
├── gerbers/
└── pcb/
    ├── AirDrop.kicad_pro
    ├── AirDrop.kicad_prl
    ├── AirDrop.kicad_sch
    ├── AirDrop.kicad_pcb
    └── AirDrop_legacy.sch
```

## Dashboard

The project dashboard concept is available at [foresight-alert-sphere.lovable.app](https://foresight-alert-sphere.lovable.app/). The firmware payload shape is intentionally compatible with the Firebase structure in `docs/firebase_schema.json`.

## Verification records

- KiCad Gerber export completed with F.Mask and B.Mask layers.
- FreeCAD assembly verification: `cad/verification.txt`.
- The BOM contains one line for one single custom PCB assembly; no ESP32 development board or sensor breakout boards are included.

## License

Released under the MIT License. Hardware files are provided under CERN-OHL-S-2.0 terms where applicable. See `LICENSE`.
