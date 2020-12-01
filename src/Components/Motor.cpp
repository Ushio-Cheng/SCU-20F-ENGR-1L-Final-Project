#include "Motor.hpp"
#include <Arduino.h>

Motor::Motor(int CtrPin1, int CtrPin2, bool reversed = false)
{
    if (!reversed)
    {
        this->CtrPin1 = CtrPin1;
        this->CtrPin2 = CtrPin2;
    }
    else
    {
        this->CtrPin1 = CtrPin2;
        this->CtrPin2 = CtrPin1;
    }
    pinMode(CtrPin1, OUTPUT);
    pinMode(CtrPin2, OUTPUT);
    this->travelInReverse = false;
    this->currentSpeed = 0;
    this->breakEnabled = false;
}

void Motor::setSpeed(unsigned char newSpeed, bool reverse = false)
{
    this->travelInReverse = reverse;
    this->currentSpeed = newSpeed;
    this->breakEnabled = false;
    if (!reverse)
    {
        analogWrite(this->CtrPin1, newSpeed);
        analogWrite(this->CtrPin2, 0);
    }
    else
    {
        analogWrite(this->CtrPin1, 0);
        analogWrite(this->CtrPin2, newSpeed);
    }
}

void Motor::setBreak(bool applied)
{
    if (this->breakEnabled)
    {
        if (applied)
        {
            // do nothing
        }
        else
        {
            analogWrite(this->CtrPin1, 0);
            analogWrite(this->CtrPin2, 0);
            this->travelInReverse = false;
            this->currentSpeed = 0;
            breakEnabled = applied;
        }
    }
    else
    {
        if (applied)
        {
            analogWrite(this->CtrPin1, 255);
            analogWrite(this->CtrPin2, 255);
            this->travelInReverse = false;
            this->currentSpeed = 0;
            breakEnabled = applied;
        }
        else
        {
            // Do Nothing
        }
    }
}