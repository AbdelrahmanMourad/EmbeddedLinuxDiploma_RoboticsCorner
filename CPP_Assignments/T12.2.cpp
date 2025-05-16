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










/*________________________________________________________________________________________________________

    Task(7.7): Extra Prefix sum:
    ----------------------------

        You are given an array of N integers.
        You have to answer Q queries.
        Each query contains two integers L and R
        For each query print the sum of integers in array from index L to R
        
        Input :
            First line will contain an integer T (number of test cases).
            T blocks of line follows.
            First line of each block contains an integer N (number of array elements).
            Next line contains N integers (array elements).
            Next line contains an integer Q (number of queries).
            Next Q lines contain two integers L and R
        
        HINT:
            use prefix sum array.
    
        Sample Input :
            2 4 10 20 30
            40 2 1 4 2 3 5
            1 1 1 1 1 3 1 2
            2 5 5 5
        
        Sample Output:
            100 50 2 4 1
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */


/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */










