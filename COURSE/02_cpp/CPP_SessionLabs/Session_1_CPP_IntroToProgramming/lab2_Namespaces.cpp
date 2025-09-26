/*  ===========================================================================================
                                    Included Libraries
    =========================================================================================== */
#include <iostream>

/*  ===========================================================================================
                                    Declarations
    =========================================================================================== */
/// @brief This code demonstrates the use of namespaces in C++ to separate floating point and integer values.
/// It uses two namespaces: `floatingPoint` for float values and `integers` for integer values.
/// It initializes a float variable `value` in the `floatingPoint` namespace and an int variable `value` in the `integers` namespace.
namespace floatingPoint
{
    float value = 0;
}

namespace integers
{
    int value = 0;
}

/*  ===========================================================================================
                                    main() - Entry Point
    =========================================================================================== */
int main()
{
    // Change Values.
    floatingPoint::value = 5.4;
    integers::value = 5.4;

    // Print
    std::cout << floatingPoint::value << "\n"; //  5.4
    std::cout << integers::value << "\n";      //  5
}