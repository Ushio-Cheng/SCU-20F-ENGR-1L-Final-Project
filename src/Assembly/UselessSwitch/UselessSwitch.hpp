#ifndef USELESS_SWITCH_HPP
#define USELESS_SWITCH_HPP

class MyServo;
class Button;

class UselessSwitch
{
private:
    MyServo* servo;
    Button* theSwitch;
    int servoRestPos;
    int servoActPos;
public:
    UselessSwitch(MyServo* servo, Button* theSwitch, int servoRestPos, int servoActPos);
    ~UselessSwitch();
    /**
     * update method, should be called at each cycle.
     * would turn off switch if it is turned on
     * THREADT: Non-Blocking, would use scheduler.
     */
    void update();
};


#endif