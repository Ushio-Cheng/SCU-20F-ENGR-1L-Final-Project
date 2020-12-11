#include "BidirectionalDrive.hpp"
#include "Components/MyServo.hpp"
#include "Assembly/Drivetrain/DifferentialDrive.hpp"
#include <Arduino.h>

BidirectionalDrive::BidirectionalDrive(
    DifferentialDrive *drivetrainFB,
    DifferentialDrive *drivetrainLR,
    MyServo *servo,
    void (*setServoFB)(MyServo *),
    void (*setServoLR)(MyServo *))
{
    this->servo = servo;
    this->setServoLR = setServoLR;
    this->setSetvoFB = setSetvoFB;
    this->drivetrainFB = drivetrainFB;
    this->drivetrainLR = drivetrainLR;
    this->currentDirection = FWD_BACK;
    setSetvoFB(this->servo);
}

void BidirectionalDrive::setDirection(DriveDirection direction)
{
    getCurrentActiveDriveTrain()->setBreakStatus(true);
    getCurrentActiveDriveTrain()->setBreakStatus(false);
    this->currentDirection = direction;
    if (direction == LEFT_RIGHT)
    {
        setServoLR(servo);
    }
    else
    {
        setSetvoFB(servo);
    }
}

DriveDirection BidirectionalDrive::getDirection()
{
    return currentDirection;
}

DifferentialDrive *BidirectionalDrive::getCurrentActiveDriveTrain()
{
    if (currentDirection == LEFT_RIGHT)
    {
        return drivetrainLR;
    }
    else
    {
        return drivetrainFB;
    }
}
