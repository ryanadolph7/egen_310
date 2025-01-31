int red_pin = 9;
int green_pin = 10;
int blue_pin = 11;

void setup() {
    Serial.begin(9600);
    pinMode(red_pin, OUTPUT);
}

void loop() {
    for (int val = 0; val < 256; val++) {
        analogWrite(red_pin, val);
        Serial.print("Wrote ");
        Serial.print(val);
        Serial.println(" to red pin.");
    }
    for (int val = 0; val < 256; val++) {
        analogWrite(green_pin, val);
        Serial.print("Wrote ");
        Serial.print(val);
        Serial.println(" to green pin.");
    }
    for (int val = 0; val < 256; val++) {
        analogWrite(blue_pin, val);
        Serial.print("Wrote ");
        Serial.print(val);
        Serial.println(" to blue pin.");
    }
}
