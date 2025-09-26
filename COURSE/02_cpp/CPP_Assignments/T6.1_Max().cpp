/*________________________________________________________________________________________________________

    Task(6.1):
    ----------
       Write a C++ function that takes two integers as parameters and returns the maximum
        of the two numbers. Then, use this function to find the maximum of three numbers.

    Example:
        Input:
            The first number: 50
            The Second number: 70
            The third number: 90
        Output:
            The maximum of the 3 numbers is = 90

___________________________________________________________________________________________________________*/

/* Include Section */
#include <iostream>

// Functions Prototype Section.
int MaxOf3IntNumbers(int *N1, int *N2, int *N3);

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

// Functions Implementation Section.
int MaxOf3IntNumbers(int *N1, int *N2, int *N3)
{
    if (*N1 >= *N2)
    {
        if (*N1 >= *N3)
            return *N1;
        else
            return *N3;
    }
    else if (*N2 >= *N3)
        return *N2;
    else
        return *N3;
}