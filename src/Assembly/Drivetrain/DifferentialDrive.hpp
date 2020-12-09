#ifndef DIFFERENTIAL_DRIVE_HPP
#define DIFFERENTIAL_DRIVE_HPP

class Motor;

enum TurnDirection{ Left, Right, None };

class DifferentialDrive
{
private:
    Motor* leftMotor;
    Motor* rightMotor;
    double motorDistance;
    bool breakEnabled = false;
public:
    DifferentialDrive(Motor* leftMotor, Motor* rightMotor, double motorDistance);
    ~DifferentialDrive();
    /*
     * Set Speed and direction
     * @param speed travel speed between 0 and 255
     * @param turn direction
     * @param radius radius of travel
     */
    void setSpeed(unsigned char speed, TurnDirection direction = None, int radius = 100);

    /*
     * Set break
     * REMARK: when break is released speed is set to 0
     * @param applied if true, would set driver pin to 1,1
     */
    void setBreakStatus(bool appplied = true);
};



#endif