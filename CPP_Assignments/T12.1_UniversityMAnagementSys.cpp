
/*________________________________________________________________________________________________________

    Task(12.1): Hackerrank problem: University Management System:
    -----------------------------------------------------------
    •○□
    Requirements:
        1.  Base Class - Person:
            ○   The class Person will be an abstract class (cannot be instantiated directly) with the following:
                •   Two pure virtual functions:
                    □   getdata(): for inputting data.
                    □   putdata(): for displaying data.
                •   Two data members:
                    □   name: a string representing the name of the person.
                    □   age: an integer representing the age of the person.
        2.  Derived Class - Professor:
            ○   Inherits from the Person class.
            ○   Additional data members:
                •   publications: an integer representing the number of publications.
                •   curr_id: a unique identifier for the professor.
                    It is a static integer that increments each time a new professor is created.
            ○   Overrides the getdata() and putdata() methods:
                •   getdata() should input the name, age, and number of publications.
                •   putdata() should display the name, age, publications, and current professor ID.

        3.  Derived Class - Student:
            ○   Inherits from the Person class.
            ○   Additional data members:
                •   marks_[6]: an array of six integers representing the marks_ of the student.
                •   curr_id: a unique identifier for the student. It is a static integer that
                    increments each time a new student is created.
            ○   Overrides the getdata() and putdata() methods:
                •   getdata() should input the name, age, and six marks_.
                •   putdata() should display the name, age, the sum of the six marks_, and current student ID.

-   Hackerrank URL to submit the solution:
    https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
class Person
{
protected:
    std::string name_;
    int age_;

public:
    Person() { std::cout << "Constructor Called: Person.\n"; }
    ~Person() { std::cout << "Destructor Called: Preson\n"; }
    virtual void getdata(void) = 0;
    virtual void putdata(void) const = 0;
};

class Professor : public Person
{
private:
    int publications_;
    int curr_id_;
    static int id_counter_;

public:
    Professor()
    {
        this->curr_id_++;
        std::cout << "Constructor Called: Professor.\n";
    }
    ~Professor()
    {
        this->curr_id_--;
        std::cout << "Constructor Called: Professor.\n";
    }
    void set_name(std::string N) { this->name_ = N; }
    void getdata() override
    {
        std::cout << "Please Enter Professor Data: \"name / age / number of publications\"." << std::endl;
        std::cin >> name_ >> age_ >> publications_;
    }
    void putdata(void) const override
    {
        std::cout << "Professor: \"" << name_ << "\" ,Age: " << age_ << " ,publications: " << publications_ << "\n";
    }
};
int Professor::id_counter_ = 0;

class Student : public Person
{
private:
    int marks_[6];
    int curr_id_;
    static int id_counter_;

public:
    Student()
    {
        curr_id_ = ++id_counter_;
        std::cout << "Constructor Called: Student.\n";
    }
    ~Student()
    {
        id_counter_--;
        std::cout << "Destructor Called: Student.\n";
    }

    void getdata() override
    {
        std::cout << "Please Enter Student Data: \"name / age \"." << std::endl;
        std::cin >> name_ >> age_;
        std::cout << "Please Enter Student Marks for the 6 subjects.\n";
        for (int &mark : marks_)
            std::cin >> mark;
    }

    void putdata() const override
    {
        int total = 0;
        for (int mark : marks_)
            total += mark;
        std::cout << "Student: " << name_ << " " << age_ << " " << total << " " << curr_id_ << std::endl;
    }
};

int Student::id_counter_ = 0;

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    int n;
    std::cout << "Enter Number of Persons:\t";
    std::cin >> n; // Number of objects

    Person *people[n];

    for (int i = 0; i < n; ++i)
    {
        int type;
        std::cout << "Please Select Person Type: 1 for Professor, 2 for Student:\t";
        std::cin >> type; // 1 for Professor, 2 for Student

        if (type == 1)
            people[i] = new Professor();
        else
            people[i] = new Student();

        people[i]->getdata();
    }

    for (int i = 0; i < n; ++i)
    {
        people[i]->putdata();
        delete people[i]; // Clean up
    }

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
