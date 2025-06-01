/*
================================================================================
|   C++ Functions - Quick Study Summary
|-------------------------------------------------------------------------------
| - Functions are reusable blocks of code that perform a specific task.
| - Syntax:
|       ReturnType FunctionName(ParameterType1 param1, ParameterType2 param2, ...)
|       {
|           // Function body (statements)
|           return value; // (if not void)
|       }
| - Functions help organize code, avoid repetition, and improve readability.
| - You can pass arguments (inputs) and get a return value (output).
| - Function declaration (prototype) tells the compiler about the function.
| - Function definition provides the actual code.
| - Example:
|       int add(int a, int b) {
|           return a + b;
|       }
| - Call a function by its name and pass arguments: int sum = add(2, 3);
| - The main() function is the entry point of every C++ program.
| - Functions have their own scope, so variables defined inside a function are local to that function.
| - Functions call has:
|       - Pre-Condition: Arguments must be valid.
|       - Post-Condition: Function should return a value or perform an action.
| - Functions can be overloaded (same name, different parameters).
| - Functions can be recursive (call themselves).
| - Use functions to break down complex problems into smaller, manageable parts.
| - Functions can be defined inside classes (member functions).
| - Functions can be passed as arguments to other functions (function pointers).
| - Functions can return multiple values using structures or tuples.
| - Functions can be used to implement algorithms and data structures.
| - Arguments in function call can be passed by 3 different ways:
|       - Call by value.                => example: int add(int a, int b)
|       - Call by pointer.              => example: int add(int *a, int *b)
|       - Call by reference.            => example: int add(int &a, int &b)
|       - Call by constant reference.   => example: int add(const int &a, const int &b)
|_______________________________________________________________________________
| - Note: Default arguments are NOT the same as function overloading.
|         Overloading allows different types and numbers of parameters.
|         Default arguments only fill in missing values for parameters at the end. (Can be used with Templates).
================================================================================
*/

/*  ================================================================================
    - Lab(1): Demonstrates function overloading, passing by value, reference, and pointer.
        Overloading allows different types and numbers of parameters.
        Default arguments only fill in missing values for parameters at the end. (Can be used with Templates).
    ================================================================================    
*/
#include <iostream>

// --- By Value ---
int add(int a) { return a; }
int add(int a, int b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
int add(int a, int b, int c, int d) { return a + b + c + d; }
int add(int a, int b, int c, int d, int e) { return a + b + c + d + e; }
// By Value with default arguments (float version)
float add_default(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0) { return a + b + c + d + e; }

// --- By Reference ---
int add_ref(const int& a) { return a; }
int add_ref(const int& a, const int& b) { return a + b; }
int add_ref(const int& a, const int& b, const int& c) { return a + b + c; }
int add_ref(const int& a, const int& b, const int& c, const int& d) { return a + b + c + d; }
int add_ref(const int& a, const int& b, const int& c, const int& d, const int& e) { return a + b + c + d + e; }
// By Reference with default arguments (float version)
float add_ref_default(const float& a = 0, const float& b = 0, const float& c = 0, const float& d = 0, const float& e = 0) { return a + b + c + d + e; }

// --- By Pointer ---
int add_ptr(const int* a) { return *a; }
int add_ptr(const int* a, const int* b) { return *a + *b; }
int add_ptr(const int* a, const int* b, const int* c) { return *a + *b + *c; }
int add_ptr(const int* a, const int* b, const int* c, const int* d) { return *a + *b + *c + *d; }
int add_ptr(const int* a, const int* b, const int* c, const int* d, const int* e) { return *a + *b + *c + *d + *e; }
// By Pointer with default arguments (float version)
float add_ptr_default(const float* a = nullptr, const float* b = nullptr, const float* c = nullptr, const float* d = nullptr, const float* e = nullptr)
{
    float sum = 0;
    if (a) sum += *a;
    if (b) sum += *b;
    if (c) sum += *c;
    if (d) sum += *d;
    if (e) sum += *e;
    return sum;
}

int main()
{
    int x = 1, y = 2, z = 3, w = 4, v = 5;
    float fx = 1.1f, fy = 2.2f, fz = 3.3f, fw = 4.4f, fv = 5.5f;

    // By Value
    std::cout << "add(x) = " << add(x) << std::endl;
    std::cout << "add(x, y) = " << add(x, y) << std::endl;
    std::cout << "add(x, y, z) = " << add(x, y, z) << std::endl;
    std::cout << "add(x, y, z, w) = " << add(x, y, z, w) << std::endl;
    std::cout << "add(x, y, z, w, v) = " << add(x, y, z, w, v) << std::endl;
    // By Value with default arguments (float)
    std::cout << "add_default() = " << add_default() << std::endl;
    std::cout << "add_default(fx) = " << add_default(fx) << std::endl;
    std::cout << "add_default(fx, fy) = " << add_default(fx, fy) << std::endl;
    std::cout << "add_default(fx, fy, fz) = " << add_default(fx, fy, fz) << std::endl;
    std::cout << "add_default(fx, fy, fz, fw) = " << add_default(fx, fy, fz, fw) << std::endl;
    std::cout << "add_default(fx, fy, fz, fw, fv) = " << add_default(fx, fy, fz, fw, fv) << std::endl;

    // By Reference
    std::cout << "add_ref(x) = " << add_ref(x) << std::endl;
    std::cout << "add_ref(x, y) = " << add_ref(x, y) << std::endl;
    std::cout << "add_ref(x, y, z) = " << add_ref(x, y, z) << std::endl;
    std::cout << "add_ref(x, y, z, w) = " << add_ref(x, y, z, w) << std::endl;
    std::cout << "add_ref(x, y, z, w, v) = " << add_ref(x, y, z, w, v) << std::endl;
    // By Reference with default arguments (float)
    std::cout << "add_ref_default() = " << add_ref_default() << std::endl;
    std::cout << "add_ref_default(fx) = " << add_ref_default(fx) << std::endl;
    std::cout << "add_ref_default(fx, fy) = " << add_ref_default(fx, fy) << std::endl;
    std::cout << "add_ref_default(fx, fy, fz) = " << add_ref_default(fx, fy, fz) << std::endl;
    std::cout << "add_ref_default(fx, fy, fz, fw) = " << add_ref_default(fx, fy, fz, fw) << std::endl;
    std::cout << "add_ref_default(fx, fy, fz, fw, fv) = " << add_ref_default(fx, fy, fz, fw, fv) << std::endl;

    // By Pointer
    std::cout << "add_ptr(&x) = " << add_ptr(&x) << std::endl;
    std::cout << "add_ptr(&x, &y) = " << add_ptr(&x, &y) << std::endl;
    std::cout << "add_ptr(&x, &y, &z) = " << add_ptr(&x, &y, &z) << std::endl;
    std::cout << "add_ptr(&x, &y, &z, &w) = " << add_ptr(&x, &y, &z, &w) << std::endl;
    std::cout << "add_ptr(&x, &y, &z, &w, &v) = " << add_ptr(&x, &y, &z, &w, &v) << std::endl;
    // By Pointer with default arguments (float)
    std::cout << "add_ptr_default() = " << add_ptr_default() << std::endl;
    std::cout << "add_ptr_default(&fx) = " << add_ptr_default(&fx) << std::endl;
    std::cout << "add_ptr_default(&fx, &fy) = " << add_ptr_default(&fx, &fy) << std::endl;
    std::cout << "add_ptr_default(&fx, &fy, &fz) = " << add_ptr_default(&fx, &fy, &fz) << std::endl;
    std::cout << "add_ptr_default(&fx, &fy, &fz, &fw) = " << add_ptr_default(&fx, &fy, &fz, &fw) << std::endl;
    std::cout << "add_ptr_default(&fx, &fy, &fz, &fw, &fv) = " << add_ptr_default(&fx, &fy, &fz, &fw, &fv) << std::endl;

    return 0;
}