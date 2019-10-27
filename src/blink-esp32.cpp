#include <Arduino.h>

int ledPin = 2;

bool ledStatus = false;

int del = 500;

int globalVariable = 0;

void showLED(int pin, int delayPeriod, bool ledStatus) {
    int functionVariable = 0;

    if (ledStatus)
        digitalWrite(pin, HIGH);
    else
        digitalWrite(pin, LOW);

    delay(delayPeriod);

    functionVariable++;
    Serial.printf("functionVariable: %d\n", functionVariable);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Start");

    pinMode(ledPin, OUTPUT);
}

void loop() {
    int localVariable;

    showLED(ledPin, del, ledStatus);
    ledStatus = !ledStatus;
    showLED(ledPin, del, ledStatus);

    globalVariable++;
    localVariable++;

    Serial.printf("localVariable: %d\n", localVariable);
    Serial.printf("globalVariable: %d\n", globalVariable);
}
