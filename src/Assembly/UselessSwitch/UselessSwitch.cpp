#include <Arduino.h>
#include "Components/Button.hpp"
#include "Components/MyServo.hpp"
#include "UselessSwitch.hpp"
#include "Scheduler/Scheduler.hpp"

void setupEvents(MyServo *servo, Button *theSwitch, int servoPos);

UselessSwitch::UselessSwitch(MyServo *servo, Button *theSwitch, int servoRestPos, int servoActPos)
{
    this->servo = servo;
    this->theSwitch = theSwitch;
    this->servoRestPos = servoRestPos;
    this->servoActPos = servoActPos;
    this->servo->setAngle(servoRestPos);
}

UselessSwitch::~UselessSwitch()
{
}

/**
 * A Periodic Scheduler Task to check condition of the useless switch.  
 * Should execute on every cycle.  
 * @link Scheduler.hpp
 */
class UselessSwitchWatcher : public Task
{
public:
    UselessSwitch *caller;
    UselessSwitchWatcher(UselessSwitch *caller) : Task()
    {
        this->caller = caller;
    }
    virtual bool checkTrigger() final
    {
        return true;
    }
    virtual void execute() final
    {
        caller->update();
    }
};

/**
 * A Task that asychroniously wait for servo to turn the switch off.
 */
class WaitForServoTask : public Task
{
public:
    UselessSwitch *caller;
    WaitForServoTask(UselessSwitch *caller) : Task()
    {
        this->caller = caller;
    }
    virtual bool checkTrigger() final
    {
        return caller->checkServo();
    }
    virtual void execute() final
    {
        caller->reset();
    }
};

void UselessSwitch::update()
{
    if (!this->theSwitch->isDown())
    {
        UselessSwitchWatcher *watcher = new UselessSwitchWatcher(this);
        getGlobalScheduler()->scheduleGlobalEvent(watcher);
    }
    this->servo->setAngle(servoActPos);
    WaitForServoTask *task = new WaitForServoTask(this);
    getGlobalScheduler()->scheduleGlobalEvent(task);
}

bool UselessSwitch::checkServo()
{
    return !theSwitch->isDown();
}

void UselessSwitch::reset()
{
    servo->setAngle(servoRestPos);
    // Reset global scheduler watcher
    getGlobalScheduler()->scheduleGlobalEvent(new UselessSwitchWatcher(this));
}
