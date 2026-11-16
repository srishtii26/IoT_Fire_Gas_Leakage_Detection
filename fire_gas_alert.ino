#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include "DHTesp.h"
#include "ThingSpeak.h"

// Sensor and output pins
const int DHT_PIN = 15;
const int MQ2_PIN = 34;
const int BUZZER_PIN = 18;
const int LED_PIN = 19;

// Alert thresholds
const int GAS_THRESHOLD = 1500;
const float TEMP_THRESHOLD = 40.0;

// Wi-Fi credentials (Wokwi simulation network)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingSpeak credentials: add your own values here.
// Never commit private API keys to a public GitHub repository.
unsigned long myChannelNumber = 0;
const char* myWriteAPIKey = "YOUR_THINGSPEAK_WRITE_API_KEY";

WiFiClient client;
DHTesp dhtSensor;
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long lastTime = 0;
const unsigned long timerDelay = 20000; // ThingSpeak update interval

void triggerAlarm();

void setup() {
    Serial.begin(115200);

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(MQ2_PIN, INPUT);

    lcd.init();
    lcd.backlight();

    dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

    lcd.setCursor(0, 0);
    lcd.print("WiFi Connecting");

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected");

    ThingSpeak.begin(client);

    lcd.clear();
    lcd.print("System Online");
    delay(1000);
}

void loop() {
    TempAndHumidity data = dhtSensor.getTempAndHumidity();
    int gasValue = analogRead(MQ2_PIN);

    bool isDanger =
        (gasValue > GAS_THRESHOLD || data.temperature > TEMP_THRESHOLD);

    // Display temperature and humidity
    lcd.setCursor(0, 0);
    lcd.print("T:" + String(data.temperature, 0) + "C H:" +
              String(data.humidity, 0) + "%   ");

    // Display gas value and current safety state
    lcd.setCursor(0, 1);
    lcd.print("G:" + String(gasValue) + "       ");

    if (isDanger) {
        lcd.setCursor(8, 1);
        lcd.print("!DANGER!");
        triggerAlarm();
    } else {
        lcd.setCursor(8, 1);
        lcd.print(" SAFE   ");
        digitalWrite(LED_PIN, LOW);
        noTone(BUZZER_PIN);
    }

    // Send readings to ThingSpeak every 20 seconds
    if (millis() - lastTime >= timerDelay) {
        ThingSpeak.setField(1, data.temperature);
        ThingSpeak.setField(2, data.humidity);
        ThingSpeak.setField(3, gasValue);

        int response = ThingSpeak.writeFields(
            myChannelNumber, myWriteAPIKey
        );

        if (response == 200) {
            Serial.println("ThingSpeak update successful");
        } else {
            Serial.println("ThingSpeak HTTP error: " + String(response));
        }

        lastTime = millis();
    }

    delay(200);
}

void triggerAlarm() {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    delay(150);

    digitalWrite(LED_PIN, LOW);
    tone(BUZZER_PIN, 600);
    delay(150);
}
