#define _USE_MATH_DEFINES  // Enable math constants like M_PI on MSVC
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

// Abstract Base Class: defines the calculator interface
class Calculator {
public:
    virtual void add() = 0;           // Abstract add method
    virtual void sub() = 0;           // Abstract subtract method
    virtual void Display() = 0;       // Abstract display method
    virtual ~Calculator() = default;  // Virtual destructor
};

// Implements basic calculator functions
class CalculatorBase : public Calculator {
public:
    void add() override {
        double a, b;
        cout << "Enter two numbers to add: ";
        cin >> a >> b;
        cout << "Result: " << a + b << endl;
    }

    void sub() override {
        double a, b;
        cout << "Enter two numbers to subtract: ";
        cin >> a >> b;
        cout << "Result: " << a - b << endl;
    }

    void Display() override {
        cout << "Basic Calculator operation" << endl;
    }
};

// Scientific calculator with trigonometric functions
class ScientificCalculator : public CalculatorBase {
public:
    void sin_ang() {
        double angle;
        cout << "Enter angle in degrees: ";
        cin >> angle;
        // Convert degrees to radians and compute sine
        cout << "sin(" << angle << ") = " << sin(angle * M_PI / 180.0) << endl;
    }

    void cos_ang() {
        double angle;
        cout << "Enter angle in degrees: ";
        cin >> angle;
        // Convert degrees to radians and compute cosine
        cout << "cos(" << angle << ") = " << cos(angle * M_PI / 180.0) << endl;
    }

    void Display() override {
        cout << "Scientific Calculator operation" << endl;
    }
};

// Programmer calculator for number system conversions
class ProgrammerCalculator : public CalculatorBase {
public:
    void hexaToDecimal() {
        string hex;
        cout << "Enter hexadecimal value (e.g. 1A): ";
        cin >> hex;
        int decimal;
        stringstream ss;
        ss << hex;
        ss >> std::hex >> decimal;  // Convert hex string to decimal int
        cout << "Decimal: " << decimal << endl;
    }

    void decimalToHexa() {
        int decimal;
        cout << "Enter decimal number: ";
        cin >> decimal;
        cout << "Hexadecimal: " << hex << uppercase << decimal << endl;
    }

    void Display() override {
        cout << "Programming Calculator operation" << endl;
    }
};

// Main logic: user selects calculator type and operations
int main() {
    char typeChoice, opChoice;
    CalculatorBase* Cal = nullptr;
    int attempts = 3;

    while (attempts--) {
        cout << "\nChoose Calculator Type:\n"
             << "C: Basic Calculator\nS: Scientific Calculator\n"
             << "P: Programmer Calculator\nE: Exit\nChoice: ";
        cin >> typeChoice;

        switch (toupper(typeChoice)) {
            case 'C':
                Cal = new CalculatorBase();
                Cal->Display();
                cout << "A: Add\nS: Subtract\nChoice: ";
                cin >> opChoice;
                if (toupper(opChoice) == 'A') Cal->add();
                else if (toupper(opChoice) == 'S') Cal->sub();
                else cout << "Invalid operation.\n";
                break;

            case 'S': {
                ScientificCalculator* sci = new ScientificCalculator();
                Cal = sci;
                Cal->Display();
                cout << "S: sin(angle)\nC: cos(angle)\nChoice: ";
                cin >> opChoice;
                if (toupper(opChoice) == 'S') sci->sin_ang();
                else if (toupper(opChoice) == 'C') sci->cos_ang();
                else cout << "Invalid operation.\n";
                break;
            }

            case 'P': {
                ProgrammerCalculator* prog = new ProgrammerCalculator();
                Cal = prog;
                Cal->Display();
                cout << "H: Hex to Decimal\nD: Decimal to Hex\nChoice: ";
                cin >> opChoice;
                if (toupper(opChoice) == 'H') prog->hexaToDecimal();
                else if (toupper(opChoice) == 'D') prog->decimalToHexa();
                else cout << "Invalid operation.\n";
                break;
            }

            case 'E':
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid calculator type. Try again.\n";
                continue;
        }

        delete Cal;
        Cal = nullptr;
    }

    cout << "Too many invalid attempts. Program exiting.\n";
    return 0;
}
