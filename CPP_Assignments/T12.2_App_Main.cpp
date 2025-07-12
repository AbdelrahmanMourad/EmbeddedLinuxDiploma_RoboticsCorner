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

/*
================================================================================
|   C++ Calculator Polymorphism System - Study Summary
|-------------------------------------------------------------------------------
| Architecture:
| - Abstract Base Class: Calculator
|     * Declares pure virtual functions: add(), sub(), Display()
|     * Cannot be instantiated directly; serves as a blueprint for calculators.
|
| - Derived Class: CalculatorBase
|     * Implements add(), sub(), and Display() for basic arithmetic.
|     * Used as the base for further specialized calculators.
|
| - Derived Class: ProgrammerCalculator (inherits CalculatorBase)
|     * Adds programmer-specific functions:
|         - hexaToDecimal(): Converts hexadecimal string to decimal.
|         - decimalToHexa(): Converts decimal to hexadecimal string.
|     * Uses helper: Conversion_ManualHexToDecimal() for manual conversion.
|     * Overrides Display().
|
| - Derived Class: ScientificCalculator (inherits CalculatorBase)
|     * Adds scientific functions:
|         - sin_ang(): Calculates sine of an angle in degrees.
|         - cos_ang(): Calculates cosine of an angle in degrees.
|     * Overrides Display().
|
| Polymorphism:
| - Enables using a base class pointer (Calculator*) to point to any derived calculator.
| - Allows dynamic selection of calculator type and operation at runtime.
| - Downcasting (dynamic_cast) is used to access derived-only methods.
|
| Key Concepts:
| - Abstract classes and pure virtual functions enforce interface contracts.
| - Inheritance enables code reuse and extension.
| - Polymorphism enables flexible, runtime behavior selection.
|
| Interview Q&A:
| Q1: Why use an abstract base class?
| A1: To define a common interface and enforce implementation in derived classes.
|
| Q2: What is polymorphism and how is it used here?
| A2: Polymorphism allows treating different calculator types uniformly via base pointers,
|     enabling runtime selection and extension.
|
| Q3: Why use dynamic_cast?
| A3: To safely access derived-class-specific methods from a base class pointer.
|
| Q4: What is the difference between CalculatorBase, ProgrammerCalculator, and ScientificCalculator?
| A4: CalculatorBase provides basic arithmetic; ProgrammerCalculator adds hex/dec conversions;
|     ScientificCalculator adds trigonometric functions.
|
| Q5: What is a pure virtual function?
| A5: A function with no implementation in the base class, forcing derived classes to implement
================================================================================
*/

/*  =============================================================================================
                                Included Libraries -> "Calculator.h"
    =============================================================================================   */
#include "T12.2_Calculator_PolyMorphism.h" // All headers and libraries are included inside.
#include "T12.2_Lib_HelpingFunctions.h"    // Helping functions namespace to be used in main.

/*  =============================================================================================
                                Declarations / Functions Prototypes -> "Calculator.h"
    =============================================================================================   */

/*  =============================================================================================
                                Entry Point - Main Function
    =============================================================================================   */
int main()
{
    while (true)
    {
        char ModeSelected;
        int attempts = 0;
        const int max_attempts = 3;

        // Get Mode From User.
        HelpingFunctions::get_Mode_print_menu(ModeSelected);

        // Make mode upper-case to be ready to switch to it.
        ModeSelected = std::toupper(ModeSelected);

        // Pointer object to calculator.
        Calculator *Calculator_ptr = nullptr;

        // Exit Program if user wants to.
        if (ModeSelected == 'E')
        {
            std::cout << "Exiting...\n";
            break;
        }

        // Switching to proper calculator depending on selected mode.
        if (ModeSelected == 'C')
            Calculator_ptr = new CalculatorBase();
        else if (ModeSelected == 'S')
            Calculator_ptr = new ScientificCalculator();
        else if (ModeSelected == 'P')
            Calculator_ptr = new ProgrammerCalculator();
        else
        {
            std::cout << "Invalid Calculator Type.\n";
            if (++attempts >= max_attempts)
            {
                std::cout << "Too many invalid attempts. Exiting.\n";
                break; // After 3 attempts, close the program.
            }
            continue; // repeat the loop without continue the following.
        }

        // Display what we selected.
        Calculator_ptr->Display();

        // Enter Operation Mode.
        if (ModeSelected == 'C') /***********************************************************/
        {
            char operation; // Container variable.

            // Show available operations to user.
            std::cout << "Select operation\n"
                      << "\t' A ' - Add\n"
                      << "\t' S ' - Subtract\n";

            // Take operation input from user.
            std::cin >> operation;

            // Upper-Case to prepare for switching.
            operation = std::toupper(operation);

            // Switch operation.
            if (operation == 'A')
                Calculator_ptr->add();
            else if (operation == 'S')
                Calculator_ptr->sub();
            else
                std::cout << "Invalid operation.\n";
        }
        else if (ModeSelected == 'S') /***********************************************************/
        {
            // Cast the calculator to the one we need.
            ScientificCalculator *Sci_calc_ptr = dynamic_cast<ScientificCalculator *>(Calculator_ptr);

            char operation; // Container variable.

            // Show available operations to user.
            std::cout << "Select operation\n"
                      << "\t' S ' - Sin(angle)\n"
                      << "\t' C ' - Cos(angle)\n";

            // Take operation input from user.
            std::cin >> operation;

            // Upper-Case to prepare for switching.
            operation = std::toupper(operation);

            // Switch operation.
            if (operation == 'S')
                Sci_calc_ptr->sin_ang();
            else if (operation == 'C')
                Sci_calc_ptr->cos_ang();
            else
                std::cout << "Invalid operation.\n";

            Sci_calc_ptr = nullptr;
        }
        else if (ModeSelected == 'P') /***********************************************************/
        {
            // Cast the calculator to the one we need.
            ProgrammerCalculator *prog_calc_ptr = dynamic_cast<ProgrammerCalculator *>(Calculator_ptr);

            char operation; // Container variable.

            // Show available operations to user.
            std::cout
                << "Select operation\n"
                << "\t' H ' - Hex to Decimal.\n"
                << "\t' D ' - Decimal to Hex.\n";

            // Take operation input from user.
            std::cin >> operation;

            // Upper-Case to prepare for switching.
            operation = std::toupper(operation);

            // Switch operation.
            if (operation == 'H')
                prog_calc_ptr->hexaToDecimal();
            else if (operation == 'D')
                prog_calc_ptr->decimalToHexa();
            else
                std::cout << "Invalid operation.\n";

            prog_calc_ptr = nullptr;
        }

        delete Calculator_ptr; // delete all dynamic memory allocated.
        attempts = 0;          // reset attempts after a valid session.
    }
    return 0;
}

/*  =============================================================================================
                                Functions implementation -> "Calculator.cpp"
    =============================================================================================   */
