AIRDROP: Smart Environmental Safety & Early Warning System

<img width="720" height="1019" alt="c7771f2b-d4c5-4e82-b6b9-3f5450d73018_thumb" src="https://github.com/user-attachments/assets/9e268d99-5ade-48a1-8765-226d14a7272d" />

It is a smart environmental safety and early-warning system designed to monitor surroundings, detect unusual environmental changes and alert people when something doesn't seem right.

<img width="720" height="405" alt="0e0d7a9c-f9d2-4eef-81de-85b5f49f2ab9_thumb" src="https://github.com/user-attachments/assets/b0bc6614-e372-4167-8bc9-742dff26d441" />

AIRDROP combines multiple sensors, ESP32-based modules and a connected dashboard to make environmental monitoring more accessible. The idea is to build something that doesn't just collect sensor readings but can also help people understand when their surroundings might be becoming unsafe.

I started working on AIRDROP because I wanted to explore how affordable electronics and software could be used for real-world safety problems. I wanted to go beyond making another basic temperature or gas detector, so I started developing a system with multiple monitoring modules, a wearable alert concept and a connected application.

Features

- Environmental monitoring using multiple sensors.
- Temperature, humidity and air-quality monitoring.
- Airflow detection.
- Water-leak detection.
- Motion and distance monitoring.
- ESP32-based wireless communication.
- Firebase integration for real-time data updates.
- Dashboard with sensor readings and alerts.
- Risk scoring system with different safety levels.
- Location-based monitoring concept.
- Wearable notifications and SOS functionality.
- Early-warning and forecasting features under development.

Hardware

AIRDROP uses ESP32-based modules to collect information from different sensors.

Main components:

- ESP32-WROOM-32 modules
- BME680 environmental sensor
- MPU6050 motion sensor
- HC-SR04 ultrasonic sensors
- Airflow sensor
- Water-leak sensors
- Custom-designed PCB
- USB power connection

The system is divided into multiple sensor modules so different environmental parameters can be monitored together.

Schematics 
<img width="720" height="400" alt="2b020648-ed2b-4084-bb17-10407751aba8_thumb" src="https://github.com/user-attachments/assets/740fa0f6-552d-4f8f-9e65-a15490eca258" />

Instead of relying entirely on ready-made sensor boards, I worked on a custom PCB design for the system.

The design uses two ESP32-WROOM-32 modules and a combined board architecture. The goal was to make the electronics more organized and suitable for a proper physical assembly.

PCB specifications:

- 4-layer PCB
- 50 × 50 mm board
- USB-powered design
- Two ESP32-WROOM-32 modules
- Custom component placement and routing

3D Assembly

<img width="470" height="380" alt="98307633-bf5f-48ec-a5f4-772aa08b9e72_thumb" src="https://github.com/user-attachments/assets/127b4549-4158-4e3d-b965-cb545065ff83" />
<img width="720" height="551" alt="1f4e5274-c258-4b62-9743-5bc52c5c924d_thumb" src="https://github.com/user-attachments/assets/29fe4e18-2d3b-4e3e-8d82-310e3155264f" />


I also worked on the 3D assembly to understand how the different components would fit together physically.

This helped me visualize the overall structure before moving towards the actual hardware build.

Software & Dashboard

<img width="720" height="1570" alt="04434ef3-845b-442c-a095-8e11ffd926a1_thumb" src="https://github.com/user-attachments/assets/46b92061-39d7-4f0e-83eb-57a4d31e1cd3" />

<img width="720" height="1570" alt="404dea71-05fa-43c4-9e14-1719cf908065_thumb" src="https://github.com/user-attachments/assets/80ea2635-3362-4ef1-a759-a5008a4697f2" />

The software side of AIRDROP connects the sensor hardware to a Firebase backend.

The dashboard is designed to display environmental readings, safety scores, alerts and location information.

The planned risk classification is:

- Safe: 0–25
- Caution: 26–50
- Warning: 51–75
- Critical: 76–100

I also want to include a map-based monitoring system, historical readings, multilingual support and a rescue mode.

Firmware

The firmware is being developed for the ESP32 modules.

Its main responsibilities include:

- Reading data from connected sensors.
- Processing sensor readings.
- Communicating between modules.
- Sending data to Firebase.
- Detecting unusual readings.
- Triggering alerts when required.

The idea is to avoid unnecessary panic alerts and make notifications meaningful.

Current Progress

The PCB design and 3D assembly have been worked on, and the dashboard and software architecture are also in development.

I'm currently focusing on firmware, sensor integration and connecting the different parts of the system.

There are still plenty of things to test and improve, especially when it comes to making the hardware and software work together reliably.

Why AIRDROP?

I wanted to build something that could have a practical purpose outside a normal electronics project.

Environmental hazards can affect people without much warning. AIRDROP is my attempt to explore how connected sensors and accessible technology could help detect unusual conditions earlier.

It's still a work in progress, but every part of this project is helping me understand hardware design, embedded systems, software integration and real-world engineering.

Credits & Acknowledgements

AIRDROP is an independently developed project.

Hardware architecture, PCB design, software integration and system planning are part of the project development.

Thanks to the open-source hardware and software communities for the tools, libraries and resources that make projects like this possible.

Built with curiosity, experimentation and a lot of debugging.

AIRDROP — Detect Early. Alert Smarter. Stay Safer.
