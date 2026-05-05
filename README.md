# STM32-Based Digital Thermometer & Barometer

## Overview

This project is a lightweight environmental monitoring system built using an STM32 microcontroller and a BMP280 sensor.

It measures temperature and pressure with high precision and displays the results on a simple OLED screen. The goal was to build a minimal, efficient system without unnecessary complexity—both in hardware and firmware.

This is also a personal project to stay close to low-level engineering while working as a Product Manager.

---

## Problem

Many off-the-shelf sensing solutions are either:
- over-engineered for simple use cases,
- not precise enough,
- or inefficient in terms of power and resource usage.

I wanted to explore how to design a small, reliable system that focuses on:
- accuracy
- simplicity
- efficiency

---

## Solution

The system reads environmental data from a BMP280 sensor, processes it using an STM32 microcontroller, and displays the output on an OLED screen in real time.

The architecture is intentionally simple:

Sensor (BMP280) → STM32 → OLED Display

---

## Key Features

- High precision temperature measurement (~0.01°C resolution)
- Pressure sensing with fine granularity
- Real-time display on OLED
- Lightweight firmware (no RTOS, minimal abstraction)
- Simple and maintainable design

---

## Hardware Components

- STM32 microcontroller
- BMP280 temperature & pressure sensor
- OLED display (I2C)
- Basic supporting components (wiring, power supply)

---

## System Design

The system follows a straightforward data flow:

1. Read raw data from BMP280 via I2C
2. Apply calibration and conversion
3. Format values for display
4. Render output on OLED

The focus was on keeping the loop efficient and predictable rather than adding layers of abstraction.

---

## Design Decisions & Trade-offs

Some intentional choices in this project:

- **OLED over TFT**  
  Chosen for lower power consumption and simpler interface

- **No RTOS**  
  The system is simple enough to run on a bare-metal loop

- **No connectivity (yet)**  
  Kept the scope focused on sensing accuracy and stability

- **Minimal UI**  
  Prioritized clarity and responsiveness over visual complexity

---

## Future Improvements

Some directions I’d like to explore next:

- Add WiFi/Bluetooth for remote monitoring (IoT use case)
- Log historical data
- Build a simple dashboard for visualization
- Optimize power consumption further
- Package as a standalone device

---

##  Hardware Design

###  Schematic

The schematic includes:
- STM32F030 Bluepill board
- BMP280 sensor (I2C)
- OLED LCD interface (I2C)

![Schematic](docs/Thermometer-SchDoc.PNG)

### PCB Layout

The PCB is designed as a solution integrating:
- Bluepull + sensor + display connectors
- Signal routing for I2C

### PCB Preview

![PCB](docs/Thermometer-PcbDoc.PNG)

---

## Demo

![Demo](docs/Thermometer.PNG)

---

## ⚙️ Setup & Usage

### 1. Clone the repository

```bash
git clone https://github.com/mhmdaliab/stm32-thermometer.git
```

---
## Notes

This project sits at the intersection of embedded systems and product thinking for me.

I'm interested in exploring more use cases where hardware constraints and user needs meet—especially in IoT systems.

Feedback is welcome.


