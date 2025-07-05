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
class MyString;
class Entity;
/*____________________________________________________*/
class Entity
{
private:
    MyString name;

public:
    // Copy constructor ... Lvalue Reference // Copy the name from the other objects
    Entity(const MyString &other) : name{other} { std::cout << "Constructor Called: Copied Entity String.\n"; }
    Entity(const Entity &other) : name{other.name} { std::cout << "Constructor Called: Copied Entity.\n"; }
    // Move constructor ... Rvalue Reference // Transfer ownership of the name
    Entity(MyString &&other) noexcept : name(std::move(other)) { std::cout << "Constructor Called: Moved Entity String.\n"; }
    Entity(Entity &&other) noexcept : name(std::move(other.name)) { std::cout << "Constructor Called: Moved Entity.\n"; }
    void print() { name.Print(); }
};
/*____________________________________________________*/
class MyString
{
private:
    uint32_t mSize;
    char *m_data;

public:
    MyString(const char *Array_data);
    MyString(const MyString &other); // Lvalue reference in Parameterized constructor.
    MyString(MyString &&other);      // Rvalue reference in Parameterized constructor.
    void Print();
    ~MyString() { delete m_data; }
};

/*  ================================================================================
                            Main() - Entry Point
    ================================================================================ */
int main()
{
    /* ___Move_Semantics___ */
    // Example of move semantics with a custom class
    // Call the default constructor and move constructor.
    MyString str(std::move("Hello, World!")); // Using move semantics to initialize a string

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

MyString::MyString(const char *Array_data)
{
    printf("Created\n");
    mSize = strlen(Array_data);
    m_data = new char[mSize];
    memcpy(m_data, Array_data, mSize);
    // printf("%S", m_data);
}
MyString::MyString(const MyString &other) // Copy Constructor.
{
    printf("Copied.\n");
    mSize = other.mSize;
    m_data = new char[mSize];
    memcpy(m_data, other.m_data, mSize);
}
MyString::MyString(MyString &&other) // Move Constructor.
{
    printf("Moved.\n");
    mSize = other.mSize;
    m_data = other.m_data;
    other.mSize = 0;
    other.m_data = nullptr;
}

void MyString::Print()
{
    printf("%S", m_data);
    // for (int i = 0; i < mSize; i++)
    //     printf("%C", m_data[i]);
    printf("\n");
}