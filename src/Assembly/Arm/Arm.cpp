#include <Arduino.h>
#include "Components/Motor.hpp"
#include "Components/Button.hpp"
#include "Scheduler/Scheduler.hpp"
#include "Arm.hpp"

Arm::Arm(Motor *motor, Button *LimitSwLower, Button *LimitSwHigher)
{
    this->motor = motor;
    this->limitSw1 = LimitSwLower;
    this->limitSw2 = LimitSwHigher;
}

void Arm::raise()
{
    motor->setSpeed(255, false);
    while (!limitSw2->isDown())
        ; // Wait
    motor->setBreak(true);
    motor->setBreak(false);
}

void Arm::lower()
{
    motor->setSpeed(255, true);
    while (!limitSw1->isDown())
        ; // Wait
    motor->setBreak(true);
    motor->setBreak(false);
}

/**
 * A scheduler task to yeet an object  
 * Composited of 2 parts, raise arm and then lower it.
 * Abstracted to a uniform stricture "Do something with a motor when a switch is triggered."
 */
class TaskYeet : public Task
{
private:
    Motor *armMotor;
    void (*whatToDo)(Motor *motor, Button *limitSwitch1, Button *limitSwitch2);
    Button *limitSwitch1;
    Button *limitSwitch2;
    bool (*howToTrigger)(Button *limit1, Button *limit2);

public:
    TaskYeet(
        Motor *armMotor,
        void (*whatToDO)(Motor *motor, Button *limitSwitch1, Button *limitSwitch2),
        Button *limitSwitch1,
        Button *limitSwitch2,
        bool (*howToTrigger)(Button *limit1, Button *limit2)) : Task()
    {
        this->armMotor = armMotor;
        this->whatToDo = whatToDO;
        this->limitSwitch1 = limitSwitch1;
        this->limitSwitch2 = limitSwitch2;
    }
    virtual bool checkTrigger() final
    {
        return howToTrigger(limitSwitch1, limitSwitch2);
    }
    virtual void execute() final
    {
        whatToDo(armMotor, limitSwitch1, limitSwitch2);
    }
};

void Arm::yeet()
{
    /*
     * Basically did the following
     * 1. tell the arm to move up
     * 2. spawn a event that
     *      2.1 would trigger when upper limit is down
     *      2.2 would stop the motor
     *      2.3 would tell the motor to go down
     *      2.4 would spawn another event that
     *          2.4.1 would trigger when lower limit sw is hit
     *          2.4.2 would stop the motor
     */
    motor->setSpeed(255, false);
    getGlobalScheduler()->scheduleGlobalEvent(
        new TaskYeet(
            motor,
            [](Motor *motor, Button *limitSwitch1, Button *limitSwitch2) -> void {
                motor->setBreak(true);
                delay(50);
                motor->setBreak(false);
                motor->setSpeed(255, true);
                getGlobalScheduler()->scheduleGlobalEvent(
                    new TaskYeet(
                        motor,
                        [](Motor *motor, Button *limitSwitch1, Button *limitSwitch2) -> void {
                            motor->setBreak(true);
                            delay(50);
                            motor->setBreak(false);
                        },
                        limitSwitch1,
                        limitSwitch2,
                        [](Button *ls1, Button *ls2) -> bool {
                            return ls1->isDown();
                        }));
            },
            limitSw1,
            limitSw2,
            [](Button *ls1, Button *ls2) -> bool {
                return ls2->isDown();
            }));
}
