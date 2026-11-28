
**Airdrop**
<img width="720" height="1019" alt="79e908e1-a92e-4ecf-a43f-8ea918420e05_thumb" src="https://github.com/user-attachments/assets/d9303ed9-91eb-4562-9606-c04e21fdd47e" />

okay so... what if we could detect environmental danger BEFORE it becomes a whole disaster?

That's basically how AirDrop started.

AirDrop is my attempt at building a smart environmental safety and early warning system. The idea is pretty simple: instead of waiting for something to go wrong and THEN reacting to it, why not have a system that keeps monitoring what's happening and warns you when things start looking sus?

I wanted to build something that wasn't just another basic sensor project that detects one thing, beeps a little and calls it a day.

So yeah, I went a little further.

AirDrop combines ESP32-based sensor nodes, environmental monitoring, wireless communication, a Firebase-connected dashboard and a wearable alert system. The goal is to make environmental monitoring smarter, more accessible and actually useful in real-world situations.

And honestly, this project has been one big learning experience. From figuring out hardware connections to designing a custom PCB and working on the 3D assembly, there's been a LOT going on behind the scenes :)

---

**the schematic**
<img width="718" height="382" alt="9281913b-9d55-400a-bcd8-220c13e674f0_thumb" src="https://github.com/user-attachments/assets/ae634c91-5bad-4592-a854-132c547a2481" />

Here's where all the electronics start making sense.

AirDrop uses two ESP32-based sensor nodes, each handling different parts of the monitoring system.

Node 1 works with the BME680 and HC-SR04, while Node 2 uses the MPU6050 and another HC-SR04.

I've also been working on integrating airflow detection and leak detection because I didn't want the project to stop at basic environmental readings.

Basically, this is where all the different pieces start coming together.


---

**the PCB**
<img width="720" height="510" alt="813e63dc-a6cc-42ea-9701-085cc16110a7_thumb" src="https://github.com/user-attachments/assets/5cb4d8e5-6955-478b-88cc-d7137f4ea104" />

Not gonna lie, getting to the PCB stage felt pretty cool.

Instead of keeping everything as a bunch of separate modules and wires, I worked on bringing the electronics into a custom PCB design.

The current design uses a 50 × 50 mm, four-layer PCB.

A lot of planning goes into making sure the components, connections and overall layout actually work together.

---

**the enclosure**
<img width="720" height="720" alt="7121b55e-af2c-41d3-9dc1-23b6806aa01f_thumb" src="https://github.com/user-attachments/assets/02462c24-22d2-4fe1-96f6-390bf67303ea" />

A bunch of electronics thrown together isn't exactly the final vision lol.

I also worked on the 3D enclosure and assembly to give AirDrop an actual device-like form instead of just looking like a breadboard experiment.

okay but what actually happens to the data?

This is where the software side comes in.

The sensor nodes collect readings, which are intended to be sent to Firebase Realtime Database and then displayed through the monitoring dashboard.

**The basic architecture:**

ESP32 → Firebase → Dashboard

The dashboard is being developed to display environmental readings, risk levels, alerts and location-related information.

I'm also working on making the system more useful through risk scoring, forecasting concepts and a connected wearable alert interface.

<img width="720" height="1313" alt="b83756e2-9042-49c7-8eec-910ac68286c1_thumb" src="https://github.com/user-attachments/assets/45fd3d69-ff50-4f97-a4c2-17578921a6e5" />

---
| Component | Qty | Price (USD) | Price (INR) | Description |
|---|---:|---:|---:|---|
| ESP32 38-pin Development Board | 2 | $9.14 | ₹850 | The main brains handling sensor data and wireless communication. |
| BME680 Environmental Sensor | 1 | $8.91 | ₹829 | Tracks temperature, humidity, pressure and gas-resistance changes. |
| MPU6050 Accelerometer + Gyroscope | 1 | $1.66 | ₹154 | Detects movement, tilt and unusual vibrations. |
| HC-SR04 Ultrasonic Sensor | 3 | $2.22 | ₹207 | Measures distance and detects nearby objects. |
| DFRobot PAV3015 Air Velocity Sensor | 1 | $51.26 | ₹4,767.45 | Monitors airflow speed and ventilation changes. |
| Water-Level Sensor Strip | 2 | $0.46 | ₹42 | Detects water contact for basic leak and flooding alerts. |
| PMS5003 Particulate Sensor | 1 | $17.20 | ₹1,600 | Measures PM1.0, PM2.5 and PM10 particles in the air. |
| NEO-6M GPS Module | 1 | $2.78 | ₹259 | Adds GPS coordinates to outdoor alerts and records. |
| DS3231 RTC Module | 1 | $2.63 | ₹245 | Keeps accurate timestamps even when offline. |
| MicroSD SPI Reader | 1 | $0.35 | ₹33 | Allows sensor readings to be saved locally. |
| SanDisk 32GB microSD Card | 1 | $7.04 | ₹655 | Stores offline readings and event logs. |
| ESP32-C3 Super Mini | 1 | $2.71 | ₹252 | Powers the compact wireless wearable unit. |
| 0.96-inch SSD1306 OLED Display | 1 | $1.99 | ₹185 | Displays wearable status, readings and alerts. |
| 3.7V 1000mAh Li-ion Battery | 1 | $2.20 | ₹205 | Provides rechargeable power to the wearable. |
| TP4056 Charging Protection Board | 1 | $0.28 | ₹26 | Handles single-cell battery charging and protection. |
| 3V Coin Vibration Motor | 1 | $1.60 | ₹149.20 | Gives silent vibration alerts on the wearable. |
| Active Buzzer Module | 1 | $0.29 | ₹27 | Produces audible warning signals. |
| ABS Ventilated Electronics Enclosure | 1 | $5.37 | ₹499 | Protects and houses the main electronics. |
| 5V 2A Power Adapter | 1 | $2.04 | ₹190 | Supplies regulated power to the main unit. |

---

**where things stand rn**

AirDrop is still a work in progress, and there's a lot more to bring together.

The PCB design is done, the 3D assembly is done, and I'm currently working on getting the firmware and software side properly connected.

There's been plenty of trial and error, a LOT of design decisions, and probably more tabs open than my laptop can handle.

But that's kinda the point of building something from scratch, right?

I didn't want to just make something that looks cool in a project presentation. I wanted to understand how the actual thing works, from the electronics all the way to the software.

**Anyway, that's AirDrop. Still definitely not done yet :)**
