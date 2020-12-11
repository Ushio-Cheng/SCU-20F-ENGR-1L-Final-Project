#ifndef BIDIRECTIONAL_DRIVE_HPP
#define BIDIRECTIONAL_DRIVE_HPP

class MyServo;
class DifferentialDrive;

/**
 * Direction selection of bi-directional drivetrain
 */
enum DriveDirection
{
    FWD_BACK,
    LEFT_RIGHT
};

/**
 * Bi-Directional Drivetrain, use a servo as the switcher.
 */
class BidirectionalDrive
{
private:
    /**
     * servo used to switch the Drive direction
     */
    MyServo *servo;
    void (*setSetvoFB)(MyServo *);
    void (*setServoLR)(MyServo *);
    DifferentialDrive *drivetrainFB;
    DifferentialDrive *drivetrainLR;
    DriveDirection currentDirection;

public:
    /**
     * Default Constructor
     * @param drivetrainFB drivetrain that moves front-back
     * @param drivetrainLR drivetrain that moves left-right
     * @param servo pointer to servo used to switch the Drive Direction
     * @param setServoFB functino pointer to set the servo to fwd/back position
     * @param setServoLR function pointer to set the servo to left/right position
     * REMARK: Use function pointer to allow tweaking of servo behavior.
     */
    BidirectionalDrive(
        DifferentialDrive *drivetrainFB,
        DifferentialDrive *drivetrainLR,
        MyServo *servo,
        void (*setServoFB)(MyServo *),
        void (*setServoLR)(MyServo *));
    ~BidirectionalDrive() {}
    void setDirection(DriveDirection direction);
    DriveDirection getDirection();
    DifferentialDrive *getCurrentActiveDriveTrain();
};

#endif