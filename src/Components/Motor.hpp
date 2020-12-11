#ifndef MOTOR_HPP
#define MOTOR_HPP

class Motor
{
private:
    int CtrPin1;
    int CtrPin2;
    /**
     * current speed represented between 0 to 255
     * is the speed wanted instead of real speed.
     */
    unsigned char currentSpeed;
    /**
     * Speed Direction
     */
    bool travelInReverse;
    bool breakEnabled;

public:
    Motor(int CtrPin1, int CtrPin2, bool reversed = false);
    /**
     * set current speed represented between 0 to 255
     * is the speed wanted instead of real speed.
     * @param newSpeed 0 to 255 unsigned
     * @param reverse bool, reversed or not
     */
    void setSpeed(unsigned char newSpeed, bool reverse = false);
    /**
     * Get Speed
     * WARNING: the speed get is only expected, not measured by anything.
     * @return from 0 to 255 no direction
     */
    short int getSpeed() { return currentSpeed; }
    /**
     * Set Break
     * would set both control pin high for the breaking provided by driver board.
     * WARNING: cannot be set true for too long since that would draw too much current.
     */
    void setBreak(bool applied);
};

#endif