#include <iostream>
#include "Employee.h"
// #include "Student.h"

// Const class
void Foo(const Employee& emp)
{
    // emp.setId(55); // ERROR -> as const (it's a read-only)
}




int main()
{
    // Employee emp1;       // Call Default constructor
    // emp1.setId(1);
    // emp1.setAge(25);
    // emp1.setName("Hesham");
    // emp1.hire();
    // std::cout << "Country =\t" << emp1.getCountry() << std::endl;

    Employee *Emp2 = new Employee(2,25, 1000, "Mohamed Alaa");
    Emp2->hire();   


    return 0;
}


/*
    NOTES:
        constructor Initializer:
            as called before calling the constructor it can break 2 rules.
                - initiaize const variable
                - initialize reference&.
        
*/

/*
    Delegate constructor (C++11)
*/