#include <iostream>
#include <vector>    // for Vectors
#include <algorithm> // for lambdaa expression

/*  -------------------------------------------------------------------
    Session Agenda:
    ---------------
        - More on OOP.
            => const class
                - 

    -------------------------------------------------------------------
*/
/*  -------------------------------------------------------------------
                Object Oriented Programming (OOP)
    -------------------------------------------------------------------
    Classes Types:
    --------------
        Polymorphic : متعدد الاشكال
        Value Classes :
        RAII(REsource Aquisition Is Initialization) :


    -------------
    Access Level:
    -------------
        private     -
        public      +
        protected   #

    ------------
    Inheritance:
    ------------

    --------------------------------------------------------------------
    [MISRA Rule]:   When you find struct using functions... turn it into class
    --------------------------------------------------------------------
*/

namespace HelpingFunctions
{
    // print separator function.
    void PrintSeparatorFn(void)
    {
        std::cout << "---------------------\n";
    }
    // Print Text.
    void PrintTextFn(std::string text)
    {
        std::cout << text << std::endl;
    }
}

// class is private accessible by default.
// struct is public by default.
class Employee
{
public:
    void hire()
    {
        std::cout << "Employee " << name << " is hired\n";
    }
    void setId(int id)
    {
        // id = id;
        this->id = id;
        // this is pointer to the current member inside the object class.
    }
    void setName(std::string name)
    {
        this->name = name;
        // this is pointer to the current member inside the object class.
    }
    void setAge(int age)
    {
        this->age = age;
        // this is pointer to the current member inside the object class.
    }
    std::string getCountry()
    {
        this->country = "Egypt";
        return country;
    }

private:
    int id;
    int age;
    std::string name;
    std::string country;
};

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
