/*  ________________________________Functions Overloading______________________________

    if two functions of the same name with (different parameters dataTypes or different number of parameters) ... They are called Overloaded function

    Compiler differ by them by what is called "Name Mangling"

    _______________________________________________________________________
*/

// Include Library.
#include <iostream>

// Fuunctions ProtoTypes.
namespace Calculator
{
    void Welcome(void);                  // Initialization.
    double Add(double a, double b);      // Add.
    double Sub(double a, double b);      // Sub.
    double Div(double a, double b);      // Div.
    double Multiply(double a, double b); // Multiply.
    double Rem(double a, double b);      // Remainder.
    /*************************** Overloading ************************** */
    double Add(int a,int b);

    // // ------
    // // NOTES:
    // // ------
    // // Compiler generated code (name mangling)
    // double add_AX121(double a, double b);
    // double add_Z241(int a, int b);
}

int main()
{


    return 0;
}