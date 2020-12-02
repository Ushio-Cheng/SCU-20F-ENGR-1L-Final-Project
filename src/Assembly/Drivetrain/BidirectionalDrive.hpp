#ifndef BIDIRECTIONAL_DRIVE_HPP
#define BIDIRECTIONAL_DRIVE_HPP

class MyServo;
class DifferentialDrive;
enum DriveDirection{FWD_BACK,LEFT_RIGHT};

class BidirectionalDrive
{
private:
    MyServo* servo;
    unsigned char servoActivatedPos1;
    unsigned char servoActivatedPos2;
    unsigned char servoActivatedPos3;
    unsigned char servoUnactivatedPos;
    DifferentialDrive* drivetrainFB;
    DifferentialDrive* drivetrainLR;
    DriveDirection currentDirection;
public:
    BidirectionalDrive(DifferentialDrive* drivetrainFB, DifferentialDrive* drivetrainLR, MyServo* servo, unsigned char servoPosLR, unsigned char servoPosFB);
    ~BidirectionalDrive();
    void setDirection(DriveDirection direction);
    DriveDirection getDirection();
    DifferentialDrive* getCurrentActiveDriveTrain();
};


#endif