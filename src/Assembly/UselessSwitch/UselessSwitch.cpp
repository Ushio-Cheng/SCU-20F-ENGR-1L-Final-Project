#include <Arduino.h>
#include "Components/Button.hpp"
#include "Components/MyServo.hpp"
#include "UselessSwitch.hpp"
#include "Scheduler/Scheduler.hpp"

void setupEvents(MyServo* servo, Button* theSwitch, int servoPos);

UselessSwitch::UselessSwitch(MyServo* servo, Button* theSwitch, int servoRestPos, int servoActPos) {
    this->servo = servo;
    this->theSwitch = theSwitch;
    this->servoRestPos = servoRestPos;
    this->servoActPos = servoActPos;
    this->servo->setAngle(servoRestPos);
}

UselessSwitch::~UselessSwitch() {
}

class Task1:public Task{
public:
    UselessSwitch* caller;
    Task1(UselessSwitch* caller){
        this->caller = caller;
        this->trigger = []{return true;};
        this->exec = []{};
    }
    virtual bool checkTrigger() final {
        return caller->checkServo();
    }
    virtual void execute() final {
        caller->callback();
    }
};

void UselessSwitch::update(){
    if (!this->theSwitch->isDown()) return;
    this->servo->setAngle(servoActPos);
    Task1* task = new Task1(this);
    getGlobalScheduler()->scheduleGlobalEvent(task);
}


bool UselessSwitch::checkServo(){
    return !theSwitch->isDown();
}

void UselessSwitch::callback(){
    servo->setAngle(servoRestPos);
}
