/*
================================================================================
|   OOP Relationships: Summary & Examples
|-------------------------------------------------------------------------------
| 1. "Is-a" (Inheritance):
|    - Expresses specialization/generalization.
|    - Implemented via class inheritance.
|    - Example: class Dog : public Animal {};
|
| 2. "Has-a" (Composition/Aggregation):
|    - Expresses whole-part relationship.
|    - Composition: Strong ownership (part cannot exist without whole).
|    - Aggregation: Weak ownership (part can exist independently).
|    - Example (Composition): class Car { Engine engine; };
|    - Example (Aggregation): class Team { std::vector<Player*> players; };
|
| 3. "Uses-a" (Association/Dependency):
|    - Expresses that a class uses another class temporarily.
|    - Implemented by passing objects as parameters or using them locally.
|    - Example: class Doctor { void CheckPatient(Stethoscope& s); };
|
| 4. "Part-of" (Aggregation vs. Composition):
|    - Aggregation: "Has-a" with independent lifetime.
|    - Composition: "Has-a" with dependent lifetime.
|
| 5. UML Notation:
|    - Inheritance: solid line with closed arrow.
|    - Composition: solid diamond.
|    - Aggregation: hollow diamond.
|    - Association: solid line.
================================================================================
|   50 Interview Questions & Answers on OOP Relationships
|-------------------------------------------------------------------------------
| 1.  Q: What is an "is-a" relationship in OOP?
|     A: It represents inheritance, where one class is a specialized type of another.
| 2.  Q: What is a "has-a" relationship?
|     A: It represents composition or aggregation, where one class contains another as a part.
| 3.  Q: What is a "uses-a" relationship?
|     A: It represents association or dependency, where one class uses another to perform a task.
| 4.  Q: How is inheritance implemented in C++?
|     A: Using the ':' syntax, e.g., class Sub : public Super {}.
| 5.  Q: What is composition?
|     A: A strong "has-a" relationship where the part cannot exist without the whole.
| 6.  Q: What is aggregation?
|     A: A weak "has-a" relationship where the part can exist independently of the whole.
| 7.  Q: Give an example of composition in C++.
|     A: class Car { Engine engine; };
| 8.  Q: Give an example of aggregation in C++.
|     A: class Team { std::vector<Player*> players; };
| 9.  Q: How is association different from aggregation?
|     A: Association is a general relationship; aggregation is a specific type of association with ownership semantics.
| 10. Q: What is dependency in OOP?
|     A: When one class depends on another to function, usually by using it as a parameter or local variable.
| 11. Q: What keyword is used for inheritance in C++?
|     A: public, protected, or private after the colon.
| 12. Q: Can a class inherit from multiple classes in C++?
|     A: Yes, C++ supports multiple inheritance.
| 13. Q: What is the base class?
|     A: The class being inherited from.
| 14. Q: What is the derived class?
|     A: The class that inherits from the base class.
| 15. Q: What is method overriding?
|     A: Redefining a base class method in the derived class.
| 16. Q: What is the purpose of 'virtual' keyword?
|     A: To allow derived classes to override base class methods for polymorphism.
| 17. Q: What is upcasting?
|     A: Treating a derived class object as a base class object.
| 18. Q: What is downcasting?
|     A: Casting a base class pointer/reference to a derived class type.
| 19. Q: What is the diamond problem?
|     A: Ambiguity caused by multiple inheritance when two base classes inherit from the same ancestor.
| 20. Q: How is the diamond problem solved in C++?
|     A: Using virtual inheritance.
| 21. Q: How do you implement composition in C++?
|     A: By including an object as a member variable.
| 22. Q: How do you implement aggregation in C++?
|     A: By including a pointer or reference to another object.
| 23. Q: What happens to composed objects when the container is destroyed?
|     A: They are destroyed as well.
| 24. Q: What happens to aggregated objects when the container is destroyed?
|     A: They are not destroyed; they can exist independently.
| 25. Q: Give a real-world example of composition.
|     A: A House has Rooms.
| 26. Q: Give a real-world example of aggregation.
|     A: A Team has Players who can exist outside the team.
| 27. Q: Can you have both composition and aggregation in the same class?
|     A: Yes.
| 28. Q: What is the difference between strong and weak ownership?
|     A: Strong ownership (composition) means the part cannot exist without the whole; weak ownership (aggregation) means it can.
| 29. Q: How does C++ manage memory for composition?
|     A: Automatically, as part of the containing object.
| 30. Q: How does C++ manage memory for aggregation?
|     A: The programmer must manage the lifetime of aggregated objects.
| 31. Q: How is association implemented in C++?
|     A: By passing objects as parameters or storing references/pointers.
| 32. Q: What is a unidirectional association?
|     A: Only one class knows about the other.
| 33. Q: What is a bidirectional association?
|     A: Both classes know about each other.
| 34. Q: Give an example of dependency in C++.
|     A: void Print(Document& doc); — Print depends on Document.
| 35. Q: Is association always permanent?
|     A: No, it can be temporary (method parameter) or permanent (member variable).
| 36. Q: What is the difference between association and dependency?
|     A: Dependency is a special case of association, usually temporary.
| 37. Q: Can association exist without inheritance?
|     A: Yes.
| 38. Q: Can a class have multiple associations?
|     A: Yes.
| 39. Q: What is multiplicity in association?
|     A: The number of objects involved in the relationship (one-to-one, one-to-many, etc.).
| 40. Q: How is multiplicity represented in C++?
|     A: Using containers like std::vector for one-to-many.
| 41. Q: How are OOP relationships represented in UML?
|     A: Inheritance: solid line with closed arrow; Composition: solid diamond; Aggregation: hollow diamond; Association: solid line.
| 42. Q: What is a dependency arrow in UML?
|     A: A dashed arrow showing that one class depends on another.
| 43. Q: Can a class be part of multiple relationships?
|     A: Yes.
| 44. Q: What is a reflexive association?
|     A: A class associated with itself.
| 45. Q: What is a qualified association?
|     A: An association with a qualifier (like a key or index).
| 46. Q: What is a navigability in association?
|     A: Indicates which direction the association can be traversed.
| 47. Q: What is a composite aggregation?
|     A: Another term for composition.
| 48. Q: What is the main benefit of using composition over inheritance?
|     A: Greater flexibility and less coupling.
| 49. Q: When should you use inheritance?
|     A: When there is a clear "is-a" relationship and shared behavior.
| 50. Q: When should you use composition?
|     A: When you want to build complex types from simpler ones and allow for more flexible designs.
================================================================================
*/

<<<<<<< HEAD
/*  ================================================================================
                                Included Libraries
    ================================================================================    */
=======
/*
========================================================================================================
Polymorphism, Casting, and OOP Relationships in C++ - Summary & Interview Q&A
========================================================================================================
| Polymorphism:
| - Enables using base class pointers/references to refer to derived class objects.
| - Requires at least one virtual function in the base class.
| - Allows dynamic dispatch (runtime binding) of overridden methods.
|
| Casting in C++:
| 1. static_cast<T>(expr): Compile-time cast for related types (safe upcast, unchecked downcast).
|    - Example: Base* b = new Derived(); Derived* d = static_cast<Derived*>(b);
| 2. dynamic_cast<T>(expr): Runtime-checked cast for polymorphic types (base must have virtual function).
|    - Example: Base* b = new Derived(); Derived* d = dynamic_cast<Derived*>(b); // d != nullptr if b is Derived
| 3. reinterpret_cast<T>(expr): Bitwise cast, for unrelated types (dangerous, rarely used).
|    - Example: int* p = reinterpret_cast<int*>(0x1234);
| 4. const_cast<T>(expr): Adds/removes const/volatile qualifier.
|    - Example: const int* p = ...; int* q = const_cast<int*>(p);
| 5. C-style cast: (T)expr or T(expr). Tries static_cast, const_cast, reinterpret_cast in order.
|    - Not recommended in modern C++.
| 6. dynamic_pointer_cast<T>(shared_ptr<U>): Safe downcast for shared_ptr, returns nullptr if fails.
|    - Example: std::shared_ptr<Base> b = ...; auto d = std::dynamic_pointer_cast<Derived>(b);
| 7. static_pointer_cast<T>(shared_ptr<U>): Compile-time cast for shared_ptr.
|    - Example: auto d = std::static_pointer_cast<Derived>(b);
|
| Common Interview Questions & Answers on Polymorphism and Casting:
| 1. Q: What is polymorphism?
|    A: The ability to treat objects of different derived types as objects of a common base type, enabling dynamic method dispatch.
| 2. Q: What is a virtual function?
|    A: A function declared with 'virtual' in the base class, allowing derived classes to override it for runtime polymorphism.
| 3. Q: What is pure virtual function?
|    A: A virtual function with '= 0', making the class abstract (cannot instantiate).
| 4. Q: What is upcasting?
|    A: Casting a derived class pointer/reference to a base class type (always safe).
| 5. Q: What is downcasting?
|    A: Casting a base class pointer/reference to a derived class type (safe only with dynamic_cast and polymorphic base).
| 6. Q: When do you use dynamic_cast?
|    A: When you need to safely downcast in a class hierarchy with virtual functions.
| 7. Q: What happens if dynamic_cast fails?
|    A: For pointers, returns nullptr; for references, throws std::bad_cast.
| 8. Q: Why must the base class be polymorphic for dynamic_cast?
|    A: RTTI (runtime type information) is only available for classes with at least one virtual function.
| 9. Q: What is object slicing?
|    A: When a derived object is assigned to a base object by value, losing the derived part.
| 10. Q: What is the difference between static_cast and dynamic_cast?
|     A: static_cast is compile-time and unchecked; dynamic_cast is runtime-checked and safe for downcasting.
| 11. Q: Can you dynamic_cast with unique_ptr?
|     A: No direct helper; use raw pointer and reconstruct unique_ptr if needed.
| 12. Q: What is the diamond problem?
|     A: Ambiguity from multiple inheritance; solved with virtual inheritance.
| 13. Q: What is the difference between composition and aggregation?
|     A: Composition: strong ownership (part destroyed with whole); Aggregation: weak ownership (part can outlive whole).
| 14. Q: What is the purpose of a virtual destructor?
|     A: Ensures proper cleanup of derived objects when deleting via base pointer.
| 15. Q: What is RTTI?
|     A: Run-Time Type Information, used for dynamic_cast and typeid.
========================================================================================================
| Example: All Cases of Casting
--------------------------------------------------------------------------------------------------------
class Base { public: virtual ~Base() {} };
class Derived : public Base { public: void foo() {} };

Base* b = new Derived();
Derived* d1 = static_cast<Derived*>(b);   // Unsafe downcast, no check
Derived* d2 = dynamic_cast<Derived*>(b);  // Safe downcast, d2 != nullptr if b is Derived
Base* b2 = static_cast<Base*>(d2);        // Upcast, always safe

const int* ci = new int(5);
int* i = const_cast<int*>(ci);            // Remove constness

int n = 42;
void* vp = &n;
int* ip = reinterpret_cast<int*>(vp);     // Bitwise cast

// C-style cast (not recommended)
Derived* d3 = (Derived*)b;

// Smart pointer casting
std::shared_ptr<Base> spb = std::make_shared<Derived>();
std::shared_ptr<Derived> spd1 = std::dynamic_pointer_cast<Derived>(spb); // Safe
std::shared_ptr<Derived> spd2 = std::static_pointer_cast<Derived>(spb);  // Unsafe, no check
========================================================================================================
*/

>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
#include <iostream>
#include <vector>
#include <string>

<<<<<<< HEAD
/*  ================================================================================
                                Declarations / Prototypes
    ================================================================================    */

/*
---------------------------------------------------------
1. "_______Is-a_______" Relationship Example: Inheritance
---------------------------------------------------------
*/
=======
// 1. "Is-a" Relationship Example: Inheritance
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
class Super
{
public:
    Super() { std::cout << "Constructor Called: Super.\n"; }
    virtual void Method1() { std::cout << "SuperClass.Method1().\n"; }
    virtual void Method2() { std::cout << "SuperClass.Method1().\n"; }
    ~Super() { std::cout << "Destructor Called: Super.\n"; }
    // virtual ~Super() = 0;
};

class Sub : public Super
{
public:
    Sub() { std::cout << "Constructor Called: Sub.\n"; }
    void Method1() override { std::cout << "SubClass.Method1().\n"; }
    void Method2() override { std::cout << "SubClass.Method2().\n"; }
    ~Sub() { std::cout << "Destructor Called: Sub.\n"; }
    // ~Sub() override { std::cout << "Destructor Called: Sub.\n"; }
};

<<<<<<< HEAD
/*
----------------------------------------------------------
2. "_______Has-a_______" Relationship Example: Composition  "تركيب"
----------------------------------------------------------
*/
=======
// 2. "Has-a" Relationship Example: Composition
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
class Engine
{
public:
    void Start() { std::cout << "Engine started.\n"; }
};

class Car
{
private:
    Engine engine; // Car has an Engine (composition)
public:
    void Start() { engine.Start(); }
};

<<<<<<< HEAD
/*
----------------------------------------------------------
3. "_______Has-a_______" Relationship Example: Aggregation  "تجميع"
----------------------------------------------------------
*/
=======
// 3. "Has-a" Relationship Example: Aggregation
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
class Player
{
public:
    std::string name;
    Player(const std::string &n) : name(n) {}
};

class Team
{
private:
    std::vector<Player *> players; // Team has Players (aggregation)
public:
    void AddPlayer(Player *p) { players.push_back(p); }
    void ListPlayers()
    {
        std::cout << "Team players: ";
        for (auto p : players)
            std::cout << p->name << " ";
        std::cout << std::endl;
    }
};

<<<<<<< HEAD
/*
----------------------------------------------------------------------
4. "_______Uses-a_______" Relationship Example: Association/Dependency
----------------------------------------------------------------------
*/
=======
// 4. "Uses-a" Relationship Example: Association/Dependency
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
class Stethoscope
{
public:
    void Listen() { std::cout << "Listening to heartbeat.\n"; }
};

class Doctor
{
public:
    void CheckPatient(Stethoscope &s) { s.Listen(); }
};

<<<<<<< HEAD
/*
-------------------------------------------------------------------
5. "_______Part-of_______" Relationship: Composition vs Aggregation
-------------------------------------------------------------------
*/
=======
// 5. "Part-of" Relationship: Composition vs Aggregation
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
class Room
{
};

class House
{
private:
    Room room; // Composition: Room is created/destroyed with House
};

class Employee
{
};

class Department
{
private:
    std::vector<Employee *> employees; // Aggregation: pointers, not ownership
};

<<<<<<< HEAD
/*  ================================================================================
                                Main - Entry point
    ================================================================================    */
=======
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
int main()
{
    std::cout << "=== Is-a (Inheritance) Example ===\n";
    Super *ptr = new Super();
    ptr->Method1();
    // ptr->Method2(); // Error: Super has no Method2

    delete ptr;

    ptr = new Sub();
    ptr->Method1();
    // ptr->Method2(); // Error: Super pointer can't access Method2 directly

    // To access Method2, need to cast:
    Sub *subPtr = dynamic_cast<Sub *>(ptr);
    if (subPtr)
        subPtr->Method2();
    delete ptr;

    std::cout << "\n=== Has-a (Composition) Example ===\n";
    Car car;
    car.Start();

    std::cout << "\n=== Has-a (Aggregation) Example ===\n";
    Player p1("Alice"), p2("Bob");
    Team team;
    team.AddPlayer(&p1);
    team.AddPlayer(&p2);
    team.ListPlayers();

    std::cout << "\n=== Uses-a (Association/Dependency) Example ===\n";
    Doctor doc;
    Stethoscope st;
    doc.CheckPatient(st);

    std::cout << "\n=== Part-of (Composition vs Aggregation) Example ===\n";
    House house; // Room is part of House, destroyed with it
    Employee e1, e2;
    Department dept;
<<<<<<< HEAD
    // Employees can exist independently of
}

/*  ================================================================================
                                Functions/ Methods Implementations
    ================================================================================    */
=======
    // Employees can exist independently of the Department

    return 0;
}
>>>>>>> 8b12fb5968b47918e6e37560963d14945fa31fce
