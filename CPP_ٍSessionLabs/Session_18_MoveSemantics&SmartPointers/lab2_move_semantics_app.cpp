#include <iostream>

/*  ===============================================================================
                        Declarations
    =============================================================================== */
class Person
{
private:
    std::string name_;
    double salary_;
    int id_;

public:
    ~Person() { std::cout << "Destructor Called: Person.\n"; }
    Person(int id, std::string name, double salary) : id_{id}, name_{name}, salary_{salary} { std::cout << "Constructor Called: Person.\n"; }
    Person(const Person &copy) /*Copy Constructor*/
    {
        this->id_ = copy.id_;
        this->name_ = copy.name_;
        this->salary_ = copy.salary_;
        std::cout << "Constructor Called: Person Copy Constructor.\n";
    }
    void Display() { std::cout << "Name= " << name_ << "\tid= " << id_ << "\tSalary= " << salary_ << "\n"; }
};

/*  ===============================================================================
                        ProtoTypes
    =============================================================================== */
int GetValue();
int &GetValueRef();
void PrintName(std::string &name);  // &
void PrintName(std::string &&name); // &&
void Print_Person(Person &P) { std::cout<<"Rvalue Display Invoked. "; P.Display();}
void Print_Person(Person &&P) { std::cout<<"Rvalue Display Invoked. "; P.Display(); }

/*  ===============================================================================
                        Main Function / Entry Point
    =============================================================================== */
int main()
{
    int i = GetValue();       // OK
    int &var = GetValueRef(); // OK

    // 10 = i;         // ERROR, You can't do that.. assign Rvalue to Lvalue.
    // GetValue() = i; // ERROR, You can't do that.. assign Rvalue to Lvalue.

    std::string firstName = "Robotics"; // temp obj. (Rvalue)
    std::string lastName = "Corner";    // temp obj. (Rvalue)

    std::string fullName = firstName + " " + lastName;

    PrintName(fullName); // (Lvalue).

    PrintName(firstName + lastName); // temp obj. (Rvalue)

    /*___________________________________________________________*/
    Person player{11, "Mohamed Salah", 20000};           // Lvalue Created.
    Print_Person(player);                                // Lvalue Ref & invoked.
    Print_Person(Person{7, "Cristiano Ronaldo", 40000}); // temp.. Rvalue Ref & invoked.

    return 0;
}

/*  ===============================================================================
                        Implementation
    =============================================================================== */
int GetValue()
{ /*Data Segment*/
    int value = 15;
    return value;
}
int &GetValueRef()
{ /*Data Segment*/
    static int value = 15;
    return value;
}
void PrintName(std::string &name) /*&*/ { std::cout << "Left Value Reference" << "..." << name << ".\n"; }
void PrintName(std::string &&name) /*&&*/ { std::cout << "Right Value Reference" << "..." << name << ".\n"; }
// void PrintName(std::string name) /*ERROR, both it and && can be used, so makes conflicts together*/ { std::cout << "Right Value Reference" << "..." << name << ".\n"; }