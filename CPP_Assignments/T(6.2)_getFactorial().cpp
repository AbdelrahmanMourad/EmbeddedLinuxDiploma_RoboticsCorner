/*________________________________________________________________________________________________________

    Task(6.2):
    ----------
        Create a C++ program that implements a function to calculate the factorial of a given
        number using recursion.

        In mathematics, the factorial of a non-negative integer n, denoted by n!, is the
        product of all positive integers less than or equal to n.

        The factorial of n also equals the product of n with the next smaller factorial:
        n!=n×(n−1)×(n−2)×(n−3)× ×3×2×1=n×(n−1)!


        For example:
            5!=5×4!=5×4×3×2×1=120.
___________________________________________________________________________________________________________*/

/* Include Section */
#include <iostream>

/* Function Implementation */
int getFactorial(int &Number)
{
    int Factorial = 1;

    for (int i = Number; i >= 1; i--)
    {
        Factorial *= i;
    }

    return Factorial;
}

/* Entry Point */
int main()
{
    // Define Example Variables.
    int N1{5}, N2{8};

    // Define Example References.
    int &r1 = N1;
    int &r2 = N2;

    std::cout << "getFactorial(5) = " << getFactorial(r1) << std::endl;
    std::cout << "getFactorial(8) = " << getFactorial(r2) << std::endl;

    // Return E_OK Status.
    return 0;
}