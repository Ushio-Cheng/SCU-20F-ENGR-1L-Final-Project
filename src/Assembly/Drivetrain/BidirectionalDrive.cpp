#include "BidirectionalDrive.hpp"
#include "Components/MyServo.hpp"
#include "Assembly/Drivetrain/DifferentialDrive.hpp"
#include <Arduino.h>

BidirectionalDrive::BidirectionalDrive(DifferentialDrive* drivetrainFB, DifferentialDrive* drivetrainLR, MyServo* servo, unsigned char servoPosLR, unsigned char servoPosFB){
    this->servo = servo;
    int pos1 = ((int)servoPosLR)+(servoPosLR-servoPosFB)*6;
    int pos2 = ((int)servoPosLR)+(servoPosLR-servoPosFB)*2;
    this->servoActivatedPos1 = pos1>180?180:pos1;
    this->servoActivatedPos2 = pos2>100?100:pos2;
    this->servoActivatedPos3 = servoPosLR;
    this->servoUnactivatedPos = servoPosFB;
    this->drivetrainFB = drivetrainFB;
    this->drivetrainLR = drivetrainLR;
    this->currentDirection = FWD_BACK;
    this->servo->setAngle(this->servoUnactivatedPos);
}

BidirectionalDrive::~BidirectionalDrive(){
}

void BidirectionalDrive::setDirection(DriveDirection direction){
    getCurrentActiveDriveTrain()->setBreakStatus(true);
    getCurrentActiveDriveTrain()->setBreakStatus(false);
    this->currentDirection = direction;
    if (direction==LEFT_RIGHT)
    {
        this->servo->setAngle(servoActivatedPos1);
        delay(100);
        this->servo->setAngle(servoActivatedPos2);
        delay(100);
        this->servo->setAngle(servoActivatedPos3);
    } else {
        this->servo->setAngle(servoUnactivatedPos);
    }
}

DriveDirection BidirectionalDrive::getDirection(){
    return currentDirection;
}

DifferentialDrive* BidirectionalDrive::getCurrentActiveDriveTrain(){
    if (currentDirection==LEFT_RIGHT){
        return drivetrainLR;
    } else {
        return drivetrainFB;
    }
}

