# 🌡️ STM32 Thermometer Project

A simple embedded system project that reads temperature and pressure data from a BMP280 sensor and displays it on a TFT LCD using an STM32F0 microcontroller.

---

## 📌 Features

- Real-time temperature measurement
- Pressure sensing via BMP280
- TFT LCD display output
- Lightweight embedded implementation
- Bare-metal / HAL-based (edit accordingly)

---

## 🧰 Hardware Components

- STM32F0 microcontroller (e.g. STM32F030 / STM32F072)
- BMP280 Temperature & Pressure Sensor
- TFT LCD Display (mention model, e.g. ILI9341)
- Breadboard / PCB
- Connecting wires

---

## 🧑‍💻 Software Stack

- C (Embedded C)
- STM32 HAL / LL drivers (specify which one)
- STM32CubeIDE / Keil / PlatformIO (specify your IDE)
- Communication Protocols:
  - I2C (for BMP280)
  - SPI / Parallel (for TFT)

---
## 🧩 Hardware Design

### 📐 Schematic

The schematic includes:
- STM32F0 microcontroller
- BMP280 sensor (I2C)
- TFT LCD interface (SPI)
- Power regulation and decoupling

![Schematic](docs/Thermometer-SchDoc.PNG)

### 🪛 PCB Layout

The PCB is designed as a compact single-board solution integrating:
- MCU + sensor + display connectors
- Proper grounding and decoupling
- Signal routing for SPI and I2C

### 🖼️ PCB Preview

![PCB](docs/Thermometer-PcbDoc.PNG)

---

## 🔌 System Architecture

---

## 📷 Demo

![Demo](docs/Thermometer.PNG)

---

## ⚙️ Setup & Usage

### 1. Clone the repository

```bash
git clone https://github.com/mhmdaliab/stm32-thermometer.git
