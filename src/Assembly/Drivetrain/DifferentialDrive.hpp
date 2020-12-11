#ifndef DIFFERENTIAL_DRIVE_HPP
#define DIFFERENTIAL_DRIVE_HPP

class Motor;

/**
 * Turn Direction of Differential Drive  
 * Assume wheels are on back.  
 */
enum TurnDirection
{
    Left,
    Right,
    None
};

/**
 * 2-motor differential Drivetrain
 * Utilize Differential Power to turn left or right.
 */
class DifferentialDrive
{
private:
    Motor *leftMotor;
    Motor *rightMotor;
    double motorDistance;
    bool breakEnabled = false;

public:
    /**
     * Default Constructor
     * @param leftMotor pointer to the abstraction of left Motor
     * @param rightMotor pointer to the abstraction of right Motor
     * @param motorDistance distance between the point that wheels contact the ground, used to calculate difference in speed
     */
    DifferentialDrive(Motor *leftMotor, Motor *rightMotor, double motorDistance);
    ~DifferentialDrive() {}
    /**
     * Set Speed and direction
     * @param speed travel speed between 0 and 255
     * @param turn direction
     * @param radius radius of travel
     * REMARK: When turning is enabled, the speed is the speed of the faster side.
     */
    void setSpeed(unsigned char speed, TurnDirection direction = None, int radius = 100);

    /**
     * Set break
     * REMARK: when break is released speed is set to 0
     * @param applied if true, would set driver pin to 1,1
     */
    void setBreakStatus(bool appplied = true);
};

#endif