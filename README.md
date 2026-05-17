# Smart Adaptive Traffic Signal System
## Using ESP32-CAM and Arduino Nano

---

## Project Overview
A 2-lane smart traffic signal system that 
automatically adjusts green light duration 
based on real-time vehicle density detected 
by ESP32-CAM camera.

Built as a yearly project assignment for 
solving real traffic problems in India.

---

## Problem Statement
Fixed timer traffic signals waste time — 
empty lanes get same green time as busy lanes.
This project solves that by giving more green 
time to lanes with more vehicles.

---

## How It Works
1. ESP32-CAM captures bird's eye view of
   intersection every 2 seconds
2. Image divided into 2 halves — one per lane
3. Bright pixels counted in each half
   (toy cars are light colored on black road)
4. Lane with more cars gets longer green time
5. Arduino Nano controls all 6 LED signals
6. System adapts automatically every cycle

---

## Green Time Formula
total = Lane A cars + Lane B cars
green time = (lane cars / total) x 30 seconds
minimum green = 5 seconds
maximum green = 30 seconds

---

## Components Used
| Component         | Quantity | Purpose                  |
|-------------------|----------|--------------------------|
| ESP32-CAM         | 1        | Camera and processing    |
| Arduino Nano      | 1        | Controls LEDs            |
| FTDI232           | 1        | Upload code to ESP32-CAM |
| Red LED 5mm       | 2        | Red signal               |
| Yellow LED 5mm    | 2        | Yellow signal            |
| Green LED 5mm     | 2        | Green signal             |
| 220 ohm Resistor  | 6        | Protect LEDs             |
| Breadboard        | 1        | Circuit connections      |
| Jumper wires      | 1 pack   | Wiring                   |
| MicroSD card 4GB  | 1        | ESP32-CAM storage        |
| Foam board        | 1        | Road model base          |
| Toy cars          | 6        | Vehicle simulation       |

Total Cost: approximately Rs 1850

---

## Circuit Connections

### Arduino Nano
| Arduino Pin | Connected To        |
|-------------|---------------------|
| Pin 2       | Red LED Lane A      |
| Pin 3       | Yellow LED Lane A   |
| Pin 4       | Green LED Lane A    |
| Pin 5       | Red LED Lane B      |
| Pin 6       | Yellow LED Lane B   |
| Pin 7       | Green LED Lane B    |
| Pin 0 RX    | ESP32-CAM TX pin    |
| GND         | All LED short legs  |
| USB         | Laptop USB          |

### ESP32-CAM
| ESP32-CAM Pin | Connected To        |
|---------------|---------------------|
| 5V            | FTDI232 VCC         |
| GND           | FTDI232 GND         |
| TX U0T        | Arduino Nano Pin 0  |
| U0R           | FTDI232 TX          |
| IO0           | GND during upload   |

---

## Files in This Repository
| File              | Description                    |
|-------------------|--------------------------------|
| arduino_nano.ino  | Arduino Nano code              |
| esp32_cam.ino     | ESP32-CAM code                 |
| README.md         | Project documentation          |
| circuit.jpg       | Circuit diagram photo          |
| project.jpg       | Complete project photo         |

---

## How to Run This Project

### Step 1 — Upload ESP32-CAM Code
- Connect ESP32-CAM to FTDI232
- Connect IO0 to GND for upload mode
- Open esp32_cam.ino in Arduino IDE
- Select board: AI Thinker ESP32-CAM
- Click Upload
- Press RESET button when you see dots
- Remove IO0 wire after upload

### Step 2 — Upload Arduino Nano Code
- Connect Arduino Nano to laptop via USB
- Open arduino_nano.ino in Arduino IDE
- Select board: Arduino Nano
- Select processor: ATmega328P Old Bootloader
- Click Upload

### Step 3 — Connect Everything
- ESP32-CAM TX to Arduino Nano Pin 0
- ESP32-CAM GND to Arduino GND
- Power both from laptop USB

### Step 4 — Run Demo
- Place toy cars on Lane A
- Watch Lane A get longer green time
- Move cars to Lane B
- Watch system adapt next cycle

---

## Software Requirements
- Arduino IDE 2.x
- ESP32 board package by Espressif Systems

---

## Demo Results
| Lane A Cars | Lane B Cars | Lane A Green | Lane B Green |
|-------------|-------------|--------------|--------------|
| 4           | 1           | 24 seconds   | 5 seconds    |
| 1           | 4           | 5 seconds    | 24 seconds   |
| 3           | 3           | 15 seconds   | 15 seconds   |
| 0           | 0           | 5 seconds    | 5 seconds    |

---

## Real World Application
This system can be scaled to real intersections
to reduce traffic congestion in Indian cities.
Current fixed timer signals waste 40% of green
time on empty lanes during off peak hours.

---

## Project By
Name: KUNDAN KUMAR
Year: 2nd Year Engineering
Subject: IoT Project Assignment
College: Guru Gobind Singh Indraprastha University 
Year: 2025-2026

---

## Acknowledgements
Special thanks to my teacher for guidance
and support throughout this project.
