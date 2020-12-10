#include <Arduino.h>
#include "Scheduler/Scheduler.hpp"
#include "Components/Button.hpp"
#include "Assembly/Drivetrain/BidirectionalDrive.hpp"
#include "Assembly/Drivetrain/DifferentialDrive.hpp"
#include "Assembly/Arm/Arm.hpp"
#include "Components/Motor.hpp"
#include "Components/MyServo.hpp"
#include "Components/DistanceSensor.hpp"
#include "Assembly/EmojiDisplay/EmojiDisplay.hpp"
#include "Assembly/UselessSwitch/UselessSwitch.hpp"

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
MyServo switchServo = MyServo(A0);
Button theSwitch = Button(A1);
UselessSwitch* uselessSwitch = new UselessSwitch(&switchServo,&theSwitch, 5, 80);
DistanceSensor* distanceSensor = new DistanceSensor(4);

class UselessSwitchWatcher:public Task{
public:
    UselessSwitch* caller;
    UselessSwitchWatcher(UselessSwitch* caller){
        this->caller = caller;
        this->trigger = []{return true;};
        this->exec = []{};
    }
    virtual bool checkTrigger() final {
        return true;
    }
    virtual void execute() final {
        caller->update();
        getGlobalScheduler()->scheduleGlobalEvent(this);
    }
};

class DrivetrainEvent:public Task{
public:
    BidirectionalDrive* caller;
    DrivetrainEvent(BidirectionalDrive* caller){
        this->caller = caller;
        this->trigger = []{return true;};
        this->exec = []{};
    }
    virtual bool checkTrigger() final {
        // return random(1,40)==1;
        return true;
    }
    virtual void execute() final {
        // DriveDirection direction = random(1,2)==1?LEFT_RIGHT:FWD_BACK;
        // caller->setDirection(direction);
        // caller->getCurrentActiveDriveTrain()->setSpeed(random(0,255),random(0,1)==1?None:Left);
        caller->setDirection(FWD_BACK);
        caller->getCurrentActiveDriveTrain()->setSpeed(255);
        getGlobalScheduler()->scheduleGlobalEvent(this);
    }
};



class ArmWatcher:public Task{
public:
    Arm* arm;
    DistanceSensor* sensor;
    ArmWatcher(Arm* arm, DistanceSensor* sensor){
        this->arm = arm;
        this->sensor = sensor;
        this->trigger = []{return true;};
        this->exec = []{};
    }
    virtual bool checkTrigger() final {
        return sensor->measureDistance()<5;
    }
    virtual void execute() final {
        arm->yeet();
        getGlobalScheduler()->scheduleGlobalEvent(this);
    }
};



void setup(){
    initScheduler();
    showEmoji();
    // getGlobalScheduler()->scheduleGlobalEvent(new UselessSwitchWatcher(uselessSwitch));
    // switchServo.setAngle(90);
    getGlobalScheduler()->scheduleGlobalEvent(new DrivetrainEvent(&drivetrain));
    getGlobalScheduler()->scheduleGlobalEvent(new ArmWatcher(&arm,distanceSensor));
}

void loop(){
    getGlobalScheduler()->schedulerCycle();
}