#include <iostream>
#include "Employee.h"
// #include "Student.h"

int main()
{
    Employee emp1;
    // emp1.setId(1);
    // emp1.setAge(25);
    // emp1.setName("Hesham");
    // emp1.hire();
    // std::cout << "Country =\t" << emp1.getCountry() << std::endl;
    Employee emp2(2 /*id*/, 26 /*Age*/, "Mohamed Alaa" /*Name*/);

    return 0;
}
