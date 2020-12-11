#include <Arduino.h>
#include "DifferentialDrive.hpp"
#include "Components/Motor.hpp"

DifferentialDrive::DifferentialDrive(Motor *leftMotor, Motor *rightMotor, double motorDistance)
{
    this->leftMotor = leftMotor;
    this->rightMotor = rightMotor;
    this->motorDistance = motorDistance;
    this->breakEnabled = false;
}

void DifferentialDrive::setSpeed(unsigned char speed, TurnDirection direction, int radius)
{
    // make sure break is released.
    setBreakStatus(false);
    if (direction == None)
    {
        leftMotor->setSpeed(speed);
        rightMotor->setSpeed(speed);
    }
    else
    {
        // The lower speed in differential drive.
        unsigned char lspeed = ((double)speed) * (radius - motorDistance / 2) / (radius + motorDistance / 2);
        // Limit lower speed to range
        if (lspeed < 0)
            lspeed = 0;
        if (lspeed > 255)
            lspeed = 255;
        switch (direction)
        {
        case Left:
            rightMotor->setSpeed(speed);
            leftMotor->setSpeed(lspeed);
            break;
        case Right:
            rightMotor->setSpeed(lspeed);
            leftMotor->setSpeed(speed);
            break;
        case None:
            return; // Unreachable but just to stop the warning
        }
    }
}

void DifferentialDrive::setBreakStatus(bool applied)
{
    leftMotor->setBreak(applied);
    rightMotor->setBreak(applied);
}