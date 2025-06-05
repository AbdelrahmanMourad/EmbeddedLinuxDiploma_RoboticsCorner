/*
================================================================================
|   C++ Inheritance, Polymorphism, and Class Relationships - Study Summary
|-------------------------------------------------------------------------------
| Inheritance:
| - Mechanism to derive a new class (child) from an existing class (parent).
| - Child class inherits members (attributes and methods) of the parent class.
| - Types:
|     * Public Inheritance: "is-a" relationship (most common).
|     * Protected Inheritance: Inherited members become protected in the child.
|     * Private Inheritance: Inherited members become private in the child.
|
| Polymorphism:
| - Ability to use a derived class object as if it were a base class object.
| - Achieved through virtual functions and function overriding.
| - Types:
|     * Compile-time (static): Function overloading, operator overloading.
|     * Runtime (dynamic): Virtual functions, achieved via pointers/references.
|
| Class Relationships:
| - Composition: "has-a" relationship. One class contains another as a member.
| - Aggregation: "has-a" relationship, but the contained object is passed externally.
| - Association: General relationship where one class uses another.
| - Dependency: "uses-a" relationship, where one class temporarily uses another.
|
| Interview Q&A at the end.
================================================================================
*/

#include <iostream>
#include <string>
#include <vector>

// --- Base and Derived Classes (Inheritance) ---
class Animal // Base class
{
public:
    Animal(const std::string &name) : name(name) {}
    virtual void Speak() const { std::cout << name << " makes a sound.\n"; }
    virtual ~Animal() {}

protected:
    std::string name;
};

class Dog : public Animal // Derived class
{
public:
    Dog(const std::string &name) : Animal(name) {}
    void Speak() const override { std::cout << name << " barks.\n"; }
};

class Cat : public Animal // Derived class
{
public:
    Cat(const std::string &name) : Animal(name) {}
    void Speak() const override { std::cout << name << " meows.\n"; }
};

// --- Composition ---
class Engine
{
public:
    void Start() { std::cout << "Engine starts.\n"; }
};

class Car
{
public:
    Car() : engine(new Engine()) {}
    ~Car() { delete engine; }
    void Drive() { engine->Start(); std::cout << "Car drives.\n"; }

private:
    Engine *engine; // Composition: Car "has-a" Engine
};

// --- Aggregation ---
class Department
{
public:
    void AddStudent(const std::string &student) { students.push_back(student); }
    void ListStudents()
    {
        std::cout << "Students in department:\n";
        for (const auto &student : students)
            std::cout << "- " << student << "\n";
    }

private:
    std::vector<std::string> students; // Aggregation: Department "has-a" collection of students
};

// --- Association ---
class Teacher
{
public:
    void Teach(const Department &dept) { std::cout << "Teaching a department.\n"; }
};

// --- Dependency ---
class Printer
{
public:
    void Print(const std::string &doc) { std::cout << "Printing: " << doc << "\n"; }
};

class Office
{
public:
    void UsePrinter(Printer &printer, const std::string &doc)
    {
        printer.Print(doc); // Dependency: Office "uses-a" Printer
    }
};

int main()
{
    // --- Inheritance and Polymorphism ---
    Animal *dog = new Dog("Buddy");
    Animal *cat = new Cat("Whiskers");
    dog->Speak(); // Runtime polymorphism
    cat->Speak();
    delete dog;
    delete cat;

    // --- Composition ---
    Car car;
    car.Drive();

    // --- Aggregation ---
    Department dept;
    dept.AddStudent("Alice");
    dept.AddStudent("Bob");
    dept.ListStudents();

    // --- Association ---
    Teacher teacher;
    teacher.Teach(dept);

    // --- Dependency ---
    Printer printer;
    Office office;
    office.UsePrinter(printer, "Report.pdf");

    return 0;
}

/*
================================================================================
|   Interview Questions & Answers - Inheritance, Polymorphism, and Relationships
|-------------------------------------------------------------------------------
| Q1: What is the difference between inheritance and composition?
| A1: Inheritance is an "is-a" relationship (e.g., Dog is an Animal). Composition is a "has-a"
|     relationship (e.g., Car has an Engine).
|
| Q2: What is polymorphism in C++?
| A2: Polymorphism allows using a derived class object as if it were a base class object.
|     Achieved through virtual functions and function overriding.
|
| Q3: What is the difference between public, protected, and private inheritance?
| A3: Public inheritance keeps the base class's public/protected members as-is.
|     Protected inheritance makes public members protected in the child.
|     Private inheritance makes all inherited members private in the child.
|
| Q4: What is the difference between aggregation and composition?
| A4: Both are "has-a" relationships. In composition, the contained object is created and
|     destroyed with the container. In aggregation, the contained object is passed externally
|     and can exist independently.
|
| Q5: What is the difference between overriding and overloading?
| A5: Overriding is redefining a base class's virtual function in a derived class.
|     Overloading is defining multiple functions with the same name but different parameters.
|
| Q6: What is the purpose of virtual functions?
| A6: Virtual functions enable runtime polymorphism, allowing derived class behavior to be
|     invoked through a base class pointer/reference.
|
| Q7: What is the difference between association and dependency?
| A7: Association is a general relationship where one class uses another. Dependency is a
|     specific "uses-a" relationship, often temporary.
|
| Q8: What is the role of destructors in composition?
| A8: Destructors ensure proper cleanup of dynamically allocated objects in composition.
================================================================================
*/