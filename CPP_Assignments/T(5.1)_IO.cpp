/*________________________________________________________________________________________________________

    Task(5.1):
    ----------
        Create a C++ program that prompts the user to enter their name and age,
        then displays a greeting message along with their age.

    Example:
        Input:
            Ahmed
            15
        Output:
            Hello Ahmed, you’re 15 years old?
___________________________________________________________________________________________________________*/

/* Include Section */
#include <iostream>

/* Entry Point */
int main()
{
    // Define Container Variables.
    std::string Name;
    float Age;

    // Taking Inputs from user.
    std::cout << "Kindly Enter Your Name:" << std::endl;
    std::cin >> Name;
    std::cout << "Kindly Enter Your Age:" << std::endl;
    std::cin >> Age;

    // Printing Statement.
    std::cout << "Hello " << Name << ", You're " << Age << " years old?" << std::endl;

    // Return E_OK Status.
    return 0;
}