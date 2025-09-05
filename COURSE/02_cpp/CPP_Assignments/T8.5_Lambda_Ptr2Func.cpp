
/*________________________________________________________________________________________________________

    Task(8.5): Lambda Expressions and Function Pointers:
    ----------------------------------------------------

        Objective:
            Understand the limitations of converting lambda expressions to function pointers, particularly
            when lambdas capture variables.

        Instructions:
            1. Define Two Lambdas:
                - Lambda 1:
                    - Define a lambda that does not capture any variables and takes a parameter.
                    - This lambda should simply print the value of the parameter.
                - Lambda 2:
                    - Define a lambda that captures a variable from its surrounding scope.
                    - This lambda should print the value of the captured variable and take a parameter.
            2. Create Function Pointers:
                - Attempt to create function pointers for both lambdas.
                - Observe the compilation errors when attempting to create a function pointer for the lambda
                    that captures a variable.
___________________________________________________________________________________________________________*/

/*  ===================================================================
                    Included Libraries.
    =================================================================== */
#include <iostream>

/*  ===================================================================
                        Declarations and Definitions
    =================================================================== */
namespace HelpingFunctions
{
    void printSeparator(const std::string &&str)
    {
        std::cout << "\n-----------------------------------------\n"
                  << str
                  << "\n-----------------------------------------\n";
    };
};
/*  ===================================================================
                        main() - Entry Point
    =================================================================== */
int main()
{
    /*-----------------------------------------------------------------------------------------*/
    HelpingFunctions::printSeparator(std::move("Lambda Expressions and Function Pointers:"));
    /*-----------------------------------------------------------------------------------------*/
    // Declare variables for demonstration.
    int passedValue = 10;   // variable to be passed by value.
    int capturedValue = 42; // Variable to be captured by value.

    // Define two Lambdas:

    // Lambda 1: No capture, takes a parameter, prints the value.
    // [](int passedValue)
    auto lambda01 = [](int passedValue)
    { std::cout << "lambda 01 passed_value =   " << passedValue << std::endl; };

    // Lambda 2: Captures a variable from surrounding scope, prints the value of the captured variable and takes a parameter.
    // [capturedValue](int passedValue)
    auto lambda02 = [capturedValue](int passedValue)
    { std::cout << "lambda 02 captured_value = " << capturedValue << std::endl; };

    // calling the lambdas directly:
    std::cout << "\nCalling Lambdas Directly:\n";
    lambda01(passedValue);
    lambda02(passedValue);

    // Using function pointer for lambda01 (valid).
    void (*funcPtrToLambda01)(int) = lambda01;
    std::cout << "\nCalling funPtr2Lambds:\n";
    funcPtrToLambda01(passedValue); // Call the function pointer with a value passed.
    funcPtrToLambda01(15);          // Call the function pointer with a value passed.

    // Attempting function pointer for lambda2 (invalid)
    // void (*funcPtrToLambda02)(int) = lambda02; // This will cause a compilation error because Lambda 2 captures a variable.
    // void (*funcPtr2)(int) = lambda2; // Uncommenting this line causes an error.

    return 0;
}

/*  =================================================================================
    Summary:
    =================================================================================

    ---- Lambda Expressions Overview ----
        A lambda expression in C++ allows the creation of anonymous functions on-the-fly.
        Syntax:
            _________________________________________________________________
            |                                                               |
            |       [capture] (parameters) -> returnType { body }           |
            |                                                               |
            |_______________________________________________________________|

    ---- Capture Mechanisms ----
        - []            : No capture (stateless lambda)
        - [var]         : Capture var by value (copy stored within lambda)
        - [&var]        : Capture var by reference (modifications affect original)
        - [var1, &var2] : Capture var1 by value and var2 by reference
        - [=]           : Capture all variables by value
        - [=var]        : capture var by value and others by reference
        - [&]           : Capture all variables by reference

    --- Keywords Used with Lambdas ---
        - mutable   → Allows modifications of captured-by-value variables.
        - constexpr → Makes the lambda compile-time evaluable if possible.
        - noexcept  → Specifies that the lambda won't throw exceptions.
        - auto      → Used to infer the return type automatically.

    ---- Default Values in Lambdas ----
        - Default values can be provided for function parameters.
        - Captured variables cannot have default values; their values are fixed at capture time.

    ---- Calling a Lambda ----
        - Lambdas can be executed instantly upon declaration using `()`.
        - No function pointer is needed; they can be called like regular functions.

    ---- Function Pointers and Lambdas ----
        - A function pointer can store the address of a regular function.
        - Stateless lambdas (without captures) can be converted to function pointers.
        - Capturing lambdas (stateful lambdas) **cannot** be assigned to function pointers because
            they generate a unique callable object with internal storage.

    NOTE:
    ---- Key Takeaway ----
        Lambda expressions with captures generate closure objects, preventing conversion
        to regular function pointers. However, non-capturing lambdas can be safely assigned.

    =================================================================================  */