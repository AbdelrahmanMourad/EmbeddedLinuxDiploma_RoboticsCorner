/*
===============================================
      Multi-Purpose Calculator System
===============================================

    Requirements:
    This system consists of an abstract base class, `Calculator`, which serves
    as a blueprint for different types of calculators. The following pure
    virtual functions are declared in this class:

    - void add(): Function to add two numbers.
    - void sub(): Function to subtract two numbers.
    - void Display(): Function to display the type of calculator in use.

    Since `Calculator` is an abstract class, it cannot be instantiated directly.
    All derived classes must implement these methods.

-----------------------------------------------
    Abstract Base Class: Calculator
-----------------------------------------------

    - Acts as a blueprint for calculator types.
    - Contains pure virtual methods:
        - add(): Addition functionality.
        - sub(): Subtraction functionality.
        - Display(): Displays the type of calculator.

-----------------------------------------------
    Derived Class: CalculatorBase
-----------------------------------------------

    - Provides basic calculator functionality.
    - Implements:
        - add(): Prompts user for two numbers, then displays their sum.
        - sub(): Prompts user for two numbers, then displays their difference.
        - Display(): Outputs "Basic Calculator operation".

-----------------------------------------------
    Derived Class: ProgrammerCalculator
-----------------------------------------------

    - Extends `CalculatorBase` with programmer-specific functions.
    - Implements:
        - hexaToDecimal(): Converts a hexadecimal number (string input) to decimal.
        - decimalToHexa(): Converts a decimal number to hexadecimal.
        - Display(): Outputs "Programming Calculator operation".

-----------------------------------------------
    Derived Class: ScientificCalculator
-----------------------------------------------

    - Extends `CalculatorBase` with scientific calculations.
    - Implements:
        - sin_ang(): Takes input angle in degrees and calculates its sine.
        - cos_ang(): Takes input angle in degrees and calculates its cosine.
        - Display(): Outputs "Scientific Calculator operation".

-----------------------------------------------
    Program Structure:
-----------------------------------------------

    In `main()`, the user selects a calculator type:

    - Basic Calculator ('C')
    - Scientific Calculator ('S')
    - Programmer Calculator ('P')
    - Exit ('E')

    Based on user choice, a calculator is instantiated using
    a base class pointer (`CalculatorBase *Cal`).

    Then, the user selects operations depending on the calculator type:

    - Basic Calculator:
        - 'S': Subtract two numbers.
        - 'A': Add two numbers.

    - Scientific Calculator:
        - 'S': Calculate sine of an angle.
        - 'C': Calculate cosine of an angle.

    - Programmer Calculator:
        - 'H': Convert hexadecimal to decimal.
        - 'D': Convert decimal to hexadecimal.

    If an invalid choice is made, the user is given up to 3 attempts before
    the program exits.

===============================================
*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <cmath>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
// ___ABSTRACT BASE CLASS___
class Calculator
{
public:
    virtual void add() = 0;           // Addition functionality.
    virtual void sub() = 0;           // Subtraction functionality
    virtual void Display() const = 0; // Display the type of calculator.
    Calculator() { std::cout << "Constructor Called: Calculator.\n"; }
    ~Calculator() { std::cout << "Desstructor Called: Calculator.\n"; }
};

class CalculatorBase : public Calculator
{
public:
    void add() override;
    void sub() override;
    void Display() const override { std::cout << "CalculatorBase:: Basic Calculator Operation.\n"; }
    CalculatorBase() { std::cout << "Constructor Called: CalculatorBase\n"; }
    ~CalculatorBase() { std::cout << "Destructor Called: CalculatorBase\n"; }
};

class ProgrammerCalculator : public CalculatorBase
{
public:
    void hexaToDecimal();
    void decimalToHexa();
    void Display() const override { std::cout << "ProgrammingCalculator:: Programmer Calculator operation.\n"; }
    ProgrammerCalculator() { std::cout << "Constructor Called: ProgrammerCalculator.\n"; }
    ~ProgrammerCalculator() { std::cout << "Destructor Called: ProgrammerCalculator.\n"; }
};

class ScientificCalculator : public CalculatorBase
{
private:
    double PI = 3.14;

public:
    void sin_ang();
    void cos_ang();
    void Display() const override { std::cout << "ScientificCalculator:: Scientific Calculator operation.\n"; }
    ScientificCalculator() { std::cout << "Constructor Called: ScientificCalculator.\n"; }
    ~ScientificCalculator() { std::cout << "Destructor Called: ScientificCalculator.\n"; }
};

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    char user_selection;
    std::cout << "------------------------------\n"
              << "Welcome to Calculator Program\n"
              << "------------------------------\n";
    std::cout << "Select Calculator Type:\n"
              << "\t- Basic Calculator ('C')\n"
              << "\t- Scientific Calculator ('S')\n"
              << "\t- Programmer Calculator ('P')\n"
              << "\t- Exit ('E')\n";
    std::cin >> user_selection;
    switch (user_selection)
    {
    case 'C':
        break;
    case 'S':
        break;
    case 'P':
        break;
    case 'E':
        break;
    default:
        break;
    }

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
void CalculatorBase::add()
{
    // add(): Prompts user for two numbers, then displays their sum.
    double a, b;
    std::cout << "CalculatorBase:: Please enter add parameters: n1, n2:";
    std::cin >> a >> b;
    std::cout << "Calculator Base:/tSum= " << a + b << std::endl;
}
void CalculatorBase::sub()
{
    // sub(): Prompts user for two numbers, then displays their difference.
    double a, b;
    std::cout << "CalculatorBase:: Please enter sub parameters: n1, n2:";
    std::cin >> a >> b;
    std::cout << "Calculator Base:/tSum= " << a - b << std::endl;
}

void ProgrammerCalculator::hexaToDecimal()
{
    std::string input_hexa_string;
    std::cout << "to convert HexaToDecimal()... Enter the hexa number:\t";
    std::cin >> input_hexa_string;
    // Conversion steps.
}
void ProgrammerCalculator::decimalToHexa()
{
    std::string input_decimal_string;
    std::cout << "to convert decimalToHexa()... Enter the decimal number:\t";
    std::cin >> input_decimal_string;
    // Conversion Steps.
}

void ScientificCalculator::sin_ang()
{
    // Takes input angle in degrees and calculates its sine.
    double angle_degree;
    std::cout << "to get sin()... Enter angle in degrees: ";
    std::cin >> angle_degree;
    std::cout << "sin(" << angle_degree << ") = " << /*cmath*/ sin(angle_degree * PI / 180.0) << std::endl;
}

void ScientificCalculator::cos_ang()
{
    // Takes input angle in degrees and calculates its cosine
    double angle_degree;
    std::cout << "to get cos()... Enter angle in degrees: ";
    std::cin >> angle_degree;
    std::cout << "cos(" << angle_degree << ") = " << /*cmath*/ cos(angle_degree * PI / 180.0) << std::endl;
}