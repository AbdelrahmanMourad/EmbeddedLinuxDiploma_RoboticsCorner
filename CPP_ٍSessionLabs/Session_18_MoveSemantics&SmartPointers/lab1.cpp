/*
================================================================================
|   C++ Move Semantics and Smart Pointers
================================================================================
*/
/*
================================================================================
|   Move Semantics in C++
|-------------------------------------------------------------------------------
| - Move semantics allow resources (like memory) to be transferred from one object
|   to another without copying, improving performance.
| - Uses rvalue references (T&&) and std::move to enable "moving" instead of copying.
| - Commonly used in classes that manage resources (e.g., dynamic memory, files).
| - Move constructor and move assignment operator are special functions for this.
| - Example: std::vector uses move semantics to efficiently transfer data.
================================================================================
*/

/*
================================================================================
|   Smart Pointers in C++
|-------------------------------------------------------------------------------
| - Smart pointers are classes that manage the lifetime of dynamically allocated objects.
| - They automatically release memory when no longer needed, preventing memory leaks.
| - Types:
|     * std::unique_ptr: Sole ownership, cannot be copied, only moved.
|     * std::shared_ptr: Shared ownership, reference counted.
|     * std::weak_ptr: Non-owning reference to a shared_ptr-managed object.
| - Use smart pointers instead of raw pointers for safer and cleaner code.
================================================================================
*/

/*  ================================================================================
                            Included Libraries
    ================================================================================ */
#include <iostream> // For std::cout, std::cin
#include <memory>   // For smart pointers like std::unique_ptr, std::shared_ptr, std::weak_ptr
#include <utility>  // For std::move
extern "C"
{
#include <stdio.h>  // For C-style I/O functions
#include <stdlib.h> // For C-style memory management functions
#include <string.h> // For C-style string functions
#include <cstring>  // For C++ style string functions // for using strlen and memcpy:
}

/*  ================================================================================
                            Definitions
    ================================================================================ */
class Entity
{
private:
    std::string name;

public:
    // Copy constructor
    Entity(const Entity &other) // Copy constructor
        : name(other.name)      // Copy the name from the other objects
    {
        std::cout << "Entity copied: " << name << std::endl;
    }

    Entity(Entity &&other) noexcept   // Move constructor
        : name(std::move(other.name)) // Transfer ownership of the name
    {
        std::cout << "Entity moved: " << name << std::endl;
    }
};

/*  ================================================================================
                            Main() - Entry Point
    ================================================================================ */
int main()
{
    /* ___Move_Semantics___ */
    // Example of move semantics with a custom class
    // Call the default constructor and move constructor.
    std::string str(std::move("Hello, World!")); // Using move semantics to initialize a string

    // Example of using move semantics and smart pointers
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42); // Create a unique pointer
    std::cout << "Value pointed by ptr1: " << *ptr1 << std::endl;

    // Move ownership to ptr2
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    if (!ptr1)
    {
        std::cout << "ptr1 is now null after move." << std::endl;
    }
    std::cout << "Value pointed by ptr2: " << *ptr2 << std::endl;

    return 0;
}

/*  ================================================================================
                            Implementations
    ================================================================================ */