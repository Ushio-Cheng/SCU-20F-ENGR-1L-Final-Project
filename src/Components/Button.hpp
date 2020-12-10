#ifndef BUTTON_CPP
#define BUTTON_CPP

enum ButtonType {PullUP, PullDOWN};
enum ButtonState{UP, DOWN};

class Button
{
private:
    int pinNum;
    ButtonType type;
public:
    /**
     * REMARK: Type defaults to pull-down!!!
     */
    Button(int pinNum, ButtonType type = PullDOWN);
    ~Button();
    /**
     * @return true if the button is pressed down.
     * REMARK: Evaluated on call, non-brocking, take ~5 instruction
     */
    bool isDown();
    /**
     * Beautified Version of isDown();
     * @return emun {UP,DOWN} DOWN if the button is pressed down.
     */
    ButtonState getButtonState();
};

#endif