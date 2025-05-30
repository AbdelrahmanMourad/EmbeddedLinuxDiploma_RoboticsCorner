// //  Header Guard Condition.
// #ifndef FUNCTIONS_H     // Cons: inside the c/c++ languages, so compiler independent.
// #define FUNCTIONS_H

/*Another way for header guard condition*/
#pragma once            // Backdraw: Compiler Dependent.

// Fuunctions ProtoTypes.
namespace Calculator
{
    void Welcome(void);                  // Initialization.
    double Add(double a, double b);      // Add.
    double Sub(double a, double b);      // Sub.
    double Div(double a, double b);      // Div.
    double Multiply(double a, double b); // Multiply.
    double Rem(double a, double b);      // Remainder.
}

// #endif /*FUNCTIONS_H*/