/*  ________________________________Functions Overloading______________________________


    _______________________________________________________________________
*/

// Include Library.
#include <iostream>

// Fuunctions ProtoTypes.
namespace Calculator
{
    double add(int a, int b);
    double add(char a, char b);
    double add(double a, double b);
    /*************************** Overloading ************************** */
}

int main()
{
    int a = 1, b = 2;
    char c = 1, d = 2;
    double e = 1, f = 2;

    std::cout << "int sum = " << Calculator::add(a, b) << std::endl;
    std::cout << "char sum = " << Calculator::add(c, d) << std::endl;
    std::cout << "double sum = " << Calculator::add(e, f) << std::endl;
    return 0;
}

double Calculator::add(int a, int b)
{
    std::cout << "int Fun is called\n";
    return a + b;
}
double Calculator::add(char a, char b)
{
    std::cout << "char Fun is called\n";
    return a + b;
}
double Calculator::add(double a, double b)
{
    std::cout << "double Fun is called\n";
    return a + b;
}