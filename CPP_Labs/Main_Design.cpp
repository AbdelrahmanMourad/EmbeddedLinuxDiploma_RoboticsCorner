#include "iostream"
/*
    PRocedural Programming.  <-- running lines of code inside the main()
    Functional Programming.  <-- More modular design based on functions.
*/

#include "functions.h"  // If not adding Functions,cpp in complication, we get "Linking error" as it's now declared, not found the inplemenetation.

int main()
{
    // Local Variables.
    double first_num, second_num;
    char operation;
    int result = 0;

    // Take inputs from user.
    std::cout << "Please enter two numbers:\n";
    std::cin >> first_num;
    std::cin >> second_num;
    std::cout << "Please enter the operation \"+,-,/,*,%\"\n";
    std::cin >> operation;

    // Main Operation.
    switch (operation)
    {
    case '+':
        result = Calculator::Add(first_num, second_num);
        break;
    case '-':
        result = Calculator::Sub(first_num, second_num);
        break;
    case '/':
        result = Calculator::Div(first_num, second_num);
        break;
    case '*':
        result = Calculator::Multiply(first_num, second_num);
        break;
    case '%':
        result = Calculator::Rem(first_num, second_num);
        break;
    default:
        // Do Nothing.
        break;
    }

    // Display the Output of the Operations.
    std::cout << "Then: " << first_num << " " << operation << " " << second_num << " = " << result << std::endl;
}
