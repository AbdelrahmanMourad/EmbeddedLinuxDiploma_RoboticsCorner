/*  ________________________________Loops__________________________________


    _______________________________________________________________________
*/

// Include Library.
#include <iostream>

void drive(void)
{
    // Drive.
}

int main()
{

    int i{0};

    // Loops. "do, while"
    do
    {
        std::cout << i << std::endl;
        drive();
        i = 30;
    } while (i <= 20);

    i = 0;

    // Loops. "while"
    while (i < 5)
    {
        std::cout << i << std::endl;
        i++;
    }

    // Loops. "for".
    for (i = 0; i <= 10; i++)
    {
    }

    while (1) // Infinity loop.    while(6){} , while(15.5){}
    {
        // Do Something.
    }

    bool Button_Pressed{false};
    for (;;) // Infinity loop.
    {
        // Do Something.
        if (Button_Pressed)
        {
            break;
        }
    }
    return 0;
}
