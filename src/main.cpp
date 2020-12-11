#include <Arduino.h>
#include "Scheduler/Scheduler.hpp"
#include "Assembly/Drivetrain/BidirectionalDrive.hpp"
#include "Assembly/Drivetrain/DifferentialDrive.hpp"
#include "Assembly/Arm/Arm.hpp"
#include "Assembly/EmojiDisplay/EmojiDisplay.hpp"
#include "Assembly/UselessSwitch/UselessSwitch.hpp"
#include "Components/Button.hpp"
#include "Components/Motor.hpp"
#include "Components/MyServo.hpp"
#include "Components/DistanceSensor.hpp"

/*
 * Initialize all components
 * - The one with JavaDocs are the ones that is intended to be 
 *      called, while the other ones are mostly intermediatory
 * - IDE (I use VSC+PlatformIO) suggested for intellisense and parameter lookup
 * - As of C++ Convention, most commenting is done as JavaDoc in hpp files.
 */

MyServo drivetrainServo = MyServo(5);
Motor motorXL = Motor(6, 7);
Motor motorXR = Motor(8, 9);
Motor motorZL = Motor(10, 11);
Motor motorZR = Motor(12, 13);
DifferentialDrive driveFW = DifferentialDrive(&motorXL, &motorXR, 11);
DifferentialDrive driveLR = DifferentialDrive(&motorZL, &motorZR, 9.5);
/**
 * Main Drivetrain Abstraction
 */
BidirectionalDrive drivetrain = BidirectionalDrive(
                                    &driveFW, 
                                    &driveLR, 
                                    &drivetrainServo, 
                                    // Set Servo to more FWD/BACK
                                    [](MyServo* servo)->void{
                                        servo->setAngle(0);
                                    },
                                    // Set Servo to move Left/Right
                                    [](MyServo* servo)->void{
                                        // Set the servo over the angle needed to gain more troque and 
                                        // then set it to the correct value to reduce current draw
                                        servo->setAngle(120);
                                        delay(100);
                                        servo->setAngle(80);
                                        delay(100);
                                        servo->setAngle(30);
                                    });
Motor armMotor = Motor(1, 0);
Button armRaisedLimitSw = Button(A3);
Button armLoweredLimitSw = Button(A2);
/**
 * Robotic Arm To Yeet stuff
 */
Arm arm = Arm(&armMotor, &armLoweredLimitSw, &armRaisedLimitSw);
MyServo switchServo = MyServo(A0);
Button theSwitch = Button(A1);
/**
 * Useless Switch assembly
 */
UselessSwitch *uselessSwitch = new UselessSwitch(&switchServo, &theSwitch, 5, 80);
/**
 * Distance sensor
 */
DistanceSensor *distanceSensor = new DistanceSensor(4);

/**
 * This is one of the most complicated part of this project,
 * a good understanding of the framework is almost necessary to
 * understand the code here.
 * 
 * So, because arduino is single core, multi-threading is not a thing.
 * However, servo movement and particularly arm movement (since it involves
 *     waiting for the limit switch to trigger) takes a long time. And if
 *     no multi-threading is implemented then other real-time events cannot
 *     be handled until the current task is done.
 * Therefore, a pusedo-multi-thread mechanism is implemented here. It is 
 *     similar to how a CPU in a computer would work (Intel call it Hyper Threading)
 * Basically, the execution flow never "leaves" (technically it does) the main
 *     loop in a sense that the main loop never calls time consuming tasks, defined
 *     as taking more then 500ms, but instead break them down to managable tasks
 *     and load into scheduler, which executes all task asynchroniously.
 * For example, for the robotic arm to move up, normally it would set the motor to
 *     move up and wait for the limit switch to trigger. In this case, it is breaked
 *     up into 2 part, 
 *          "tell the motor to move up" and 
 *          "stop the motor when limit switch triggered"
 *     and would be represented by code as
 *          "execute immediately: tell the motor to move up"
 *          "execute when limit switch triggered: stop the motor"
 * Check out Scheduler/Scheduler.hpp to learn more about how I am implementing it.
 * Read about class Task in Scheduler.hpp to learn how task is constructed.
 */

/**
 * Drivetrain Control event
 * Exist so that it can randomly running around and doing other things at the same time.
 */
class DrivetrainEvent : public Task
{
public:
    BidirectionalDrive *caller;
    DrivetrainEvent(BidirectionalDrive *caller) : Task()
    {
        this->caller = caller;
    }
    virtual bool checkTrigger() final
    {
        // Random commented out since not work very well for demo.
        // return random(1,40)==1;
        return true; // Would execute on next clock cycle
    }
    virtual void execute() final
    {
        // Random commented out since not work very well for demo.
        // TODO: treaking parameter
        // DriveDirection direction = random(1,2)==1?LEFT_RIGHT:FWD_BACK;
        // caller->setDirection(direction);
        // caller->getCurrentActiveDriveTrain()->setSpeed(random(0,255),random(0,1)==1?None:Left);
        caller->setDirection(FWD_BACK);
        caller->getCurrentActiveDriveTrain()->setSpeed(255);
        // Put a new task into scheduler
        // REMARK: cannot just use this pointer since when a task is finished it would be disposed by scheduler
        getGlobalScheduler()->scheduleGlobalEvent(new DrivetrainEvent(caller));
    }
};

/**
 * Arm Control Event
 * Executed when there is something in front(<5cm)
 * Would Yeet the thing use the front arm and then reset and put the task back into scheduler
 */
class ArmWatcher : public Task
{
public:
    Arm *arm;
    DistanceSensor *sensor;
    ArmWatcher(Arm *arm, DistanceSensor *sensor) : Task()
    {
        this->arm = arm;
        this->sensor = sensor;
    }
    virtual bool checkTrigger() final
    {
        return sensor->measureDistance() < 5;
    }
    virtual void execute() final
    {
        arm->yeet();
        getGlobalScheduler()->scheduleGlobalEvent(new ArmWatcher(arm, sensor));
    }
};

void setup()
{
    initScheduler();

    showEmoji();
    // Put useless switch to its initial position and add its watcher to scheduler.
    uselessSwitch->reset(); // Must be after initScheduler since this involves putting task into scheduler.

    // Add more tasks.
    getGlobalScheduler()->scheduleGlobalEvent(new DrivetrainEvent(&drivetrain));
    getGlobalScheduler()->scheduleGlobalEvent(new ArmWatcher(&arm, distanceSensor));
}

void loop()
{
    // Hands Execution to Scheduler
    getGlobalScheduler()->schedulerCycle();
    // WARNING: Don't add anything in main loop since that would lower the cycle per time
    //      of the scheduler which would have a great impact on performance.
}