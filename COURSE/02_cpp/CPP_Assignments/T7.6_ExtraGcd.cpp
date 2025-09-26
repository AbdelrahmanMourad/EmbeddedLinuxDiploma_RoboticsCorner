/*________________________________________________________________________________________________________

    Task(7.6):
    ----------
       Write a C++ function that find the Greatest Common Divisor (GCD) of two numbers.

       The greatest common dvisor (GCD), also called the greatest common factor, of two numbers is the largest number that divides them both.
        For instance, the greatest common factor of 20 and 15 is 5, since 5 divides both 20 and 15 and no larger number has this property.

    Example:
        Sample Output:
            Input the first number: 25
            Input the second number: 15
            The Greatest Common Divisor is: 5
___________________________________________________________________________________________________________*/

// Include libraries.
#include <iostream>

// Prototype.
int Find_GCF(int &x, int &y);

// Entry point.
int main()
{
    int x, y;
    std::cout << "Please Enter 2 Values:\n";
    std::cin >> x >> y;
    std::cout << "GCF=\t" << Find_GCF(x, y) << std::endl;

    return 0;
}

// Implementation.
int Find_GCF(int &x, int &y)
{
    // Check if 0 or -ve numbers.
    if (x <= 1 || y <= 1)
    {
        std::cout << "Wrong input (-ve) or zero number" << std::endl;
        return 0;
    }

    if (x >= y) // Check which one is larger
    {
        if (x % y == 0) // Check if one is GCF to the other.
        {
            return y; // Then the smaller is the FCF to each
        }
        else
        {
            for (int i = y; i >= 1; i--) // Check from the small number to 1.
            {
                if ((x % i == 0) && (y % i == 0))
                    return i; // GCF.
            }
        }
    }
    else
    {
        if (y % x == 0) // Check if one is GCF to the other.
        {
            return y; // Then the smaller is the FCF to each
        }
        else
        {
            for (int i = x; i >= 1; i--) // Check from the small number to 1.
            {
                if ((x % i == 0) && (y % i == 0))
                    return i; // GCF.
            }
        }
    }
}