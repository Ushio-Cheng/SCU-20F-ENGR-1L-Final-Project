#include <Arduino.h>
#include "Global.cpp"
#include "Components/Button.hpp"
#include "Assembly/Drivetrain/BidirectionalDrive.hpp"
#include "Assembly/Drivetrain/DifferentialDrive.hpp"
#include "Assembly/Arm/Arm.hpp"
#include "Components/Motor.hpp"
#include "Components/MyServo.hpp"

MyServo drivetrainServo = MyServo(5);
Motor motorXL = Motor(6,7);
Motor motorXR = Motor(8,9);
Motor motorZL = Motor(10,11);
Motor motorZR = Motor(12,13);
DifferentialDrive driveFW = DifferentialDrive(&motorXL,&motorXR,11);
DifferentialDrive driveLR = DifferentialDrive(&motorZL,&motorZR,9.5);
BidirectionalDrive drivetrain = BidirectionalDrive(&driveFW,&driveLR,&drivetrainServo,30,0);
Motor armMotor = Motor(1,0);
Button armRaisedLimitSw = Button(A3);
Button armLoweredLimitSw = Button(A2);
Arm arm = Arm(&armMotor, &armLoweredLimitSw, &armRaisedLimitSw);




void setup(){
}

void loop(){
    G_MAIN_SCHEDULAR.schedulerCycle();
}