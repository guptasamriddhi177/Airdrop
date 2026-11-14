# Rev-A Connector Pinouts (provisional)

| Ref | Function | Pin 1 | Pin 2 | Pin 3 | Pin 4 | Pin 5 |
|---|---|---|---|---|---|---|
| J1 | Power input | +5V | +3V3 | GND | — | — |
| J2 | BME680 module | +3V3 | GND | SDA | SCL | — |
| J3 | MPU6050 module | +3V3 | GND | SDA | SCL | — |
| J4 | Indoor airflow I2C | +3V3 | GND | SDA | SCL | — |
| J5 | Outdoor anemometer | +3V3 | GND | Pulse | — | — |
| J6 | Leak probes | +3V3 | GND | Zone 1 | Zone 2 | Zone 3 |
| J7 | Ultrasonic 1 | +5V | GND | TRIG | ECHO_RAW | — |
| J8 | Ultrasonic 2 | +5V | GND | TRIG | ECHO_RAW | — |
| J9 | UART programming | +3V3 | GND | TX0 | RX0 | — |
| J10 | Reset/boot access | EN | BOOT/GPIO0 | — | — | — |

The 5 V ultrasonic ECHO signals must pass through the divider before reaching ESP32 GPIOs. Confirm all header numbering/orientation against the actual PCB view before wiring.
