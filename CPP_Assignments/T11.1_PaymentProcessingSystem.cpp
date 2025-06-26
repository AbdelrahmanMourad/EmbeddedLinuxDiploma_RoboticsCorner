
/*________________________________________________________________________________________________________

    Task(11.1): Payment Processing System Using Inheritance in C++:
    ----------------------------------------------------------------

    In this task, you will implement a payment processing system using object-oriented
    programming (OOP) principles, particularly focusing on inheritance in C++.
    The system will simulate payments made via different methods, such as credit cards
    and PayPal, using a common base class for shared functionality.
    The key objective is to demonstrate how derived classes can extend and specialize
    behavior defined in a base class by overriding methods.

    Key Requirements:
        1.  Base Class: PaymentMethod:
            ○   Define a base class PaymentMethod to represent a general payment
                method. It should contain:
                •   A protected data member amount to store the payment amount.
                •   A constructor to initialize amount.
                •   A setter set_amount() and a getter get_amount() for managing the payment amount.
        2.  Derived Class: CreditCard:
            ○   Create a derived class CreditCard that inherits from PaymentMethod and
                represents credit card payments. It should contain:
                •   A private data member cardNumber to store the credit card number.
                •   A constructor that initializes the amount and cardNumber.
                •   A method processPayment() that simulates processing a credit card
                    payment by printing out the amount and card number.
        3.  Derived Class: PayPal:
            ○   Create another derived class PayPal that also inherits from PaymentMethod
                and represents PayPal payments. It should include:
                •   A private data member email to store the user's PayPal email address.
                •   A constructor that initializes the amount and email.
                •   A method processPayment() that simulates processing a PayPal payment
                    by printing out the amount and the email address.
        4.  Main Program:
            ○   In the main() function, create instances of the CreditCard and PayPal classes.
            ○   Call the processPayment() method on each instance to simulate processing a
                payment using both methods.
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
// _______________Base Class_______________
class PaymentMethod
{
protected:
    double amount;

public:
    PaymentMethod(double inputAmount) : amount{inputAmount} { std::cout << "Constructor Called: Payment Method.\n"; }
    ~PaymentMethod() { std::cout << "Destructor Called: PaymentMethod.\n"; }
    void set_amount(double inputAmount) { this->amount = inputAmount; }
    double get_amount(void) { return this->amount; }
    virtual void processPayment(void) const { std::cout << "Process payment: ProcessMethod" << std::endl; }
};
// _______________Deriver Classes_______________
class CreditCard : public PaymentMethod
{
private:
    std::string card_number_;

public:
    CreditCard(double inputAmount = 0.0, std::string CardNumber = "NA") : card_number_{CardNumber}, PaymentMethod{inputAmount} { std::cout << "Constructor Called: Credit Card.\n"; }
    CreditCard(std::string CardNumber = "NA", double inputAmount = 0.0) : PaymentMethod{inputAmount}, card_number_{CardNumber} { std::cout << "Constructor Called: Credit Card.\n"; }
    ~CreditCard() { std::cout << "Destructor Called: CreditCard.\n"; }
    void processPayment(void) const override { std::cout << "Process payment: amount= " << this->amount << " ,CreaditCard Number= " << this->card_number_ << std::endl; }
};
class PayPal : public PaymentMethod
{
private:
    std::string email_address_;

public:
    PayPal(double inputAmount = 0.0, std::string inputEmail = "NA") : PaymentMethod(inputAmount), email_address_{inputEmail} { std::cout << "Constructor Called: PayPal.\n"; }
    PayPal(std::string inputEmail = "NA", double inputAmount = 0.0) : email_address_{inputEmail}, PaymentMethod{inputAmount} { std::cout << "Constructor Called: PayPal.\n"; }
    ~PayPal() { std::cout << "Destructor Called: PayPal.\n"; }
    void processPayment(void) const override { std::cout << "Process payment: amount= " << this->amount << " ,PayPal Account= " << this->email_address_ << std::endl; }
};

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // // ___SMA___
    // // Create instances of CreditCard and PayPal
    // CreditCard Credit_Card_1 = {150.75, "1234-5678-9012-3456"};
    // PayPal PayPal_Acc_1{2000.50, "user1@gmail.com"};

    // // Call processPayment() Method on each instance.
    // Credit_Card_1.processPayment();
    // PayPal_Acc_1.processPayment();

    // ___DMA___
    // Create instances of CreditCard and PayPal
    CreditCard *Credit_Card_1 = new CreditCard{150.75, "1234-5678-9012-3456"};
    PayPal *PayPal_Acc_1 = new PayPal{2000.50, "user1@gmail.com"};

    // Call processPayment() Method on each instance.
    Credit_Card_1->processPayment(), PayPal_Acc_1->processPayment();

    // delete instaces:
    delete Credit_Card_1, PayPal_Acc_1;

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */

    