/*  =============================================================================================
                                Header Guard File
    =============================================================================================   */
#ifndef _LIB_HELPING_FUNCTIONS_
#define _LIB_HELPING_FUNCTIONS_

/*  =============================================================================================
                                Included Libraries -> "Calculator.h"
    =============================================================================================   */
#include "T12.2_Calculator_PolyMorphism.h" // All headers and libraries are included inside.

/*  =============================================================================================
                                Declarations / Functions Prototypes -> "Calculator.h"
    =============================================================================================   */
namespace HelpingFunctions
{
    void get_Mode_print_menu(char &ModeSelected);
    void ModeSwitchOperation(char &ModeSelected, CalculatorBase *Base_ptr);
};

/*  =============================================================================================
                                Entry Point - Main Function -> "Main.cpp"
    =============================================================================================   */

/*  =============================================================================================
                                Functions implementation
    =============================================================================================   */
void HelpingFunctions::get_Mode_print_menu(char &ModeSelected)
{

    std::cout << "Hello, please select a calculator type:\n"
              << "\t- Basic Calculator('C').\n"
              << "\t- Scientific Calculator('S').\n"
              << "\t- Programmer Calculator('P').\n"
              << "\t- Exit('E').\n";
    std::cin >> ModeSelected;
}

void HelpingFunctions::ModeSwitchOperation(char &ModeSelected, CalculatorBase *Base_ptr)
{
    /*
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
    */
}

#endif /*_LIB_HELPING_FUNCTIONS_*/
