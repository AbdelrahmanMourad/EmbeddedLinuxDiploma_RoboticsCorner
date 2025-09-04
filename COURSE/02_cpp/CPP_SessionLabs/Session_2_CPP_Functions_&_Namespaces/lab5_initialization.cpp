/*
================================================================================
|   C++ Initialization - Study Summary
|-------------------------------------------------------------------------------
| - Types of Initialization:
|     * Default Initialization: int x; (uninitialized, may contain garbage)
|     * Copy Initialization:    int x = 5; (C++98+)
|     * Direct Initialization:  int x(5); (C++98+)
|     * List Initialization (Uniform): int x{5}; (C++11+, safest, prevents narrowing)
|     * Value Initialization:   int x{}; (zero-initialized)
| - Applies to: built-in types, pointers, arrays, structs, classes, STL containers.
| - Tips & Tricks:
|     * Prefer list initialization `{}` for safety and clarity.
|     * Always initialize variables to avoid undefined behavior.
|     * Use `{}` for STL containers and classes for best practice.
|     * For pointers, initialize to nullptr.
|     * For vectors, use:
|           - vector<int> v{1,2,3}; //(List). or
|           - vector<int> v(5, 0); //(5 elements, all 0).
| - Interview Questions:
|       Q1: What is the difference between copy, direct, and list initialization?
|       Q2: Why is list initialization safer?
|       Q3: What is narrowing?
|       Q4: How do you initialize a pointer? A vector? A class?
|       Q5: What happens if you don't initialize a variable?
|       Q6: What is the downside of each type of initialization?
|       Q7: How do you initialize a struct or class?
|       Q8: How do you initialize an array?
|       Q9: What is the difference between value initialization and zero-initialization?
|       Q10: Can you use list initialization with STL containers?
================================================================================
*/

#include <iostream>
#include <vector>
#include <string>

struct Point
{
    int x;
    int y;
    // Constructor for direct initialization
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    // List initialization constructor
    Point() : x(0), y(0) {}
};

class MyClass
{
public:
    int a;
    double b;
    std::string s;
    MyClass() : a(0), b(0.0), s("default") {}
    MyClass(int a_, double b_, std::string s_) : a(a_), b(b_), s(s_) {}
};

int main()
{
    // Built-in types
    int a;     // Default initialization (uninitialized, garbage value)
    int b = 5; // Copy initialization
    int c(6);  // Direct initialization
    int d{7};  // List (uniform) initialization (safe)
    int e{};   // Value initialization (zero-initialized)

    std::cout << "b=" << b << ", c=" << c << ", d=" << d << ", e=" << e << std::endl;

    // Floating point
    double f = 3.14; // Copy initialization
    double g(2.71);  // Direct initialization
    double h{1.23};  // List initialization (safe)
    double i{};      // zero

    std::cout << "f=" << f << ", g=" << g << ", h=" << h << ", i=" << i << std::endl;

    // Char and bool
    char ch = 'A';      // Copy initialization
    char ch2{'B'};      // List initialization (safe)
    // Note: bool can be initialized with true/false or 0/1
    bool flag = true;   // Copy initialization
    bool flag2{false};  // List initialization (safe)
    bool flag3{};       // Value initialization (false)
    // Note: char can also be initialized with integer values (ASCII codes)
    std::cout << "ch=" << ch << ", ch2=" << ch2 << ", flag=" << flag << ", flag2=" << flag2 << std::endl;

    // Pointers
    int *p1;           // Uninitialized pointer (dangerous)
    int *p2 = nullptr; // Initialized to nullptr (safe)
    int *p3 = &b;      // Points to b
    std::cout << "p2=" << p2 << ", *p3=" << *p3 << std::endl;

    // Arrays
    int arr1[3];                // Uninitialized, contains garbage values.
    int arr2[3] = {1, 2, 3};    // Copy initialization, initializes with values.
    // Note: C++11 onwards allows list initialization for arrays
    int arr3[3]{4, 5, 6};       // List initialization, prevents narrowing (safe).
    int arr4[3]{};              // Zero-initialized, all elements are 0.

    std::cout << "arr2: ";
    for (int val : arr2)
        std::cout << val << " ";
    std::cout << "\narr3: ";
    for (int val : arr3)
        std::cout << val << " ";
    std::cout << "\narr4: ";
    for (int val : arr4)
        std::cout << val << " ";
    std::cout << std::endl;

    // Structs
    Point pt1;         // Default constructor (x=0, y=0)
    Point pt2(10, 20); // Direct initialization
    Point pt3{30, 40}; // List initialization

    std::cout << "pt1: (" << pt1.x << "," << pt1.y << "), pt2: (" << pt2.x << "," << pt2.y << "), pt3: (" << pt3.x << "," << pt3.y << ")\n";

    // Classes
    MyClass obj1;                  // Default constructor
    MyClass obj2(1, 2.5, "hello"); // Direct initialization
    MyClass obj3{3, 4.5, "world"}; // List initialization

    std::cout << "obj1: " << obj1.a << ", " << obj1.b << ", " << obj1.s << std::endl;
    std::cout << "obj2: " << obj2.a << ", " << obj2.b << ", " << obj2.s << std::endl;
    std::cout << "obj3: " << obj3.a << ", " << obj3.b << ", " << obj3.s << std::endl;

    // STL Containers
    std::vector<int> v1;             // Default (empty)
    std::vector<int> v2 = {1, 2, 3}; // Copy initialization
    std::vector<int> v3{4, 5, 6};    // List initialization
    std::vector<int> v4(5, 0);       // 5 elements, all 0

    std::cout << "v2: ";
    for (int val : v2)
        std::cout << val << " ";
    std::cout << "\nv3: ";
    for (int val : v3)
        std::cout << val << " ";
    std::cout << "\nv4: ";
    for (int val : v4)
        std::cout << val << " ";
    std::cout << std::endl;

    // String
    std::string s1;           // Default (empty)
    std::string s2 = "hello"; // Copy initialization
    std::string s3("world");  // Direct initialization
    std::string s4{"C++"};    // List initialization

    std::cout << "s2: " << s2 << ", s3: " << s3 << ", s4: " << s4 << std::endl;

    return 0;
}

/*
================================================================================
|   Interview Questions & Answers
|-------------------------------------------------------------------------------
| Q1: What is the difference between copy, direct, and list initialization?
| A1: Copy uses '=', direct uses '()', list uses '{}'. List is safest (prevents narrowing).
|
| Q2: Why is list initialization safer?
| A2: It prevents narrowing conversions (e.g., int x{3.14}; is an error).
|
| Q3: What is narrowing?
| A3: Narrowing is when a value is converted to a type that cannot represent all possible values,
|     potentially losing data or precision (e.g., assigning a double to an int, or a large int to a char).
|     List initialization {} will cause a compile error if narrowing would occur.
|
| Q4: How do you initialize a pointer? A vector? A class?
| A4: Pointer: int* p = nullptr; Vector: std::vector<int> v{1,2,3}; Class: MyClass obj{1,2.0,"hi"};
|
| Q5: What happens if you don't initialize a variable?
| A5: For built-in types, it contains garbage (undefined) value. For classes, default constructor is called.
|
| Q6: What is the downside of each type of initialization?
| A6:
|     - Default initialization: Leaves variables uninitialized (garbage value), can cause bugs.
|     - Copy initialization:    Allows narrowing conversions, less safe than list initialization.
|     - Direct initialization:  Also allows narrowing, but is more explicit than copy.
|     - List initialization:    Safest, but not available in pre-C++11 code.
|     - Value initialization:   Always zero-initializes, but may not be what you want for all types.
|
| Q7: How do you initialize a struct or class?
| A7: Struct: Point p{1,2}; Class: MyClass obj{1, 2.0, "hello"}; (using list initialization).
|
| Q8: How do you initialize an array?
| A8: int arr[3] = {1, 2, 3}; // Copy initialization, or int arr[3]{4, 5, 6}; // List initialization.
|
| Q9: What is the difference between value initialization and zero-initialization?
| A9: Value initialization (int x{};) initializes to zero, while zero-initialization (int x = 0;) explicitly sets to zero.
|
| Q10: Can you use list initialization with STL containers?
| A10: Yes, you can use list initialization with STL containers like std::vector<int> v{1, 2, 3};.
|
================================================================================
*/