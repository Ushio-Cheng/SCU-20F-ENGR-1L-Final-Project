#include <Arduino.h>
#include <Servo.h>
#include "MyServo.hpp"


MyServo::MyServo(int pin){
    this->servo = new Servo;
    this->servo->attach(pin);
}

MyServo::~MyServo() {
    delete this->servo;
}


void MyServo::setAngle(int degree){
    if (degree<0) degree = 0;
    if (degree>180) degree = 180;
    servo->write(degree);
}
int MyServo::getAngle(){
    return servo->read();
}
void MyServo::adjustAngle(int degree, ServoDirection direction){
    int angleWanted; 
    if (direction==ClockWise){
        angleWanted = servo->read()-degree;
    } else {
        angleWanted = servo->read()+degree; 
    }
    setAngle(angleWanted);
}

