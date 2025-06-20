/*
================================================================================
   C++ OOP - Study Summary
-------------------------------------------------------------------------------
    Programming Paradigm:
        -   Procedural
        -   Functional
        -   OOP ---------------------> Non-Linear Thinking
        -   Asynchronous

    Encapsulation:
        -   Every class/type has encapsulated his attributes and methods.
        -   Class = Type (Data + Operations)
            *   Data : data members {properiess , attributes}
            *   Operations : Methods members {behaviors}
        -   Each member is associated with an access level:
            *   private     -
            *   publbic     +
            *   protected   #

    Types of classes:
        - Polymorphic classes 
                = designed for extension 
                    {shape , circle , triangle , exception , ...}
        - Value classes 
                = designed for storing values 
                    {int , complex<double> , vector , stack , array , queue , ...}
        - RAII (Resource Acquisition Is Initialization) classes 
                = "Encapsulates a resource into a class (class manage the resource) => resource lifetime object lifetime"
                    {thread , unique_ptr , ...}
================================================================================
*/

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

