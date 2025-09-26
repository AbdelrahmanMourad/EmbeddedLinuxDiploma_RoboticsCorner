#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

// Abstract Base Class
class Calculator {
public:
    virtual void add() = 0;
    virtual void sub() = 0;
    virtual void Display() = 0;
    virtual ~Calculator() = default;
};

// Base Calculator with common functionalities
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

// Scientific Calculator
class ScientificCalculator : public CalculatorBase {
public:
    void sin_ang() {
        double angle;
        cout << "Enter angle in degrees: ";
        cin >> angle;
        cout << "sin(" << angle << ") = " << sin(angle * M_PI / 180.0) << endl;
    }

    void cos_ang() {
        double angle;
        cout << "Enter angle in degrees: ";
      n  cin >> angle;
        cout << "cos(" << angle << ") = " << cos(angle * M_PI / 180.0) << endl;
    }

    void Display() override {
        cout << "Scientific Calculator operation" << endl;
    }
};

// Programmer Calculator
class ProgrammerCalculator : public CalculatorBase {
public:
    void hexaToDecimal() {
        string hex;
        cout << "Enter hexadecimal value (e.g. 1A): ";
        cin >> hex;
        int decimal;
        stringstream ss;
        ss << hex;
        ss >> hex >> std::hex >> decimal;
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

// Entry Point
int main() {
    char typeChoice, opChoice;
    CalculatorBase* Cal = nullptr;

    int attempts = 3;
    while (attempts--) {
        cout << "\nChoose Calculator Type:\n"
             << "C: Basic Calculator\n"
             << "S: Scientific Calculator\n"
             << "P: Programmer Calculator\n"
             << "E: Exit\nChoice: ";
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
