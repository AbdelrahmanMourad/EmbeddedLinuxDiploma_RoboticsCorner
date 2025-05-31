// //  Header Guard Condition.
// #ifndef FUNCTIONS_H     // Cons: inside the c/c++ languages, so compiler independent.
// #define FUNCTIONS_H

/*Another way for header guard condition*/
#pragma once // Backdraw: Compiler Dependent.

// Fuunctions ProtoTypes.
namespace Calculator_Namespace
{
    enum class OperationType_enum
    {
        None,
        Add,
        Sub,
        Div,
        Multiply,
        Rem
    };

    class Calculator_Class
    {
    public:
        void Welcome_Msg(void);
        double Add(double a, double b);
        double Sub(double a, double b);
        double Div(double a, double b);
        double Multiply(double a, double b);
        double Rem(double a, double b);
        void PrintOperation();

    private:
        // Private Member Variables.
        // No private member variables needed for this simple calculator.
        double first_num_{0};                                    // To store the first number.
        double second_num_{0};                                   // To store the second number.
        double result_{0};                                       // To store the result of operations, if needed.
        char op_char_{0};                                        // To store the operator character.
        OperationType_enum operation_{OperationType_enum::None}; // To store the operation type as an enum.

    public:
        // Member Functions.
        void Welcome_Msg(void);                         // Initialization.
        void TakeUserInputs_Operation(void);                  // Take user inputs and switch operations.
        void TakeUserInputs_Operation_Print(void); // Take user inputs and switch operations and print result.
        // Arithmetic Operations.
        void Add(void);      // Add.
        void Sub(void);      // Sub.
        void Div(void);      // Div.
        void Multiply(void); // Multiply.
        void Rem(void);      // Remainder.
        char GetOperatorChar(OperationType_enum operation);
        void PrintOperationResult(void);
        // double Switch(double a, double b, char op); // New function to select operation

        // Constructor and Destructor.
        Calculator_Class(void) = default;                               // Default Constructor.
        ~Calculator_Class(void) = default;                              // Default Destructor.
        Calculator_Class(const Calculator_Class &) = delete;            // Copy Constructor.
        Calculator_Class &operator=(const Calculator_Class &) = delete; // Copy Assignment Operator.
        Calculator_Class(Calculator_Class &&) = delete;                 // Move Constructor.
        Calculator_Class &operator=(Calculator_Class &&) = delete;      // Move Assignment Operator.
    };
}

// #endif /*FUNCTIONS_H*/