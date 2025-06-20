#include <iostream>

/*  ==================================================================================
    C++ Inheritance and Polymorphism: A Comprehensive Overview
    ==================================================================================

    1. Inheritance:
        - Inheritance allows a class (derived class) to inherit properties and behaviors 
            (data members and member functions) from another class (base class).
        - It promotes code reusability and establishes an "is-a" relationship.
        - Example: "Cow" and "Cat" inherit from the abstract class "Sound".

    2. Abstract Classes:
        - An abstract class contains at least one pure virtual function and cannot
            be instantiated.
        - Purpose: To serve as a common interface/blueprint for derived classes.
        - In our code: "Sound" is an abstract class with the pure virtual function 
            `MakeSound()` and a virtual function `SoundVolume()`.

    3. Pure Virtual Functions:
        - Declared by setting the function equal to zero (e.g., `virtual void MakeSound() = 0;`).
        - They force derived classes to override the function, ensuring specific behavior per class.

    4. Virtual Functions:
        - Allow derived classes to override a function’s implementation.
        - Enable runtime polymorphism where the function called is based on the actual object
            type pointed to by a base class pointer.
        - Example: `SoundVolume()` can be overridden if needed, although it has a default implementation here.

    5. Virtual Destructors:
        - Essential in polymorphic base classes to ensure that the destructors of derived classes are called.
        - When deleting an object via a base class pointer, a virtual destructor ensures procper resource cleanup.
        - Our code uses `virtual ~Sound() = default;`, so deleting objects of derived types works correctly.

    6. Polymorphism:
        - Allows a base class pointer or reference to refer to objects of derived classes.
        - Enables calling overridden functions through the base class pointer, resulting in dynamic binding.
        - In our code:
            - A "Sound" pointer points to a "Cow" object and calls `MakeSound()`, which executes "Cow" implementation.
            - Reassignment with a "Cat" object demonstrates polymorphic behavior.

    7. Memory Allocation:
        - Dynamic allocation (using `new` and `delete`) is demonstrated for heap objects.
        - Stack allocation is shown by creating an object (e.g., `Cow cow;`) and then referring to it through a base class reference.
        - The code also emphasizes that pointers to base classes can only point to derived objects (not vice versa).

    8. Additional Considerations:
        - Using the `override` keyword in derived classes helps ensure that the function signature exactly
            matches that of the base class virtual function.
        - Clean deletion of objects avoids memory leaks and ensures destructors are called appropriately.

    ==================================================================================
*/

class Sound
{
public:
    // Pure virtual function: forces derived classes to override this function.
    virtual void MakeSound() = 0;

    // Virtual function: provides a default behavior that can be overridden.
    virtual void SoundVolume()
    {
        std::cout << "low\n";
    }

    // Virtual destructor ensures proper destruction of derived class objects.
    virtual ~Sound() = default;
};

class Cow : public Sound
{
public:
    void MakeSound() override
    {
        std::cout << "Cow Sound\n";
    }

    ~Cow()
    {
        std::cout << "destructor called in cow\n";
    }
};

class Cat : public Sound
{
public:
    // override keyword helps catch mismatches in function signature.
    void MakeSound() override
    {
        std::cout << "Cat Sound\n";  // Adjusted from "Cow Sound" for clearer demonstration.
    }

    ~Cat()
    {
        std::cout << "destructor called in cat\n";
    }
};

int main()
{
    // Cannot instantiate an abstract class:
    // Sound s; // Error: cannot create object of abstract class type 'Sound'

    // Dynamic allocation using base class pointer pointing to a derived class object.
    Sound *obj_sound = new Cow;
    obj_sound->MakeSound();  // Calls Cow's MakeSound() due to dynamic polymorphism.

    // More dynamic allocation example with another derived class.
    Cat *cat = new Cat;
    cat->MakeSound();  // Calls Cat's MakeSound().

    // Base class pointer reassignment to point to derived object "cat".
    obj_sound = cat;
    obj_sound->MakeSound();   // Calls Cat's MakeSound().
    obj_sound->SoundVolume(); // Calls the default SoundVolume() implementation.

    // Delete allocated objects to ensure proper cleanup.
    // When deleting through a base class pointer with virtual destructor, the derived destructor is called.
    delete obj_sound;
    // Note: 'cat' pointer is now invalid since obj_sound and cat point to the same memory.

    // Alternatively, using stack allocation with a reference.
    Cow cow;
    Sound &sound = cow;  // Reference to a derived class object.
    sound.MakeSound();   // Calls Cow's MakeSound().

    return 0;
}
