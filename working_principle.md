# Working Principle

1. The ESP32 starts serial communication, initializes the LCD and configures the sensors and alert outputs.
2. It connects to the configured Wi-Fi network.
3. The DHT22 provides temperature and humidity data.
4. The ESP32 reads the MQ-2 analog output.
5. It checks whether gas ADC is above 1500 or temperature is above 40 °C.
6. If either condition is met, the LCD indicates danger and the LED/buzzer activate in an alternating pattern.
7. If neither condition is met, the display indicates safe and the alert outputs are disabled.
8. Every 20 seconds, the latest temperature, humidity and gas ADC reading are sent to ThingSpeak.

## Data fields

- Field 1: Temperature in °C
- Field 2: Relative humidity in %
- Field 3: Gas sensor raw ADC reading
