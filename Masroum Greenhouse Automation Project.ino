#define SOIL_SENSOR A0    // Soil Moisture Sensor
#define TEMP_SENSOR A1    // LM35/TMP36 Temperature Sensor

#define RELAY_PUMP 7      // Relay for Water Pump
#define RELAY_FAN 8       // Relay for Fan
#define RELAY_LIGHT 9     // Relay for Light

#define MOISTURE_THRESHOLD 400  // Adjust based on sensor calibration
#define TEMP_THRESHOLD 25       // Temperature limit for Fan (Adjust as needed)

void setup() {
    pinMode(RELAY_PUMP, OUTPUT);
    pinMode(RELAY_FAN, OUTPUT);
    pinMode(RELAY_LIGHT, OUTPUT);

    digitalWrite(RELAY_PUMP, HIGH); // Default OFF
    digitalWrite(RELAY_FAN, HIGH);
    digitalWrite(RELAY_LIGHT, HIGH);

    Serial.begin(9600);
}

void loop() {
    int moistureValue = analogRead(SOIL_SENSOR);
    int tempValue = analogRead(TEMP_SENSOR);

    // Convert LM35/TMP36 Voltage to Temperature
    float temperature = (tempValue * 5.0 / 1024.0) * 100; // LM35: 10mV per °C

    Serial.print("Soil Moisture: ");
    Serial.println(moistureValue);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");

    // Soil Moisture Control
    if (moistureValue < MOISTURE_THRESHOLD) {
        digitalWrite(RELAY_PUMP, LOW); // Turn ON Pump
        Serial.println("Water Pump Activated");
    } else {
        digitalWrite(RELAY_PUMP, HIGH); // Turn OFF Pump
        Serial.println("Water Pump Deactivated");
    }

    // Temperature Control (Fan)
    if (temperature > TEMP_THRESHOLD) {
        digitalWrite(RELAY_FAN, LOW); // Turn ON Fan
        Serial.println("Fan Activated");
    } else {
        digitalWrite(RELAY_FAN, HIGH); // Turn OFF Fan
        Serial.println("Fan Deactivated");
    }

    // Light Control (Optional)
    int lightSensor = analogRead(A2); // Assuming a light sensor is connected to A2
    if (lightSensor < 300) {
        digitalWrite(RELAY_LIGHT, LOW); // Turn ON Light
        Serial.println("Light Activated");
    } else {
        digitalWrite(RELAY_LIGHT, HIGH); // Turn OFF Light
        Serial.println("Light Deactivated");
    }

    delay(2000);  // Delay for stability
}
