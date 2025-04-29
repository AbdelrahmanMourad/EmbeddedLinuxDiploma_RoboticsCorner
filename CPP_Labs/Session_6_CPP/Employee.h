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

    // Parameterized constructor (2)
    Employee(int id, int age, std::string name);
    // Copy Constructor {3}
    // Move Constructor {4}

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

    // Destructor
    ~Employee();

private:
    /* NOTE: Google style would be id_ , age_ , name_ , country_    */
    int id;
    int age;
    std::string name;
    std::string country;
    const int salary;
    /*
        FEATURE: we can modify const data in the class members, using constructor initializer.
    */
};

/*
    Search:
        Rule of Five
            https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
*/