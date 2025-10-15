#include <iostream>
#include <vector>    // for Vectors
#include <algorithm> // for lambdaa expression
#include "Employee.h"
#include "Student.h"

/*  -------------------------------------------------------------------
    Session Agenda:
    ---------------
        - Intro to OOP.
            Enacpsulation (Variables , Methods)

    -------------------------------------------------------------------
*/
/*  -------------------------------------------------------------------

    -------------------------------------------------------------------
*/

int main()
{
    Employee emp1;
    emp1.setId(1);
    emp1.setAge(25);
    emp1.setName("Hesham");
    emp1.hire();
    std::cout << "Country =\t" << emp1.getCountry() << std::endl;

    return 0;
}

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