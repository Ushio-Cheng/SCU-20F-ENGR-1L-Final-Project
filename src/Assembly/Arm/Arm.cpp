#include "Components/Motor.hpp"
#include "Components/Button.hpp"
#include "Arm.hpp"

Arm::Arm(Motor* motor, Button* LimitSwLower, Button* LimitSwHigher) {
    this->motor = motor;
    this->limitSw1 = LimitSwLower;
    this->limitSw2 = LimitSwHigher;
}

Arm::~Arm() {
}

void Arm::raise(){
    motor->setSpeed(255,false);
    while (!limitSw2->isDown());
    motor->setBreak(true);
    motor->setBreak(false);
}

void Arm::lower(){
    motor->setSpeed(255,true);
    while (!limitSw1->isDown());
    motor->setBreak(true);
    motor->setBreak(false);
}

void Arm::yeet(){
    raise();
    // no need to delay since already breaked.
    lower();
}
