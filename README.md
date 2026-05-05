# 🌡️ STM32 Thermometer Project

A simple embedded system project that reads temperature and pressure data from a BMP280 sensor and displays it on a TFT LCD using an STM32F0 microcontroller.

---

## 📌 Features

- Real-time temperature measurement
- Pressure sensing via BMP280
- TFT LCD display output
- Lightweight embedded implementation
- HAL-based

---

## 🧰 Hardware Components

- STM32F030 microcontroller
- BMP280 Temperature & Pressure Sensor
- TFT LCD Display (ILI9341)
- Breadboard
- Connecting wires

---

## 🧑‍💻 Software Stack

- C (Embedded C)
- STM32 HAL 
- Keil
- Communication Protocols:
  - I2C (for BMP280 and TFT)

---
## 🧩 Hardware Design

### 📐 Schematic

The schematic includes:
- STM32F030 Bluepill board
- BMP280 sensor (I2C)
- TFT LCD interface (I2C)

![Schematic](docs/Thermometer-SchDoc.PNG)

### 🪛 PCB Layout

The PCB is designed as a solution integrating:
- Bluepull + sensor + display connectors
- Signal routing for I2C

### 🖼️ PCB Preview

![PCB](docs/Thermometer-PcbDoc.PNG)

---

## 📷 Demo

![Demo](docs/Thermometer.PNG)

---

## ⚙️ Setup & Usage

### 1. Clone the repository

```bash
git clone https://github.com/mhmdaliab/stm32-thermometer.git
