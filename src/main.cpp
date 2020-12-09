#include <Arduino.h>
// #include "Components/MyServo.hpp"
#include <Servo.h>
#include "Components/Button.hpp"
#include "Assembly/Drivetrain/BidirectionalDrive.hpp"
#include "Assembly/Drivetrain/DifferentialDrive.hpp"
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
Button button = Button(A1);

void setup(){
    
}

void loop(){
    if (button.isDown())  drivetrain.setDirection(LEFT_RIGHT);
    else drivetrain.setDirection(FWD_BACK);
    
    drivetrain.getCurrentActiveDriveTrain()->setSpeed(100);
}