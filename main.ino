#define POWER_LED_PIN 2
#define AUTO_LED_PIN 4
#define AUTO_PIN 5

#define CHANNEL_A_DIRECTION_PIN 12
#define CHANNEL_A_BRAKE_PIN 9
#define CHANNEL_A_PIN 3

#define SPEED_PIN A0

#define AUTO_SPEED 200

void setup() {
    Serial.begin(9600);

    pinMode(POWER_LED_PIN, OUTPUT);
    pinMode(AUTO_LED_PIN, OUTPUT);
    pinMode(AUTO_PIN, INPUT_PULLUP);

    pinMode(CHANNEL_A_DIRECTION_PIN, OUTPUT);
    pinMode(CHANNEL_A_BRAKE_PIN, OUTPUT);

    digitalWrite(POWER_LED_PIN, HIGH);
    digitalWrite(CHANNEL_A_DIRECTION_PIN, HIGH);
    digitalWrite(CHANNEL_A_BRAKE_PIN, LOW);
}

void loop() {
    if(IsAutoMode()) {
        AutoMode();
    } else {
        ManualMode();
    }
}

void AutoMode() {
    digitalWrite(AUTO_LED_PIN, HIGH);
    analogWrite(CHANNEL_A_PIN, AUTO_SPEED);
}

void ManualMode() {
    int rawSpeed = analogRead(SPEED_PIN);
    int speed = map(rawSpeed, 0, 1023, 0, 255);
    Serial.println(speed);

    digitalWrite(AUTO_LED_PIN, LOW);
    analogWrite(CHANNEL_A_PIN, speed);
    delay(100);
}

bool IsAutoMode() {
    return digitalRead(AUTO_PIN) == LOW;
}