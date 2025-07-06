#include <iostream>
#include <memory>
#include <utility>

class Processor
{

private:
    std::string type_;

public:
    Processor(std::string type) : type_{type} {}
    void print_type() { std::cout << "Processor Type= " << this->type_ << std::endl; }
};

class Computer
{
private:
public:
    Computer(std::unique_ptr<Processor> ptr1) { ptr1->print_type(); }
};

int main()
{

    std::unique_ptr<Processor> p1 = std::make_unique<Processor>("Intel");

    Computer my_comp(std::move(p1));

    return 0;
}