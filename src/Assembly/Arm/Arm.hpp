#ifndef ARM_HPP
#define ARM_HPP

class Motor;
class Button;

class Arm {
private:
    Motor *motor;
    Button *limitSw1;
    Button *limitSw2;

public:
    Arm(Motor *motor, Button *LimitSwLower, Button *LimitSwHigher);
    ~Arm();
    /**
     * Raise Arm
     * WARNING: expect delay on synchronized call
     */
    void raise();
    /**
     * Lower Arm
     * WARNING: expect delay on synchronized call
     */
    void lower();
    /**
     * Yeet things (try to)
     * would raise arm and then wait for 1s and then lower it.
     * WARNING: expect delay on synchronized call
     */
    void yeet();
};

#endif