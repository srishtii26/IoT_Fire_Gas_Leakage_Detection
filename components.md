# Components and Pin Connections

| Component | Purpose | Connection |
|---|---|---|
| ESP32 DevKit V1 | Main controller and Wi-Fi | Main board |
| DHT22 | Temperature and humidity sensing | Data → GPIO 15 |
| MQ-2 | Gas/smoke sensing | AO → GPIO 34 |
| I2C LCD 16x2 | Display sensor values/status | SDA → GPIO 21, SCL → GPIO 22 |
| Piezo buzzer | Audio alert | Signal → GPIO 18 |
| Red LED | Visual alert | Anode → GPIO 19 through resistor |

Connect grounds together. Verify module supply and logic voltage requirements before wiring. The ESP32 ADC input must not receive 5 V.
