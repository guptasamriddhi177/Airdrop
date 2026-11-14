# AirDrop Rev-A Architecture

One main PCB using an ESP32-WROOM-32E module. It exposes interfaces for:
- BME680 I²C sensor module
- MPU6050 I²C sensor module
- Indoor airflow I²C sensor (TBD)
- Outdoor anemometer pulse output (TBD)
- Three independent leak-probe zones (electrical interface TBD)
- Two HC-SR04-compatible distance sensors (echo level shifting required)
- UART programming/debug
- 5 V and regulated 3.3 V power rails

The PCB is a single integrated controller and interface board. Sensor probes and sensor modules connect externally; the current Rev-A board draft does not mount every sensor IC directly.
