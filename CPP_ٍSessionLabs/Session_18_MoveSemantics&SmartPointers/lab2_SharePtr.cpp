/*
================================================================================
|   C++ Move Semantics and Smart Pointers
================================================================================
*/

/*  ================================================================================
                            Included Libraries
    ================================================================================ */
#include <iostream> // For std::cout, std::cin
#include <memory>   // For smart pointers like std::unique_ptr, std::shared_ptr, std::weak_ptr
#include <utility>  // For std::move

/*  ================================================================================
                            Definitions
    ================================================================================ */
class Processor
{
public:
    Processor(std::string type) : type{type} { std::cout << "Processor constructor called \n"; }
    void print_type() { std::cout << "Processor type: " << type << std::endl; }

private:
    std::string type;
};

class Computer
{
public:
    Computer(std::unique_ptr<Processor> ptr1)
    {
        ptr1->print_type();
    }
};

/*  ================================================================================
                            Main() - Entry Point
    ================================================================================ */
int main()
{
    std::unique_ptr<Processor> p1 = std::make_unique<Processor>("intel"); // Create a unique_ptr to a Processor object

    Computer my_computer(std::move(p1)); // Move ownership of p1 to my_computer

    return 0;
}

/*  ================================================================================
                            Implementations
    ================================================================================ */