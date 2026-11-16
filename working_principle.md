# ⚙️ Working Principle – IoT-Based Fire and Gas Leakage Alert System

## 1. Introduction

The IoT-Based Fire and Gas Leakage Alert System is an embedded monitoring system designed to detect potentially hazardous environmental conditions such as gas leakage, smoke, and abnormal temperature increases.

The system uses an ESP32 microcontroller as its central processing unit. It continuously collects environmental data using a DHT22 temperature and humidity sensor and an MQ-2 gas sensor.

The collected sensor readings are processed by the ESP32 and compared with predefined safety thresholds. Whenever a potentially dangerous condition is detected, the system activates a red LED and buzzer to generate immediate audio-visual alerts.

A 16x2 I2C LCD displays real-time sensor readings and the current safety status. Additionally, the ESP32 connects to the internet through Wi-Fi and uploads the collected sensor data to the ThingSpeak cloud platform for remote monitoring and visualization.

The system combines hardware-based monitoring, automated alert generation, and cloud-based data logging to demonstrate an IoT-enabled environmental safety solution.

## 2. Objectives of the System

The main objectives of the proposed system are:

- To continuously monitor environmental temperature and humidity.
- To detect potentially hazardous gas and smoke levels.
- To process sensor readings using the ESP32 microcontroller.
- To identify dangerous conditions using predefined safety thresholds.
- To generate immediate audio-visual alerts using an LED and buzzer.
- To display real-time sensor readings through an LCD.
- To establish Wi-Fi connectivity for remote monitoring.
- To upload environmental data to the ThingSpeak cloud platform.

## 3. System Architecture

The system consists of multiple hardware and software components connected through the ESP32 microcontroller.

The ESP32 acts as the central controller responsible for collecting sensor data, processing readings, controlling output devices, and communicating with the cloud platform.

### Main Components

**1. ESP32 DevKit V1**

The ESP32 is the main microcontroller used in the project.

Its responsibilities include:

- Reading sensor values.
- Processing temperature and humidity data.
- Reading analog gas sensor values.
- Comparing readings with predefined thresholds.
- Controlling the LCD display.
- Activating the LED and buzzer.
- Establishing Wi-Fi connectivity.
- Uploading sensor data to ThingSpeak.

**2. DHT22 Temperature and Humidity Sensor**

The DHT22 is used to measure the surrounding temperature and relative humidity.

It provides digital sensor readings to the ESP32 through GPIO 15.

The measured temperature is used for hazard detection, while temperature and humidity values are displayed on the LCD and uploaded to ThingSpeak.

**3. MQ-2 Gas Sensor**

The MQ-2 sensor is used to detect the presence of combustible gases and smoke.

It is sensitive to gases such as:

- LPG
- Propane
- Hydrogen
- Smoke

The analog output of the sensor is connected to GPIO 34 of the ESP32.

The ESP32 reads the analog signal and compares the resulting ADC value with the predefined gas threshold.

**4. 16x2 I2C LCD Display**

The LCD is used to display real-time environmental readings and the system's safety condition.

It displays:

- Temperature
- Humidity
- Gas sensor readings
- SAFE status
- DANGER status

**5. Red LED**

The red LED provides a visual warning whenever a potentially dangerous condition is detected.

It is connected to GPIO 19 through a current-limiting resistor.

**6. Piezo Buzzer**

The buzzer provides an audible warning when the system detects a dangerous condition.

It is connected to GPIO 18 and generates alternating sound frequencies during an alert.

**7. ThingSpeak Cloud Platform**

ThingSpeak is used for cloud-based data storage and visualization.

The ESP32 uploads temperature, humidity, and gas sensor readings to the configured ThingSpeak channel through Wi-Fi.

## 4. Hardware Connections and Pin Mapping

The ESP32 is connected to the different sensors and output components using the following pin configuration.

| Component | ESP32 Pin | Function |
|---|---|---|
| DHT22 | GPIO 15 | Temperature and humidity data |
| MQ-2 | GPIO 34 | Analog gas sensor input |
| LCD SDA | GPIO 21 | I2C data |
| LCD SCL | GPIO 22 | I2C clock |
| Buzzer | GPIO 18 | Audio alert |
| Red LED | GPIO 19 | Visual alert |

All components share a common ground connection.

The LED is connected through a suitable resistor to limit current.

The MQ-2 module's output voltage must be checked to ensure that it does not exceed the ESP32 input voltage limits.

## 5. Step-by-Step Working Principle

### Step 1: System Initialization

When the ESP32 is powered on, the program begins executing the setup() function.

During initialization:

- Serial communication is started at 115200 baud.
- The buzzer pin is configured as an output.
- The LED pin is configured as an output.
- The MQ-2 sensor pin is configured as an input.
- The LCD display is initialized.
- The LCD backlight is enabled.
- The DHT22 sensor is configured.

The LCD initially displays a Wi-Fi connection message.

This initialization prepares the ESP32 and connected components for continuous monitoring.

### Step 2: Wi-Fi Connection

After initializing the hardware components, the ESP32 attempts to connect to the configured Wi-Fi network.

The project uses the Wokwi-GUEST network for simulation.

The program continuously checks the Wi-Fi connection status until a connection is established.

Once connected, the ESP32 initializes the ThingSpeak client using the WiFiClient object.

The LCD then displays:

**System Online**

This indicates that the system has completed its initialization process.

### Step 3: Temperature and Humidity Monitoring

The DHT22 sensor continuously provides temperature and humidity readings.

The ESP32 retrieves these values using the DHTesp library.

The collected values are stored in a TempAndHumidity data structure.

The temperature reading is used to identify abnormal temperature conditions.

The humidity reading is displayed on the LCD and uploaded to ThingSpeak for remote monitoring.

### Step 4: Gas Leakage Detection

The MQ-2 gas sensor continuously monitors the surrounding environment for combustible gases and smoke.

Its analog output is connected to GPIO 34 of the ESP32.

The ESP32 reads the analog value using the analogRead() function.

The resulting value is stored in the variable gasValue.

The gas sensor reading is compared with a predefined threshold to determine whether the detected level should trigger an alert.

In this implementation, the gas reading is represented using raw ADC units rather than calibrated gas concentration in ppm.

### Step 5: Threshold Comparison

After collecting temperature and gas sensor readings, the ESP32 compares the values with predefined safety thresholds.

The project uses the following thresholds:

- Gas Threshold: 1500 ADC units
- Temperature Threshold: 40.0°C

The system uses a logical OR condition.

This means that if either the gas level exceeds its threshold or the temperature exceeds its threshold, the system identifies a potential danger condition.

The implemented logic is:

```cpp
const int GAS_THRESHOLD = 1500;
const float TEMP_THRESHOLD = 40.0;

bool isDanger =
    (gasValue > GAS_THRESHOLD ||
     data.temperature > TEMP_THRESHOLD);
```

If either condition becomes true, the system activates the alert mechanism.

Otherwise, the system continues operating in the safe condition.

### Step 6: LCD Display Operation

The LCD provides real-time information about the environmental conditions.

The first row displays temperature and humidity readings.

The second row displays the gas sensor value.

When a dangerous condition is detected, the LCD displays:

**DANGER**

When the readings remain within the configured thresholds, the LCD displays:

**SAFE**

This allows users to understand the current environmental condition without requiring access to a computer or cloud dashboard.

### Step 7: Audio-Visual Alert Generation

Whenever the system detects a potentially dangerous condition, the ESP32 calls the triggerAlarm() function.

This function activates the red LED and buzzer.

The alert mechanism works in the following sequence:

1. The red LED turns ON.
2. The buzzer generates a 1000 Hz sound.
3. The system waits for 150 milliseconds.
4. The red LED turns OFF.
5. The buzzer frequency changes to 600 Hz.
6. The system waits for another 150 milliseconds.

This alternating pattern creates a siren-like warning.

The alert continues as long as the system detects a danger condition.

### Step 8: Safe Condition Operation

When neither the gas nor temperature threshold is exceeded, the system enters the safe condition.

During this condition:

- The LCD displays SAFE.
- The red LED remains OFF.
- The buzzer is switched OFF.
- Sensor monitoring continues.

The ESP32 continuously checks new sensor readings to identify any changes in environmental conditions.

### Step 9: Cloud Data Transmission Using ThingSpeak

The project integrates the ThingSpeak cloud platform to store and visualize environmental sensor readings.

The ESP32 connects to ThingSpeak through its Wi-Fi connection.

The system uploads sensor readings at an interval of 20 seconds.

The cloud data is organized into three fields:

| ThingSpeak Field | Sensor Information |
|---|---|
| Field 1 | Temperature (°C) |
| Field 2 | Humidity (%) |
| Field 3 | Gas Sensor Reading (ADC units) |

The program uses the following functions:

- ThingSpeak.setField() to assign sensor values to the corresponding fields.
- ThingSpeak.writeFields() to upload the collected data to the ThingSpeak channel.

After sending the data, the ESP32 checks the HTTP response code.

If the response code is 200, the upload is considered successful.

Otherwise, an error message is displayed in the Serial Monitor.

### Step 10: Continuous Monitoring

After completing the sensor reading, threshold comparison, alert generation, and cloud data transmission operations, the ESP32 repeats the process continuously.

This allows the system to monitor environmental conditions in real time and respond whenever potentially dangerous conditions are detected.

## 6. Software Components and Functions

The project uses several Arduino functions and libraries to perform its operations.

| Function / Library | Purpose |
|---|---|
| WiFi.h | Establishes Wi-Fi connectivity |
| LiquidCrystal_I2C.h | Controls the LCD display |
| DHTesp.h | Reads DHT22 sensor data |
| ThingSpeak.h | Uploads sensor data to the cloud |
| setup() | Initializes the system components |
| loop() | Executes continuous monitoring |
| analogRead() | Reads the MQ-2 analog output |
| getTempAndHumidity() | Retrieves temperature and humidity |
| digitalWrite() | Controls LED output |
| tone() | Generates buzzer frequencies |
| noTone() | Stops the buzzer |
| triggerAlarm() | Activates the audio-visual alert |
| millis() | Controls the periodic cloud update interval |
| ThingSpeak.writeFields() | Sends sensor data to ThingSpeak |

## 7. Overall System Workflow

The complete working process can be summarized as follows:

**Step 1:** Power ON the ESP32 microcontroller.

**Step 2:** Initialize the sensors, LCD, LED, and buzzer.

**Step 3:** Connect the ESP32 to the Wi-Fi network.

**Step 4:** Initialize the ThingSpeak cloud connection.

**Step 5:** Collect temperature and humidity readings using the DHT22 sensor.

**Step 6:** Collect gas sensor readings using the MQ-2 sensor.

**Step 7:** Compare the collected readings against the configured thresholds.

**Step 8:** If a dangerous condition is detected, activate the LED and buzzer.

**Step 9:** Display the current sensor readings and safety status on the LCD.

**Step 10:** Upload temperature, humidity, and gas readings to ThingSpeak every 20 seconds.

**Step 11:** Repeat the monitoring process continuously.

## 8. Expected System Behaviour

The system responds differently depending on the collected sensor readings.

| Condition | LCD Display | LED | Buzzer |
|---|---|---|---|
| Normal temperature and gas level | SAFE | OFF | OFF |
| Gas reading above threshold | DANGER | Blinking | Active |
| Temperature above threshold | DANGER | Blinking | Active |
| Both thresholds exceeded | DANGER | Blinking | Active |

Regardless of the local safety condition, the system continues its periodic cloud data upload operation.

## 9. Simulation and Hardware Implementation

The project demonstrates the integration of the ESP32 microcontroller with environmental sensors and output devices.

The hardware implementation consists of:

- ESP32 development board.
- DHT22 temperature and humidity sensor.
- MQ-2 gas sensor.
- 16x2 I2C LCD.
- Red LED.
- Piezo buzzer.
- Breadboard.
- Jumper wires.

The project also uses Wokwi for the simulated Wi-Fi environment and ThingSpeak for cloud-based data monitoring.

The LCD displays the current temperature, humidity, and gas sensor values, while the LED and buzzer provide local warnings during potential danger conditions.

## 10. Limitations and Safety Considerations

Although the system demonstrates real-time environmental monitoring and alert generation, certain limitations must be considered.

- The MQ-2 sensor readings are raw ADC values and are not calibrated gas concentration measurements in ppm.
- The sensor requires suitable warm-up and calibration for reliable operation.
- The configured thresholds are demonstration values and may need adjustment according to the application.
- The system depends on Wi-Fi connectivity for cloud-based data transmission.
- The current program waits indefinitely for Wi-Fi connection during initialization if the network is unavailable.
- The alert function uses delay() calls, which temporarily block other program operations.

This project is an educational prototype and should not replace certified fire alarms, gas detectors, or professional safety systems.

## 11. Conclusion

The IoT-Based Fire and Gas Leakage Alert System demonstrates how Internet of Things technology can be used to develop an automated environmental monitoring solution.

The ESP32 microcontroller collects temperature, humidity, and gas sensor readings and processes them to identify potentially dangerous conditions.

The LCD provides real-time information, while the buzzer and LED generate immediate local alerts whenever the configured safety thresholds are exceeded.

The integration of the ThingSpeak cloud platform enables remote monitoring and visualization of environmental sensor data.

Overall, the project successfully demonstrates the integration of embedded systems, sensor interfacing, Wi-Fi communication, automated alert generation, and cloud-based IoT monitoring for an educational safety application.

