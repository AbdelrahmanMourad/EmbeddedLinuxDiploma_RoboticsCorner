/*
================================================================================
|   C++ Function Overloading - Study Summary
|-------------------------------------------------------------------------------
| - if two functions of the same name with:
|       * (different parameters dataTypes or different number of parameters)
|           ... They are called Overloaded function
|-------------------------------------------------------------------------------
| - Compiler differ by them by what is called "Name Mangling"
| - Function overloading allows multiple functions with the same name but
|   different parameter lists (number or types).
| - The compiler distinguishes them using "name mangling".
| - Overloading is resolved at compile time (static polymorphism).
| - You cannot overload only by return type.
| - Typical cases:
|     * Different number of parameters
|     * Different parameter types
|     * Different parameter order (types must differ)
================================================================================
*/

// Include Library.
#include <iostream>

// Functions Prototypes and Overloads in Namespace
namespace Calculator
{
    void Welcome(void); // Initialization.

    // Overloading by parameter type
    double Add(double a, double b); // Add two doubles
    int Add(int a, int b);          // Add two ints

    // Overloading by number of parameters
    double Add(double a, double b, double c); // Add three doubles

    // Overloading by parameter order
    double Mix(double a, int b); // double, int
    double Mix(int a, double b); // int, double

    // Other operations
    double Sub(double a, double b);      // Subtract
    double Div(double a, double b);      // Divide
    double Multiply(double a, double b); // Multiply
    double Rem(double a, double b);      // Remainder
}

// Implementations
void Calculator::Welcome(void) { std::cout << "Welcome to Calculator Function Overloading Demo!\n"; }

int Calculator::Add(int a, int b) { return a + b; }
double Calculator::Add(double a, double b) { return a + b; }
double Calculator::Add(double a, double b, double c) { return a + b + c; }

double Calculator::Mix(double a, int b) { return a + b + 0.1; }
double Calculator::Mix(int a, double b) { return a + b + 0.2; }

double Calculator::Sub(double a, double b) { return a - b; }

double Calculator::Div(double a, double b) { return a / b; }

double Calculator::Multiply(double a, double b) { return a * b; }

double Calculator::Rem(double a, double b) { return static_cast<int>(a) % static_cast<int>(b); }

int main()
{
    Calculator::Welcome();

    // Overloading by type
    std::cout << "Add(double, double):\t\t" << Calculator::Add(2.5, 3.5) << std::endl;
    std::cout << "Add(int, int):      \t\t" << Calculator::Add(2, 3) << std::endl;

    // Overloading by number of parameters
    std::cout << "Add(double, double, double):\t" << Calculator::Add(1.1, 2.2, 3.3) << std::endl;

    // Overloading by parameter order
    std::cout << "Mix(double, int):\t" << Calculator::Mix(2.5, 3) << std::endl;
    std::cout << "Mix(int, double):\t" << Calculator::Mix(2, 3.5) << std::endl;

    // Other operations
    std::cout << "Sub:     \t" << Calculator::Sub(10, 4) << std::endl;
    std::cout << "Div:     \t" << Calculator::Div(10, 4) << std::endl;
    std::cout << "Multiply:\t" << Calculator::Multiply(10, 4) << std::endl;
    std::cout << "Rem:     \t" << Calculator::Rem(10, 4) << std::endl;

    return 0;
}