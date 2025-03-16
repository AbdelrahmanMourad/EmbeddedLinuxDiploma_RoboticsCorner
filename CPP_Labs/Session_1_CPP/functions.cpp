#include "iostream"

namespace Calculator
{
    // Initialization.
    void Welcome(void) // inplementation in ROM,
    {
        std::cout << "Welcome!\n";
    }
    // add
    double Add(double a, double b)
    {
        return a + b;
    }
    // sub
    double Sub(double a, double b)
    {
        return a - b;
    }
    // div
    double Div(double a, double b)
    {
        return a / b;
    }
    // multiply.
    double Multiply(double a, double b)
    {
        return a * b;
    }
    // Remainder.
    double Rem(double a, double b)
    {
        return (int)a % (int)b;
    }
}