# 🔥 IoT-Based Fire and Gas Leakage Alert System

An IoT-based Fire and Gas Leakage Alert System that uses an ESP32 microcontroller, environmental sensors, and cloud connectivity to monitor temperature, humidity, and combustible gas levels in real time.

The project integrates a DHT22 temperature and humidity sensor, MQ-2 gas sensor, LCD display, buzzer, and LED alert system with the ThingSpeak cloud platform to provide real-time environmental monitoring and hazard detection.

## 🚀 Overview

The **IoT-Based Fire and Gas Leakage Alert System** is designed to monitor environmental conditions and identify potentially dangerous situations such as gas leakage, smoke detection, and abnormal temperature levels.

The system uses an ESP32 microcontroller as its central processing unit. It continuously collects sensor readings, evaluates them against predefined safety thresholds, and activates audio-visual alerts whenever a potentially hazardous condition is detected.

The collected sensor information is also transmitted to the ThingSpeak cloud platform through Wi-Fi, allowing remote monitoring and visualization of environmental data.

The project combines:

- Internet of Things (IoT)
- Real-time environmental monitoring
- Temperature and humidity sensing
- Gas leakage and smoke detection
- ESP32 microcontroller programming
- Audio-visual alert mechanisms
- Wi-Fi connectivity
- ThingSpeak cloud integration

## 💡 Problem Statement

Fire accidents and gas leakage incidents can cause serious damage to human life, property, and industrial environments.

Traditional monitoring systems may require continuous human supervision and may not always provide immediate notifications when dangerous environmental conditions occur.

Some of the major safety concerns include:

- Unexpected gas leakage.
- Combustible gas accumulation.
- Smoke detection.
- Abnormal temperature increases.
- Delayed hazard identification.
- Lack of continuous environmental monitoring.

Therefore, an automated monitoring system is required to continuously monitor environmental conditions and provide immediate alerts whenever potentially dangerous situations are detected.

## 🎯 Proposed Solution

The proposed system uses IoT technology and an ESP32 microcontroller to monitor temperature, humidity, and gas levels continuously.

A DHT22 sensor measures temperature and humidity, while an MQ-2 gas sensor detects changes in gas and smoke levels.

The ESP32 processes the sensor readings and compares them against predefined safety thresholds.

If the gas level exceeds 1500 ADC units or the temperature exceeds 40°C, the system activates a buzzer and red LED to indicate a potential danger condition.

A 16x2 I2C LCD displays the sensor readings and current safety status.

Additionally, sensor readings are uploaded to ThingSpeak every 20 seconds through Wi-Fi for cloud-based monitoring and visualization.

## ✨ Features Implemented

### 🌡️ 1. Temperature and Humidity Monitoring

The project uses a DHT22 digital sensor to monitor environmental conditions.

Implemented functionality:

- Real-time temperature measurement.
- Humidity measurement.
- Digital sensor communication with ESP32.
- Display of temperature and humidity readings on LCD.

### 🔥 2. Gas Leakage and Smoke Detection

The MQ-2 gas sensor is used to monitor combustible gas and smoke levels.

The sensor is sensitive to gases such as:

- LPG
- Propane
- Hydrogen
- Smoke

Implemented functionality:

- Analog gas sensor readings.
- Continuous gas-level monitoring.
- Comparison with predefined gas threshold.
- Detection of potentially hazardous gas levels.

### 🚨 3. Audio-Visual Alert System

The system provides immediate local alerts whenever a potentially dangerous condition is detected.

Alert components:

- Red LED
- Piezo buzzer

Implemented functionality:

- LED activation during danger conditions.
- Alternating buzzer frequencies.
- Automatic alert deactivation when readings return below the configured thresholds.

**Configured thresholds:**

- Gas level: Greater than 1500 ADC units.
- Temperature: Greater than 40°C.

### 📟 4. LCD-Based Monitoring

A 16x2 I2C LCD is integrated to display environmental readings and system status.

The display provides:

- Temperature readings.
- Humidity readings.
- Gas sensor values.
- SAFE status.
- DANGER status.

### 🌐 5. Wi-Fi Connectivity

The ESP32 connects to the Wokwi-GUEST Wi-Fi network in the simulation environment.

Implemented functionality:

- Wireless network connectivity.
- ESP32 internet communication.
- Connection with the ThingSpeak cloud platform.
- Remote sensor-data transmission.

### ☁️ 6. ThingSpeak Cloud Integration

ThingSpeak is used for cloud-based storage and visualization of environmental sensor data.

The system uploads sensor readings at an interval of 20 seconds.

**ThingSpeak Data Mapping:**

| Field | Description |
|---|---|
| Field 1 | Temperature (°C) |
| Field 2 | Humidity (%) |
| Field 3 | Gas Concentration (ADC units) |

The cloud platform allows sensor readings to be monitored and visualized through graphical representations.

### 🔌 7. Simulation and Hardware Implementation

The project includes simulation and hardware implementation documentation.

The report includes:

- Cisco Packet Tracer simulation.
- Hardware implementation.
- Sensor monitoring output.
- ThingSpeak cloud output.

## 🛠️ Tech Stack

### Programming Languages
- C/C++ (Arduino programming)

### Microcontroller
- ESP32 DevKit V1

### Sensors
- DHT22 Temperature and Humidity Sensor
- MQ-2 Gas Sensor

### Hardware Components
- 16x2 I2C LCD
- Piezo Buzzer
- Red LED
- Resistors
- Connecting wires

### IoT and Cloud Platform
- ThingSpeak
- Wi-Fi
- Wokwi Simulator

### Libraries
- WiFi.h
- LiquidCrystal_I2C
- DHTesp
- ThingSpeak

### Development Environment
- Arduino IDE
- Wokwi
- Cisco Packet Tracer
- Git
- GitHub

```

## ⚙️ Installation & Setup

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/IoT_Fire_Gas_Leakage_Detection.git
```

### 2. Navigate to the Project Directory

```bash
cd IoT_Fire_Gas_Leakage_Detection
```

### 3. Install Arduino IDE

Download and install Arduino IDE from:

https://www.arduino.cc/en/software

### 4. Configure ESP32 Board Support

Install ESP32 board support through the Arduino IDE Boards Manager.

Select the appropriate ESP32 DevKit board.

### 5. Install Required Libraries

Install the following libraries using Arduino IDE Library Manager:

- DHTesp
- LiquidCrystal_I2C
- ThingSpeak

The WiFi library is included with the ESP32 board package.

### 6. Configure ThingSpeak

1. Create an account on ThingSpeak.
2. Create a new ThingSpeak channel.
3. Enable three fields:
   - Temperature
   - Humidity
   - Gas Level
4. Copy your Channel ID.
5. Generate or copy your Write API Key.

Update the following variables in the Arduino source code:

```cpp
unsigned long myChannelNumber = YOUR_CHANNEL_ID;

const char* myWriteAPIKey =
    "YOUR_WRITE_API_KEY";
```

**Important:** Keep your private ThingSpeak API Key out of public GitHub repositories.

### 7. Run the Project

Open the Arduino sketch:

```text
src/fire_gas_alert.ino
```

Connect the ESP32 hardware or configure the equivalent Wokwi simulation.

Upload the program to the ESP32 and open the Serial Monitor at 115200 baud.

Verify that the LCD displays sensor readings and that the alert system activates when the configured thresholds are exceeded.

## 📊 System Workflow

The system follows the workflow below:

**Step 1 – Environmental Data Collection**

The DHT22 sensor measures temperature and humidity, while the MQ-2 sensor monitors gas and smoke levels.

**Step 2 – Data Processing**

The ESP32 receives and processes the sensor readings.

**Step 3 – Threshold Comparison**

The sensor values are compared against predefined safety thresholds.

**Step 4 – Hazard Detection**

If the gas level exceeds 1500 ADC units or the temperature exceeds 40°C, the system identifies a potential danger condition.

**Step 5 – Alert Generation**

The LCD displays DANGER, and the buzzer and red LED generate audio-visual alerts.

**Step 6 – Safe Condition Monitoring**

If neither threshold is exceeded, the system displays SAFE and switches off the alert outputs.

**Step 7 – Cloud Data Transmission**

Temperature, humidity, and gas readings are uploaded to ThingSpeak every 20 seconds.

**Step 8 – Remote Monitoring**

The uploaded information can be viewed and analyzed through the ThingSpeak cloud dashboard.

## 🔬 Sensor and Alert Logic

The project uses two main conditions for identifying potential hazards.

**Gas Detection:**

```cpp
gasValue > GAS_THRESHOLD
```

**Temperature Detection:**

```cpp
data.temperature > TEMP_THRESHOLD
```

**Combined Danger Condition:**

```cpp
bool isDanger =
    (gasValue > GAS_THRESHOLD ||
     data.temperature > TEMP_THRESHOLD);
```

If either condition is satisfied, the `triggerAlarm()` function activates the buzzer and LED.

## 📸 Project Images and Outputs

### 1. Cisco Packet Tracer Simulation

The project report includes the Cisco Packet Tracer simulation.

### 2. Hardware Implementation

The physical implementation demonstrates the integration of the ESP32, sensors, LCD, buzzer, and LED.

### 3. ThingSpeak and Wokwi Output

The simulation and cloud output demonstrate sensor monitoring and remote data visualization.

Refer to the `images/` directory for the project screenshots.

## 🔐 Safety Applications

The project demonstrates how IoT-based environmental monitoring can support safety applications such as:

- Smart Home Safety Monitoring
- Gas Leakage Monitoring
- Industrial Environmental Monitoring
- Fire Hazard Warning Systems
- Laboratory Safety Monitoring
- Connected Building Monitoring

**Note:** This project is an educational prototype. MQ-2 readings are raw ADC values and are not calibrated gas concentrations in ppm. It is not a certified fire alarm or life-safety device and should not replace certified detection equipment.

## 📌 Future Improvements

The following features can be explored in future versions:

- Mobile application integration.
- SMS and email notifications.
- Real-time remote alerts.
- Improved sensor calibration.
- Multiple sensor integration.
- Cloud-based historical data analysis.
- Automatic ventilation system activation.
- Battery backup integration.
- Advanced IoT dashboard.
- Physical deployment in industrial environments.

## 🎓 Learning Outcomes

Through this project, I developed practical knowledge of:

- Internet of Things (IoT) architecture.
- ESP32 microcontroller programming.
- Temperature and humidity sensing.
- Gas leakage detection.
- Analog and digital sensor interfacing.
- LCD interfacing using I2C.
- Wi-Fi communication.
- ThingSpeak cloud integration.
- Real-time environmental monitoring.
- Hardware and software integration.

## 🌍 Real-World Applications

The proposed system demonstrates concepts that can be applied in:

- Smart Homes
- Industrial Safety Systems
- Gas Storage Facilities
- Laboratories
- Smart Buildings
- Manufacturing Units
- Environmental Monitoring Systems

---
## 📬 Contact

**Developer:** Srishti S Rao

**Degree:** B.Tech – Electronics and Computer Science Engineering (AI/ML Specialization)

**Institution:** Christ University (Deemed to be University)

**Location:** Bengaluru, India

- Email: srishtisrao26@gmail.com
- LinkedIn: https://www.linkedin.com/in/srishti-s-rao-b09189316
- GitHub: https://github.com/srishtii26


---

⭐ If you find this project interesting, consider giving the repository a star!

**Developed with a focus on Internet of Things, Embedded Systems, Environmental Monitoring, and Smart Safety Solutions.**
