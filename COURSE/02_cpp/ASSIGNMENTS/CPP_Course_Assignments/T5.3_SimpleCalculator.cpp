/*________________________________________________________________________________________________________

    Task(5.3):
    ----------
        Write a Program to Make a Simple Calculator.

    In this problem, you have to make a program that can perform
        addition, subtraction, multiplication, and division
        on two numbers entered by the user.

    The type of arithmetic operation can also be selected by the user.

    Input:
        Enter the Number: 10 25
        Enter + for addition, - for substraction, * for multiplication, / for division.

        {{if * is entered}}
    Output: 250
___________________________________________________________________________________________________________*/

/* Include Section */
#include <iostream>

/* Entry Point */
int main()
{
    // Define Container Variables.
    float N1, N2;
    char Operation;

    while (1)
    {
        // Welcome Message To show we're in the begiining on the New Operation.
        std::cout << "-------------------------------------------" << "\n";
        std::cout << " Welcome to the Simple Calculater Program! " << "\n";
        std::cout << "-------------------------------------------" << "\n\n";

        // Taking Inputs from user.
        std::cout << "Kindly Enter Your 1st Number:" << std::endl;
        std::cin >> N1;
        std::cout << "Kindly Enter Your 2nd Number:" << std::endl;
        std::cin >> N2;
        std::cout << "Enter Operation: \" + , - , * , / , %  \"" << std::endl;
        std::cin >> Operation;

        if (Operation == '+') // Addition.
            std::cout << "Result: " << N1 << "+" << N2 << "= " << (N1 + N2) << std::endl;
        else if (Operation == '-') // Subtraction.
            std::cout << "Result: " << N1 << "-" << N2 << "= " << (N1 - N2) << std::endl;
        else if (Operation == '*') // Multiplication.
            std::cout << "Result: " << N1 << "*" << N2 << "= " << (N1 * N2) << std::endl;
        else if (Operation == '/') // Division.
            std::cout << "Result: " << N1 << "/" << N2 << "= " << (N1 / N2) << std::endl;
        else if (Operation == '%') // Remainder.
            std::cout << "Result: " << N1 << "%" << N2 << "= " << (int(N1) % int(N2)) << std::endl;
        else
            std::cout << "Wrong Operation, Try Again!" << std::endl;
    }

    // Return E_OK Status.
    return 0;
}