#ifndef MYSERVO_HPP
#define MYSERVO_HPP

class Servo;

enum ServoDirection{ClockWise, CounterClockWise};

class MyServo{
private:
    Servo* servo;
public:
    MyServo(int pin);
    ~MyServo();
    void setAngle(int degree);
    int getAngle();
    /**
     * CW->angle decrease
     */
    void adjustAngle(int degree, ServoDirection direction);
};

#endif