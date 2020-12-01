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
    bool isDown();
    ButtonState getButtonState();
};

#endif