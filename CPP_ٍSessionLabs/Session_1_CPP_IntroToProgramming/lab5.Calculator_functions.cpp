// inplementation in ROM.

/*
The member initializer list (: first_num_{a}, second_num_{b}) is only valid for constructors, not for regular member functions.
Add is a regular member function, not a constructor.
*/
#include "iostream"
#include "lab5.Calculator_functions.h" // Include the header file for calculator functions.

/* =============================================================================
    Initialization & Welcome
============================================================================= */
void Calculator_Namespace::Calculator_Class::Welcome_Msg(void)
{
    std::cout << "Welcome!\n";
}

/* =============================================================================
    User Input & Operation Selection
============================================================================= */
void Calculator_Namespace::Calculator_Class::TakeUserInputs_Operation(void)
{
    std::cout << "Please enter two numbers:\n";
    std::cin >> first_num_ >> second_num_;
    std::cout << "Please enter the operation (+, -, /, *, %):\n";
    char op_char;
    std::cin >> op_char;
    switch (op_char)
    {
    case '+':
        Add();
        break;
    case '-':
        Sub();
        break;
    case '/':
        Div();
        break;
    case '*':
        Multiply();
        break;
    case '%':
        Rem();
        break;
    default:
        operation_ = OperationType_enum::None;
        std::cout << "Invalid operation!" << std::endl;
        return;
    }
}

void Calculator_Namespace::Calculator_Class::TakeUserInputs_Operation_Print(void)
{
    std::cout << "Please enter two numbers:\n";
    std::cin >> first_num_ >> second_num_;
    std::cout << "Please enter the operation (+, -, /, *, %):\n";
    char op_char;
    std::cin >> op_char;
    switch (op_char)
    {
    case '+':
        Add();
        break;
    case '-':
        Sub();
        break;
    case '/':
        Div();
        break;
    case '*':
        Multiply();
        break;
    case '%':
        Rem();
        break;
    default:
        operation_ = OperationType_enum::None;
        std::cout << "Invalid operation!" << std::endl;
        return;
    }
    PrintOperationResult();
}

/* =============================================================================
    Arithmetic Operations
============================================================================= */
void Calculator_Namespace::Calculator_Class::Add(void)
{
    result_ = first_num_ + second_num_;
    operation_ = OperationType_enum::Add;
}

void Calculator_Namespace::Calculator_Class::Sub(void)
{
    result_ = first_num_ - second_num_;
    operation_ = OperationType_enum::Sub;
}

void Calculator_Namespace::Calculator_Class::Div(void)
{
    result_ = first_num_ / second_num_;
    operation_ = OperationType_enum::Div;
}

void Calculator_Namespace::Calculator_Class::Multiply(void)
{
    result_ = first_num_ * second_num_;
    operation_ = OperationType_enum::Multiply;
}

void Calculator_Namespace::Calculator_Class::Rem(void)
{
    result_ = static_cast<int>(first_num_) % static_cast<int>(second_num_);
    operation_ = OperationType_enum::Rem;
}

/* =============================================================================
    Output & Helpers
============================================================================= */
void Calculator_Namespace::Calculator_Class::PrintOperationResult(void)
{
    std::cout << "Result: " << this->first_num_ << " " << this->op_char_ << " " << this->second_num_ << " = " << this->result_ << std::endl;
}
