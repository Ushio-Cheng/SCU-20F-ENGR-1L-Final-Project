#ifndef MOTOR_HPP
#define MOTOR_HPP


class Motor{
private:
    int CtrPin1;
    int CtrPin2;
    /*
     * current speed represented between 0 to 255
     * is the speed wanted instead of real speed.
     */
    unsigned char currentSpeed;
    /*
     * Speed Direction
     */
    bool travelInReverse;
    bool breakEnabled;
public:
    Motor(int CtrPin1,int CtrPin2, bool reversed = false);
    void setSpeed(unsigned char newSpeed, bool reverse = false);
    short int getSpeed(){ return currentSpeed; }
    void setBreak(bool applied);
};

#endif