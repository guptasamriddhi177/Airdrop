**AirDrop** 
<img width="720" height="1019" alt="44d46a71-a989-4e50-9bbf-b5a750be2714_thumb" src="https://github.com/user-attachments/assets/16137e2a-9c5d-41a7-bcbb-a4d2106a6ab8" />

okay so... what if we could detect environmental danger BEFORE it becomes a whole disaster?

That's basically how AirDrop started.

AirDrop is my attempt at building a smart environmental safety and early warning system. The idea is pretty simple: instead of waiting for something to go wrong and THEN reacting to it, why not have a system that keeps monitoring what's happening and warns you when things start looking sus?

I wanted to build something that wasn't just another basic sensor project that detects one thing, beeps a little and calls it a day.

So yeah, I went a little further.

AirDrop combines ESP32-based sensor nodes, environmental monitoring, wireless communication, a Firebase-connected dashboard and a wearable alert system. The goal is to make environmental monitoring smarter, more accessible and actually useful in real-world situations.

And honestly, this project has been one big learning experience. From figuring out hardware connections to designing a custom PCB and working on the 3D assembly, there's been a LOT going on behind the scenes :)

---

**the schematic ⚡**

Here's where all the electronics start making sense.

AirDrop uses two ESP32-based sensor nodes, each handling different parts of the monitoring system.

Node 1 works with the BME680 and HC-SR04, while Node 2 uses the MPU6050 and another HC-SR04.

I've also been working on integrating airflow detection and leak detection because I didn't want the project to stop at basic environmental readings.

Basically, this is where all the different pieces start coming together.

<img width="720" height="376" alt="e74066b8-12bf-4257-9a75-d32cdfb746dc_thumb" src="https://github.com/user-attachments/assets/a15c04b6-7f27-475b-9b01-eabaa630d078" />


---

**the PCB**

Not gonna lie, getting to the PCB stage felt pretty cool.

Instead of keeping everything as a bunch of separate modules and wires, I worked on bringing the electronics into a custom PCB design.

The current design uses a 50 × 50 mm, four-layer PCB.

A lot of planning goes into making sure the components, connections and overall layout actually work together.

<img width="450" height="446" alt="b2c2ac50-f2b0-4f29-b066-8b2767bacadf_thumb" src="https://github.com/user-attachments/assets/2b1a7878-cb17-4105-868a-a415dcfc3bf2" />

---

**the enclosure**

A bunch of electronics thrown together isn't exactly the final vision lol.

I also worked on the 3D enclosure and assembly to give AirDrop an actual device-like form instead of just looking like a breadboard experiment.

<img width="470" height="380" alt="17d65246-f35a-4a36-8ca2-4434e78b9630_thumb" src="https://github.com/user-attachments/assets/e6d68e70-f262-4718-b320-26664b3a1374" />

okay but what actually happens to the data?

This is where the software side comes in.

The sensor nodes collect readings, which are intended to be sent to Firebase Realtime Database and then displayed through the monitoring dashboard.

**The basic architecture:**

ESP32 → Firebase → Dashboard

The dashboard is being developed to display environmental readings, risk levels, alerts and location-related information.

I'm also working on making the system more useful through risk scoring, forecasting concepts and a connected wearable alert interface.

<img width="720" height="1313" alt="e4b60a1b-eaa5-4859-a846-74a366116941_thumb" src="https://github.com/user-attachments/assets/cb359445-fc4d-402c-87c9-d52f6167f43a" />

---

**where things stand rn 🚀**

AirDrop is still a work in progress, and there's a lot more to bring together.

The PCB design is done, the 3D assembly is done, and I'm currently working on getting the firmware and software side properly connected.

There's been plenty of trial and error, a LOT of design decisions, and probably more tabs open than my laptop can handle.

But that's kinda the point of building something from scratch, right?

I didn't want to just make something that looks cool in a project presentation. I wanted to understand how the actual thing works, from the electronics all the way to the software.

**Anyway, that's AirDrop. Still building, still figuring things out, and definitely not done yet :)**
