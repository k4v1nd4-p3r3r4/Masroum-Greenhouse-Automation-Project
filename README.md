# 🌱 Masroum Greenhouse Automation Project

The **Masroum Greenhouse Automation Project** is an Arduino-based smart greenhouse monitoring and control system. It automates essential greenhouse functions such as irrigation, lighting, and environmental monitoring using sensors and actuators.

## 🔧 Features

- 🌡️ **Temperature and Humidity Monitoring** using DHT11 sensor
- 🌱 **Soil Moisture Monitoring** for optimal irrigation control
- 💡 **Automated Grow Light Control**
- 🚿 **Water Pump Activation** based on soil moisture level
- 💬 **Real-Time Feedback** via LCD display

## 📷 Components Used

| Component | Description |
|----------|-------------|
| Arduino Uno | Microcontroller Board |
| DHT11 | Temperature and Humidity Sensor |
| Soil Moisture Sensor | Analog soil water level detector |
| Relay Module | For controlling pump and lights |
| LCD Display (16x2) | To show current readings |
| LED & Pump | Grow light and water system actuator |

## ⚙️ Circuit Connections

| Arduino Pin | Connected Component |
|-------------|---------------------|
| A0 | Soil Moisture Sensor |
| 2 | DHT11 Data Pin |
| 3 | LCD RS |
| 4 | LCD EN |
| 5-6 | LCD D4-D5 |
| 7-8 | LCD D6-D7 |
| 9 | Pump Relay |
| 10 | Light Relay |

## 📜 Code Overview

- **Sensor Readings**:
  - `DHT11` for humidity and temperature.
  - Analog input from soil moisture sensor.
- **Actuation Logic**:
  - If soil moisture < threshold → turn on pump.
  - Light relay can be triggered manually or based on conditions.
- **LCD Output**:
  - Displays humidity, temperature, and soil moisture in real-time.

## 🚀 Getting Started

1. Upload the `.ino` file to your Arduino using the Arduino IDE.
2. Connect all components as described.
3. Power the Arduino and observe automated responses on the LCD and via relays.

## Link: https://www.tinkercad.com/things/fgrkPaaPXGq-masroum-greenhouse-automation-project



