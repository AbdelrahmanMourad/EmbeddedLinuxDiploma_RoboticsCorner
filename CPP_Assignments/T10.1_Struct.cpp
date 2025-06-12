
/*________________________________________________________________________________________________________

    Task(10.1): C++ Student class:
    ------------------------------

        Instructions:
            create a student class with the following fields,
                Id
                Age.
                Name.

        Each field should have there setter and getter functions.
        Add a function to display the info of an object of that class.

        Use Student class in the main to create 2 or 3 objects and display there fields
        using the info function mentioned before.
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Declarations / Functions Prototype
    ------------------------------------------------------------------- */
// #pragma pack 4;
class Student
{
private:
    std::string Name_;
    int Id_;
    int Age_;

public:
    // Constructor, Destructor.
    Student(std::string n = "___", int id = 0, char age = 0) : Name_{n}, Id_{id}, Age_{age} { std::cout << "Constructor called of Student: \'" << this->Name_ << "\'\n"; }
    ~Student() { std::cout << "Destructor called of Student: \'" << this->Name_ << "\'\n"; }
    // Setters:
    // void set_name(std::string n) { this->Name_ = n; }   // 2 Copy, 0 Move.  // Bad for large strings → High memory and CPU overhead.
    void set_name(std::string &n) { this->Name_ = n; }  // 1 Copy, 0 Move.
    void set_name(std::string &&n) { this->Name_ = n; } // 0 Copy, 1 Move.
    void set_id(int &id) { this->Id_ = id; }
    void set_id(int &&id) { this->Id_ = id; }
    void set_age(char &age) { this->Age_ = age; }
    void set_age(char &&age) { this->Age_ = age; }
    // Getters:
    std::string get_name(void) { return this->Name_; }
    int get_id(void) { return this->Id_; }
    char get_age(void) { return this->Age_; }
    // Functions.
    void Display(void) { std::cout << "Name= " << Name_ << "\t,ID= " << Id_ << "\t,Age= " << Age_ << std::endl; /*Could use the getter if filters needed*/ }
};

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
main()
{
    // Create 3 instances.
    Student student1{"Ahmed", 101, 23};
    Student student2{"Mohamed", 102, 22};
    Student student3;

    // use the setters
    student3.set_name("Ibrahim");
    student3.set_id(103);
    student3.set_age(23);

    // Display.
    student1.Display();
    student2.Display();
    student3.Display();

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
