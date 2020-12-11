#ifndef USELESS_SWITCH_HPP
#define USELESS_SWITCH_HPP

class MyServo;
class Button;

class UselessSwitch
{
private:
    /**
     * pointer to servo that controls the arm
     */
    MyServo *servo;
    /**
     * the Useless switch
     */
    Button *theSwitch;
    /**
     * position of the servo that makes it rest under the lid
     */
    int servoRestPos;
    /**
     * position of the servo that can push the button to off position
     */
    int servoActPos;

public:
    /**
     * Default Constructor
     * @param servo pointer to servo that controls the arm
     * @param servoRestPos position of the servo that makes it rest under the lid
     * @param servoActPos position of the servo that can push the button to off position
     * @param theSwitch the useless switch
     */
    UselessSwitch(MyServo *servo, Button *theSwitch, int servoRestPos, int servoActPos);
    ~UselessSwitch();
    /**
     * update method, should be called at each cycle.  
     * would turn off switch if it is turned on
     * REMARK: would determine what task is next, the one that checks again 
     *              or the one that wait for servo to be in place
     * THREADT: Non-Blocking, would use scheduler.
     */
    void update();

    /**
     * This method is only supposed to be called by scheduler task!  
     * Check if the servo is done
     * @return true if the servo is done i.e. the switch is off
     */
    bool checkServo();

    /**
     * Resets Mechanism state  
     * Would do:  
     * 1. move the servo to rest position  
     * 2. add watcher to scheduler
     */
    void reset();
};

#endif