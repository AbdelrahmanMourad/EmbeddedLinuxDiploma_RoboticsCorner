#include <iostream>
#include <vector>    // for Vectors
#include <algorithm> // for lambdaa expression
#include "Employee.h"
#include "Student.h"

// NOTE: constructor - Function that is called "Automatically" when we inialize class.
// NOTE: Destructor - Function that is called "Automatically" when we object class scope ends.

// Name mangling {"className::MethodName"}
void Employee::hire() { std::cout << "Employee " << name << " is hired\n"; }
void Employee::setId(int id) { this->id = id; }
void Employee::setName(std::string name) { this->name = name; }
void Employee::setAge(int age) { this->age = age; }
int Employee::getId() { return this->id; }
int Employee::getAge() { return this->age; }
std::string Employee::getName() { return this->name; }
std::string Employee::getCountry()
{
    this->country = "Egypt";
    return country;
}
void Employee::PrintSeparator(void)
{
    std::cout << "---------------------------\n";
}

/*_______________Constructors____________________
 */
// default constructor {1}
Employee::Employee() /*Constructor Initializers....*/ : id{-1}, name{"Unknown"}, age{60}, salary{0}
{
    PrintSeparator();
    std::cout << "default constructor\n";
    PrintSeparator();
}
// Parameterized constructor (2)
Employee::Employee(int id, int age, std::string name) : id{id}, name{name}, age{age}, salary{salary} /*Constructor Initializers*/
{
    this->id = id;
    this->age = age;
    this->name = name;
    std::cout << "Parameterized Constructor:" << "\n\tid:\t" << this->id << "\n\tage:\t" << this->age << "\n\tname:\t" << this->name << std::endl;
    PrintSeparator();
}

/*_______________Destructors____________________
 */
// Called atomatically
Employee::~Employee()
{
    std::cout << "Employee with id:\t" << this->id << "\tDestructor is called\n";
    PrintSeparator();
}