# Power and Connector Design — Open Items

## Power
The PCB placement draft exposes separate 5 V and 3.3 V input rails for engineering bring-up. The integrated regulator, USB-C power negotiation (if any), input protection, current budget, thermal design and battery charging are NOT designed yet. A commercial product must not use the board until the power tree is designed and reviewed.

## Connectors
Connector footprints are generic 2.54 mm headers in the placement draft. They are not selected production connectors. Replace them with locking, keyed, appropriately rated connectors after cable, environment, current, mating-cycle and ingress requirements are known.

## Ultrasonic
HC-SR04-style ECHO output is commonly 5 V. The PCB draft includes provisional resistor divider footprints, but their exact topology and values must be reviewed and measured. Do not connect 5 V to ESP32 GPIO directly.

## Leak probes
GPIO34–36 have no internal pull-ups. External biasing and protection must be designed. The current placement draft does not yet include completed input conditioning or ESD protection.
