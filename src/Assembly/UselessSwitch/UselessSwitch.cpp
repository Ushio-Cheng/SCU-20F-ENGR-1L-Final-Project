#include <Arduino.h>
#include "Components/Button.hpp"
#include "Components/MyServo.hpp"
#include "UselessSwitch.hpp"
#include "Global.cpp"
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

void UselessSwitch::update(){
    if (!this->theSwitch->isDown()) return;
    this->servo->setAngle(servoActPos);
}

void setupEvents(MyServo* servo, Button* theSwitch, int servoPos){
    G_MAIN_SCHEDULAR.scheduleGlobalEvent(new Task(
        []{return true;},
        []{Serial.begin(9600);}
    ));
    G_MAIN_SCHEDULAR.scheduleGlobalEvent(new Task(
        [theSwitch]()->bool{
            bool tmp = theSwitch->isDown();
            return tmp;
        },
        [=]()->void{ 
            servo->setAngle(servoPos); 
        }
    ));
}