### AirDrop

Smart Environmental Safety & Early Warning System
<img width="720" height="1019" alt="c7771f2b-d4c5-4e82-b6b9-3f5450d73018_thumb" src="https://github.com/user-attachments/assets/642f458e-b0a1-4754-b69e-cf3ffb5ce40d" />


AirDrop is a project I've been working on to make environmental monitoring a bit smarter and more useful in real life. The main idea is to build a system that can collect environmental data, understand what's happening around it, identify possible risks and send alerts when something seems wrong.

It's not just about collecting sensor readings and displaying random numbers on a screen. I want AirDrop to actually make that data useful, so people can understand their surroundings and react to potential problems earlier.

The project brings together electronics, embedded systems, IoT, cloud technology, hardware design and software. And yeah, there's quite a lot going on behind the scenes :)

### What AirDrop does

AirDrop uses multiple sensors to monitor different environmental and physical conditions. The sensor data is collected through ESP32 modules and sent to the software side, where it can be processed, displayed and used for risk assessment.

The idea is to make the system recognise unusual conditions instead of just showing raw readings. For example, changes in temperature, air quality, airflow, movement or water leakage can be monitored and considered while assessing the surrounding environment.

When readings indicate a possible risk, the system can generate an alert and display the relevant information through its dashboard. I'm also working towards making the alerts more meaningful, so the system doesn't unnecessarily create panic over every small change.

### The hardware

The hardware architecture is built around two ESP32-WROOM-32 modules. Each module handles a different set of sensors, allowing the system to collect information from multiple sources.

The first node focuses on environmental monitoring. It uses a BME680 sensor for environmental readings, along with an HC-SR04 ultrasonic sensor. The second node uses an MPU6050 for motion and orientation data, along with another ultrasonic sensor.

I'm also incorporating airflow detection and water leakage sensors to expand the monitoring capabilities.

The whole setup is being designed as a connected hardware system rather than a bunch of separate components sitting on a table. Getting the components to work together properly has been one of the more interesting parts of this project.

<img width="720" height="376" alt="3596a2f7-1769-47e9-b3bc-3f0e117ddbb7_thumb" src="https://github.com/user-attachments/assets/059714e7-3627-40de-9d46-676326cc336d" />

<img width="450" height="446" alt="d7ffc670-cfb3-4c63-a3d2-a81fb6386540_thumb" src="https://github.com/user-attachments/assets/8ac8d41b-714e-4095-aced-cb3581b97875" />


### PCB design and 3D assembly

I've worked on the PCB architecture and the physical assembly design as well. The goal is to move away from a basic breadboard prototype and towards a more organised, compact hardware setup.

The PCB design follows a four-layer architecture with a planned board size of 50 × 50 mm. USB power is part of the design, and the system is being structured around the two ESP32 modules.

The 3D assembly is also completed, giving the project a clearer physical structure and helping me understand how the components fit together.

Honestly, getting the hardware architecture, PCB and physical design aligned took quite a bit of figuring out. But that's part of building something from scratch.

<img width="720" height="1313" alt="fe856a81-4810-410f-9b95-57f2b1a05e3e_thumb" src="https://github.com/user-attachments/assets/2d75f3ea-048a-4d91-b830-81880d62c8d8" />

<img width="720" height="1368" alt="f0b74a75-ba79-4281-af0e-4f2cb65f675f_thumb" src="https://github.com/user-attachments/assets/95c25bf1-5027-4f39-a2c8-cc9fe3e5ec7b" />


### Software and connectivity

AirDrop uses ESP32-based firmware to collect sensor readings and communicate with Firebase Realtime Database.

The general data flow is:

Sensors → ESP32 → Firebase → Dashboard → Risk Assessment

The dashboard is being developed to bring the information together in one place. Instead of checking individual sensors manually, the aim is to have a single interface where readings, alerts and system status can be viewed.

I'm currently refining the dashboard UI and working on making the experience cleaner and easier to understand. There's still work left on the firmware and integration side, so some features are still under development.

### Risk assessment

One of the important parts of AirDrop is its proposed risk scoring system.

The idea is to translate sensor information into simple risk levels that are easier to understand.

The current scoring concept is:

Safe (0–25) for normal conditions.

Caution (26–50) for conditions that need attention.

Warning (51–75) for potentially concerning conditions.

Critical (76–100) for high-risk conditions that require immediate attention.

These ranges are part of the current prototype concept and will need proper testing, calibration and validation. They're not certified safety thresholds.

I want the system to consider multiple readings instead of relying on a single sensor value. That's important because environmental conditions can be complicated, and one unusual reading doesn't always mean there's an actual emergency.
<img width="470" height="380" alt="98307633-bf5f-48ec-a5f4-772aa08b9e72_thumb" src="https://github.com/user-attachments/assets/da2daa61-9807-441f-8716-4267c65942a6" />


### The wearable concept

Another part of AirDrop is a connected wearable.

The idea is to make important alerts accessible without requiring someone to constantly check the main dashboard. The wearable concept includes wireless connectivity, risk notifications and an SOS feature.

It is intended to work alongside the main monitoring system, giving users another way to receive information when something needs their attention.

This part is still being developed, but I want it to eventually feel like a proper extension of AirDrop rather than just another gadget.

### The dashboard

The dashboard is where the collected information comes together.

I'm working on an interface that can display environmental readings, risk levels, alerts and historical information in a more understandable way. The longer-term plan also includes location-based monitoring, maps, risk heatmaps and multilingual support.

I want the interface to feel like an actual monitoring platform, not just a page full of numbers and charts.

There's been a lot of UI refining lately because functionality matters, but so does how people interact with it. A useful system should also be easy to understand.

### Why I started working on it

Environmental safety is something that often gets attention only after something has gone wrong. Events like the Bhopal gas tragedy show why awareness, monitoring and early information matter.

AirDrop is my attempt to explore how accessible electronics, sensors and connected technology could contribute to better environmental awareness.

It's still a prototype, and I don't want to pretend it's already a complete disaster-prevention solution. There's a lot of testing, improvement and validation required before something like this could be relied on in real-world safety situations.

But I think it's worth exploring.

### Development

I've been handling the research, concept, hardware architecture, PCB design, 3D assembly and software development myself. That means I've had to figure out quite a few things along the way, including stuff I had never worked with before.

Some parts worked, some needed redesigning, and some took way longer than expected lol.

Right now, my focus is on firmware development, sensor integration, Firebase connectivity and dashboard refinement. The next major step is bringing all the individual parts together and testing how they behave as one system.

### What's next

The next stage is focused on getting the hardware and software properly connected, testing sensor readings, improving the risk assessment logic and making sure alerts are generated reliably.

After that, I want to work further on the wearable, location-based monitoring and the other planned dashboard features.

AirDrop is still evolving, and there's definitely more to build. I'm documenting the process as I go, including the designs, experiments, improvements and the occasional mistake along the way :)

### About

Created by Samriddhi Gupta

I'm a student innovator interested in technology, electronics, robotics and building things that solve actual problems.

AirDrop is an independently developed project, and this repository is where I'm keeping its development work, designs and progress.

GitHub: [Airdrop Repository](https://github.com/guptasamriddhi177/Airdrop?utm_source=chatgpt.com)

Still building. Still figuring things out. Still a lot to do. :)
