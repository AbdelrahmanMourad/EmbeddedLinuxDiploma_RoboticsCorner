/*________________________________________________________________________________________________________

    Task(6.3):
    ----------

    Banking System with Namespaces:

    Create a C++ program that uses namespaces to organize code related to different types of bank accounts.

    Define namespaces for SavingsAccount and CheckingAccount, and then use these namespaces to simulate some banking operations.

    Instructions:
        1.Define Namespaces and Functions:
            o Create two namespaces:
                ▪ SavingsAccount for managing savings account operations.
                ▪ CheckingAccount for managing checking account operations.

            o Inside the SavingsAccount namespace, define the following functions:
                ▪ createAccount(double initialBalance) - Creates a savings account with the specified initial balance.
                ▪ addInterest(double rate) - Adds interest to the savings account balance based on the given annual interest rate.
                ▪ getBalance() - Returns the current balance of the savings account.

            o Inside the CheckingAccount namespace, define the following functions:
                ▪ createAccount(double initialBalance) - Creates a checking account with the specified initial balance.
                ▪ applyFee(double fee) - Applies a transaction fee to the checking account balance.
                ▪ getBalance() - Returns the current balance of the checking account.

        2.Create a Main Program:
            o Use the functions from both namespaces to create and manage savings and checking accounts.
            o Print the results of these operations to the console.

___________________________________________________________________________________________________________*/

#include <iostream>
#include <string>

/* Customer Struct */
struct Customer
{
    std::string name;
    int id;
    double savingsBalance;
    double checkingBalance;

    // Parameterized Constructor.
    Customer(std::string customerName, int customerId)
        : name(customerName), id(customerId), savingsBalance(0), checkingBalance(0) {}
};

/* Namespaces */
namespace SavingsAccount
{
    void createAccount(Customer &customer, double initialBalance)
    {
        customer.savingsBalance = initialBalance;
    }

    void addInterest(Customer &customer, double rate)
    {
        customer.savingsBalance += customer.savingsBalance * (rate / 100);
    }

    double getBalance(const Customer &customer)
    {
        return customer.savingsBalance;
    }
}

namespace CheckingAccount
{
    void createAccount(Customer &customer, double initialBalance)
    {
        customer.checkingBalance = initialBalance;
    }

    void applyFee(Customer &customer, double fee)
    {
        customer.checkingBalance -= fee;
    }

    double getBalance(const Customer &customer)
    {
        return customer.checkingBalance;
    }
}

/* Entry Point */
int main()
{
    // Create a customer
    Customer customer1("Abdelrahman", 101);

    // Assign accounts to the customer
    SavingsAccount::createAccount(customer1, 1000);
    CheckingAccount::createAccount(customer1, 500);

    // Perform operations
    SavingsAccount::addInterest(customer1, 5); // Add 5% interest
    CheckingAccount::applyFee(customer1, 15);  // Apply transaction fee of $15

    // Print results
    std::cout << "Customer: " << customer1.name << " (ID: " << customer1.id << ")\n";
    std::cout << "Savings Account Balance: $" << SavingsAccount::getBalance(customer1) << std::endl;
    std::cout << "Checking Account Balance: $" << CheckingAccount::getBalance(customer1) << std::endl;

    return 0;
}