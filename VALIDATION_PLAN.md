# AirDrop Rev-A Validation Plan

## Design validation
- Verify every footprint and pad number against the official datasheet.
- Verify ESP32-WROOM-32E antenna keep-out and recommended land pattern.
- Review I2C pull-up network and address compatibility.
- Review power-tree current/thermal margin.
- Review all connector pinouts and protection circuits.
- Run KiCad ERC and DRC after full electrical schematic and routing are completed.

## Bring-up
- Use current-limited low-voltage bench supply under qualified supervision.
- Verify 3.3 V rail and reset/boot behaviour before connecting sensors.
- Program firmware through UART.
- Test I2C scan and each sensor individually.
- Validate ultrasonic echo divider with a meter/oscilloscope before ESP32 connection.
- Validate anemometer pulse interface and calibration.
- Verify each leak zone with manufacturer-recommended procedure; keep electronics dry.
- Test Wi-Fi reconnect and secure Firebase access.
- Verify stale/invalid states and data gaps.

## Product validation
- Sensor accuracy and repeatability.
- Temperature/humidity operating envelope.
- ESD, EFT/surge and EMC pre-compliance.
- RF performance and antenna detuning in enclosure.
- Cable strain relief and connector retention.
- Condensation, dust and ingress tests appropriate to product claims.
- Firmware update recovery and security testing.
