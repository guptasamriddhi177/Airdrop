#pragma once
// Provisional ESP32-WROOM-32E GPIO allocation. Verify against module pinout,
// board schematic, boot-strapping requirements and all connected peripherals.
#define PIN_I2C_SDA 21
#define PIN_I2C_SCL 22
#define PIN_WIND_PULSE 33
#define PIN_LEAK_1 34
#define PIN_LEAK_2 35
#define PIN_LEAK_3 36
#define PIN_US1_TRIG 25
#define PIN_US1_ECHO 27
#define PIN_US2_TRIG 26
#define PIN_US2_ECHO 14
// GPIO34-39 are input-only and have no internal pull-ups/pull-downs.
// Add external pull-ups or appropriate interface conditioning on the PCB.
