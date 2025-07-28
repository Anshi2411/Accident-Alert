# Accident-Alert
# HitAlert
# 🚨 Multi-Sensor Environmental Monitoring System using Arduino

This project uses an **Arduino Uno** to detect **smoke**, **alcohol**, **flame**, **temperature**, and **humidity** levels using various sensors. The system alerts via a **buzzer** and **LED** when thresholds are crossed.

## 🔧 Components Used

| Component         | Description                          |
|------------------|--------------------------------------|
| Arduino Uno       | Microcontroller board                |
| MQ-2 Sensor       | Smoke and combustible gas sensor     |
| MQ-3 Sensor       | Alcohol sensor                       |
| Flame Sensor      | Infrared flame detector              |
| DHT11             | Temperature and humidity sensor      |
| Buzzer            | Audio alert                          |
| LED               | Visual alert                         |
| Jumper Wires      | For connections                      |
| Breadboard        | For prototyping                      |

## 🪛 Pin Configuration

| Component         | Arduino Pin |
|------------------|-------------|
| MQ-2             | A0          |
| MQ-3             | A1          |
| Flame Sensor     | D2          |
| DHT11            | D3          |
| Buzzer           | D8          |
| LED              | D9          |

## 📌 Sensor Thresholds

- **Smoke (MQ-2)**: `> 300`
- **Alcohol (MQ-3)**: `> 350`
- **Flame**: Detected when **digital pin reads LOW**

## 🚀 How It Works

1. **Reads smoke level** using the MQ-2 sensor.
2. **Reads alcohol level** using the MQ-3 sensor.
3. **Detects flame presence** using a digital flame sensor.
4. **Reads temperature and humidity** using the DHT11 sensor.
5. If any hazardous condition is detected:
   - **Buzzer** and **LED** are turned ON.
   - A warning message is printed on the **Serial Monitor**.
6. If all conditions are normal:
   - Buzzer and LED are turned OFF.

## 🧠 Code Overview

- `alert()` → Turns on buzzer and LED, displays alert.
- `resetAlert()` → Turns off buzzer and LED.
- Uses `Serial.print()` for monitoring sensor values.
- Uses delays between sensor readings for stability.

## 📟 Sample Output (Serial Monitor)

