
/*  =============================================================================================
                                Included Libraries -> "Calculator.h"
    =============================================================================================   */
#include "T12.2_Calculator_PolyMorphism.h" // All headers and libraries are included inside.

/*  =============================================================================================
                                Declarations / Functions Prototypes -> "Calculator.h"
    =============================================================================================   */

/*  =============================================================================================
                                Entry Point - Main Function -> "Main.cpp"
    =============================================================================================   */

/*  =============================================================================================
                                Functions implementation
    =============================================================================================   */
void ScientificCalculator::sin_ang()
{
    // Container variables.
    double angle_degree, angle_radians, angle_sin;

    // Get user input.
    std::cout << "Please enter angle in degrees:\t";
    std::cin >> angle_degree;

    //  ___________Conversion Algorithm Here___________
    angle_radians = (angle_degree * M_PI) / 180; // from <cmath> library => """ M_PI """
    angle_sin = std::sin(angle_radians);         // from <cmath> library => """ std::sin(rad) """

    // Display output to user.
    std::cout << "sin ( " << angle_degree << " )=\t" << angle_sin << std::endl;
}

void ScientificCalculator::cos_ang()
{
    // Container variables.
    double angle_degree, angle_radians, angle_cos;

    // Get user input.
    std::cout << "Please enter angle in degrees:\t";
    std::cin >> angle_degree;

    //  ___________Conversion Algorithm Here___________
    angle_radians = (angle_degree * M_PI) / 180; // from <cmath> library => """ M_PI """
    angle_cos = std::cos(angle_radians);         // from <cmath> library => """ std::sin(rad) """

    // Display output to user.
    std::cout << "cos ( " << angle_degree << " )=\t" << angle_cos << std::endl;
}

void ProgrammerCalculator::hexaToDecimal()
{
    // Declare containers variables.
    unsigned int Decimal = 0;
    std::string Hex_str;

    // Get Hex input from user.
    std::cout << "Enter hexadecimal value (e.g., 1A3F or 0x1A3F):\t", std::cin >> Hex_str;

    //  ___________Conversion Algorithm Here___________
    std::stringstream ss;
    ss << std::hex << Hex_str;
    ss >> Decimal;

    // Display Decimal output to user.
    std::cout << "Decimal for '" << Hex_str << "' is:\t" << Decimal;
}

void ProgrammerCalculator::decimalToHexa()
{
    // Declare containers variables.
    unsigned int Decimal = 0;
    std::string Hex_str;

    //  Get Decimal input from user.
    std::cout << "Enter decimal number:\t", std::cin >> Decimal;

    //  ___________Conversion Algorithm Here___________
    // Display Hex output to user.
    std::cout << "Hexa for '" << Decimal << "' is:\t'0x" << std::uppercase << std::hex << Decimal << "'\n";
}

// // Converts a hexadecimal string to its decimal equivalent
// unsigned int ProgrammerCalculator::Conversion_ManualHexToDecimal(const std::string &hexInput)
// {
//     unsigned int result = 0; // This will hold the final decimal value

//     // Determine starting index based on whether input starts with "0x" or "0X"
//     size_t start = (hexInput.size() >= 2 && hexInput[0] == '0' &&
//                     (hexInput[1] == 'x' || hexInput[1] == 'X'))
//                        ? 2
//                        : 0;

//     // Loop through each character of the hex string
//     for (size_t i = start; i < hexInput.size(); ++i)
//     {
//         char c = hexInput[i];    // Current character
//         unsigned int digitValue; // Decimal value of the current hex digit

//         // If the character is a digit (0–9), calculate its value
//         if (std::isdigit(c))
//         {
//             digitValue = c - '0';
//         }
//         // If it's a letter (A–F or a–f), convert it to uppercase then calculate its value
//         else if (std::isalpha(c))
//         {
//             c = std::toupper(c); // Normalize to uppercase
//             if (c >= 'A' && c <= 'F')
//             {
//                 digitValue = 10 + (c - 'A'); // A = 10, B = 11, ..., F = 15
//             }
//             else
//             {
//                 throw std::invalid_argument("Invalid character in hex string.");
//             }
//         }
//         // If it's neither a digit nor a valid hex letter, it's invalid
//         else
//         {
//             throw std::invalid_argument("Invalid character in hex string.");
//         }

//         // Shift previous result left by one hex digit (multiply by 16)
//         // Then add the new digit's value
//         result = result * 16 + digitValue;
//     }

//     return result; // Return the converted decimal number
// }
