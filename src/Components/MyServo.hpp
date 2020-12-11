#ifndef MYSERVO_HPP
#define MYSERVO_HPP

class Servo;

enum ServoDirection
{
    ClockWise,
    CounterClockWise
};

class MyServo
{
private:
    Servo *servo;

public:
    MyServo(int pin);
    ~MyServo();
    /**
     * Set angle of servo, Non-blocking but takes time to actually move.
     * @param degree between 0 to 180 degree.
     * REMARK: would trim input to 0 or 180, whichever closer, if over bound.
     */
    void setAngle(int degree);
    /**
     * read current angle of the servo.
     * @return 0 to 180 in degree
     */
    int getAngle();
    /**
     * set angle of servo by increminting/decreminting
     * @param direction CW->angle decrease, CCW...
     */
    void adjustAngle(int degree, ServoDirection direction);
};

#endif