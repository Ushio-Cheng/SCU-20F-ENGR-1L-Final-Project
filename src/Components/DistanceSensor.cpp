#include <Arduino.h>
#include "DistanceSensor.hpp"

DistanceSensor::DistanceSensor(int IOPinNum)
{
    this->dataPin = IOPinNum;
}

#define SPEED_OF_SOUND 29 // (ms/cm)

int DistanceSensor::measureDistance()
{
    pinMode(this->dataPin, OUTPUT);
    digitalWrite(this->dataPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->dataPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(this->dataPin, LOW);
    pinMode(this->dataPin, INPUT);
    return pulseIn(this->dataPin, HIGH) / SPEED_OF_SOUND / 2;
}