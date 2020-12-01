#include "Button.hpp"
#include <Arduino.h>


Button::Button(int pinNum, ButtonType type) {
    this->pinNum = pinNum;
    this->type = type;
    pinMode(pinNum,INPUT);
}

Button::~Button() { }

bool Button::isDown(){
    switch (this->type)
    {
    case PullUP:
        return !(digitalRead(pinNum)==HIGH);
    case PullDOWN:
        return digitalRead(pinNum)==HIGH;
    default:
        return false; // ERROR // Unreachable
    }
}

ButtonState Button::getButtonState(){
    if (isDown()) return DOWN;
    else return UP;
}
