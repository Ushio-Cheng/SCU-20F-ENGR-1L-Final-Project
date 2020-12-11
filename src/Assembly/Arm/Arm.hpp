#ifndef ARM_HPP
#define ARM_HPP

class Motor;
class Button;

class Arm {
private:
    /**
     * Arm Motor
     */
    Motor *motor;
    /**
     * Arm Limit Switch on lower position
     */
    Button *limitSw1;
    /**
     * Arm Limit Switch on higher position
     */
    Button *limitSw2;

public:
    /**
     * Default Constructor
     */
    Arm(Motor *motor, Button *LimitSwLower, Button *LimitSwHigher);
    ~Arm(){}
    /**
     * Raise Arm
     * WARNING: expect delay on synchronized call
     * THREADT: BLOCKING
     */
    void raise();
    /**
     * Lower Arm
     * WARNING: expect delay on synchronized call
     * THREADT: BLOCKING
     */
    void lower();
    /**
     * Yeet things (try to)
     * would raise arm and then wait for 1s and then lower it.
     * THREADT: Non-Blocking
     */
    void yeet();
};

#endif