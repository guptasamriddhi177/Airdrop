#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>
#include <Adafruit_MPU6050.h>
#include <ArduinoJson.h>
#include "pins.h"

Adafruit_BME680 bme;
Adafruit_MPU6050 mpu;
volatile uint32_t windPulses = 0;
uint32_t lastSample = 0;
bool bmeOk = false, mpuOk = false;

void IRAM_ATTR windPulseISR() { windPulses++; }

float readDistanceCm(uint8_t trig, uint8_t echo) {
  digitalWrite(trig, LOW); delayMicroseconds(3);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  uint32_t duration = pulseIn(echo, HIGH, 30000);
  if (duration == 0) return NAN;
  return duration * 0.0343f / 2.0f;
}

void setup() {
  Serial.begin(115200);
  delay(300);
  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
  Wire.setClock(100000);

  pinMode(PIN_WIND_PULSE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_WIND_PULSE), windPulseISR, FALLING);

  pinMode(PIN_LEAK_1, INPUT); pinMode(PIN_LEAK_2, INPUT); pinMode(PIN_LEAK_3, INPUT);
  pinMode(PIN_US1_TRIG, OUTPUT); pinMode(PIN_US2_TRIG, OUTPUT);
  pinMode(PIN_US1_ECHO, INPUT); pinMode(PIN_US2_ECHO, INPUT);

  bmeOk = bme.begin(0x76, &Wire);
  if (!bmeOk) bmeOk = bme.begin(0x77, &Wire);
  if (bmeOk) {
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150);
  }
  mpuOk = mpu.begin(0x68, &Wire);
  if (mpuOk) {
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  }
  Serial.println("AirDrop Rev-A firmware scaffold started.");
}

void loop() {
  if (millis() - lastSample < 2000) return;
  lastSample = millis();

  StaticJsonDocument<1024> doc;
  doc["device_id"] = "airdrop-rev-a";
  doc["uptime_ms"] = millis();
  doc["bme680"]["state"] = bmeOk ? "available" : "unavailable";
  if (bmeOk && bme.performReading()) {
    doc["bme680"]["temperature_c"] = bme.temperature;
    doc["bme680"]["humidity_pct"] = bme.humidity;
    doc["bme680"]["pressure_hpa"] = bme.pressure / 100.0f;
    doc["bme680"]["gas_resistance_ohm"] = bme.gas_resistance;
  } else {
    doc["bme680"]["state"] = "read_error";
  }

  doc["mpu6050"]["state"] = mpuOk ? "available" : "unavailable";
  if (mpuOk) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    doc["mpu6050"]["accel_x_ms2"] = a.acceleration.x;
    doc["mpu6050"]["accel_y_ms2"] = a.acceleration.y;
    doc["mpu6050"]["accel_z_ms2"] = a.acceleration.z;
    doc["mpu6050"]["gyro_x_rads"] = g.gyro.x;
    doc["mpu6050"]["gyro_y_rads"] = g.gyro.y;
    doc["mpu6050"]["gyro_z_rads"] = g.gyro.z;
  }

  uint32_t pulses;
  noInterrupts(); pulses = windPulses; windPulses = 0; interrupts();
  doc["outdoor_anemometer"]["pulses_last_2s"] = pulses;
  doc["outdoor_anemometer"]["wind_speed_m_s"] = nullptr; // Requires selected anemometer calibration constant.

  doc["leak_zones"]["zone_1_raw"] = digitalRead(PIN_LEAK_1);
  doc["leak_zones"]["zone_2_raw"] = digitalRead(PIN_LEAK_2);
  doc["leak_zones"]["zone_3_raw"] = digitalRead(PIN_LEAK_3);
  doc["leak_zones"]["interpretation"] = "NOT_CONFIGURED"; // Define probe polarity before asserting wet/dry.

  doc["ultrasonic"]["distance_1_cm"] = readDistanceCm(PIN_US1_TRIG, PIN_US1_ECHO);
  doc["ultrasonic"]["distance_2_cm"] = readDistanceCm(PIN_US2_TRIG, PIN_US2_ECHO);

  serializeJson(doc, Serial);
  Serial.println();
}
