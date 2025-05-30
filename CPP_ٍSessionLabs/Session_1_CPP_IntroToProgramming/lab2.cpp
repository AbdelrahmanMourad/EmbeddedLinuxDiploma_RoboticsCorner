#include <iostream>

namespace floatingPoint
{
    float value = 0;
}
namespace integers
{
    int value = 0;
}

int main()
{
    // Change Values.
    floatingPoint::value = 5.4;
    integers::value = 5.4;

    // Print
    std::cout << floatingPoint::value << "\n";
    std::cout << integers::value << "\n";
}