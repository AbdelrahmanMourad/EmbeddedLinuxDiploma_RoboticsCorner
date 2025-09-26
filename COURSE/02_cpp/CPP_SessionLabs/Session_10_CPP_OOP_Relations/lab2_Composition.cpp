/* Composition */
#include <iostream>

/******************** Composition POINTER {Initialized inside the super class} ******************/
class Button // Sub Class.
{
public:
};

class Window // Super Class.
{
public:
    Window()
    {
        button = new Button();
    }

private:
    Button *button;
};

int main()
{
    return 0;
}
