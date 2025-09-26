/*  =============================================================================================
                                Header Guard File
    =============================================================================================   */
#ifndef _CALCULATOR_POLYMORPHISM_
#define _CALCULATOR_POLYMORPHISM_

/*  =============================================================================================
                                Included Libraries
    =============================================================================================   */
#include <iostream> // For input/output operations
#include <sstream>  // For string streams.
#include <cmath>    // For sin_angle() , cos_angle()
#include <string>   // For handling string input
#include <iomanip>
// #include <cctype>    // For character classification functions like isdigit and isalpha
// #include <stdexcept> // For throwing exceptions when input is invalid

/*  =============================================================================================
                                Declarations / Functions Prototypes
    =============================================================================================   */
// _____Abstract class Calculator_____
class Calculator
{
public:
    // Pure virtual methods:
    virtual void add() = 0;     // Add two numbers.
    virtual void sub() = 0;     // Subtract two numbers.
    virtual void Display() = 0; // Display type of calculator.
    Calculator() { std::cout << "Constructor Called: Abstract Class Claculator\n"; }
    ~Calculator() { std::cout << "Destructor Called: Abstract Class Calculator\n"; }
};

// _____Derived Classes: CalculatorBase / ProgrammerCalculator / ScientificCalculator_____
class CalculatorBase : public Calculator
{
public:
    void add() override
    {
        double x, y;
        std::cout << "Please Enter 2 numbers to add:\t", std::cin >> x >> y;
        std::cout << "Sum= " << (x + y) << std::endl;
    }
    void sub() override
    {
        double x, y;
        std::cout << "Please Enter 2 numbers to sub:\t", std::cin >> x >> y;
        std::cout << "Sub= " << (x - y) << std::endl;
    }
    void Display() override { std::cout << "Basic Calculator operation.\n"; }
};
class ProgrammerCalculator : public CalculatorBase
{
private:
    // Converts a hexadecimal string to its decimal equivalent
    unsigned int Conversion_ManualHexToDecimal(const std::string &hexInput);

public:
    void hexaToDecimal();
    void decimalToHexa();
    void Display() override { std::cout << "Progrmming Calculator Operation.\n"; }
};
class ScientificCalculator : public CalculatorBase
{
public:
    void sin_ang();
    void cos_ang();
    void Display() override { std::cout << "Scientific Calculator Opeartion.\n"; }
};


#endif /*_CALCULATOR_POLYMORPHISM_*/
