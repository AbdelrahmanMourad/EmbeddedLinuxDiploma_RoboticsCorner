// class is private accessible by default.
// struct is public by default.
/*-------------------Class Declaration-------------------*/

class Employee
{
public:
    /**
     *   Constructor initializer=> Eployee(): this->id{idValue},this->name{nameValue},this->age{ageValue}
     */
    // default constructor {1}
    Employee();
    Employee(int id, int age);
    Employee(int id, int age, std::string name);
    Employee(int id, int age, const int salary, std::string name);
    ~Employee();
    // Copy Constructor {3}
    // Move Constructor {4}
    // Delegate Constructor {5}

    Employee::Employee();
    // Employee::Employee() /*Constructor Initializers....*/// : id{-1}, name{"Unknown"}, age{60}, salary{0}
    // {
    //     PrintSeparator();
    //     std::cout << "default constructor\n";
    //     PrintSeparator();
    // }
    // Parameterized constructor (2)

    // _________________Print Methods_________________
    void hire();
    // _________________Setters_________________
    void setId(int id);
    void setName(std::string name);
    void setAge(int age);
    // _________________Getters_________________
    std::string getCountry();
    std::string getName();
    int getId();
    int getAge();
    void PrintSeparator(void);
    void display() const; // Here are qualifier like {const} defined at the end in cpp, in c-style it's differest {SEARCH}

    // Destructor
    ~Employee();

private:
    /* NOTE: Google style would be id_ , age_ , name_ , country_    */
    int id;
    int age;
    // int& age;   // int x=8; int& age=x;
    // int emp1_age= 25;
    // Employee(int id, int&  age, const int salary, std::string name);
    // Employee emp2(2 /*id*/, emp1_age /*Age*/, 5000,"Mohamed Alaa" /*Name*/);
    std::string name;
    std::string country;
    // const int salary;
    int salary;
    /*
        FEATURE: we can modify const data in the class members, using constructor initializer.
    */
};

/*
    Search:
        Rule of Five
            https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
*/