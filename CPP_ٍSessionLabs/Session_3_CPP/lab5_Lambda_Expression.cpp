/*
================================================================================
|   C++ Lambda Expressions - Study & Lab Summary
|-------------------------------------------------------------------------------
| - Lambda: An anonymous, locally-scoped function object. {syntactically similar to a function, but defined inline}
| - Syntax: [capture](params) mutable noexcept constexpr -> ret_type { body }
| - Capture:
|     * []        : No capture
|     * [=]       : Capture all by value
|     * [&]       : Capture all by reference
|     * [x]       : Capture x by value
|     * [&x]      : Capture x by reference
|     * [=, &y]   : All by value, y by reference
| - Lambda Keywords:
|     * mutable   : Allows modifying variables captured by value inside the lambda body.
|     * noexcept  : Specifies that the lambda does not throw exceptions.
|     * constexpr : Makes the lambda a constexpr function if possible (C++17+).
| - Usage:
|     * Inline algorithms (std::sort, std::for_each, etc.)
|     * As callbacks (event handlers, threading, etc.)
|     * For short, one-off functions
| - Lambdas with no capture can be assigned to function pointers.
| - Lambdas with capture require std::function.
| - Interview Q&A at the end.
================================================================================
*/

/*  ================================================================================
                        Included libraries
    ================================================================================    */
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <string>

/*  ================================================================================
                        Functions
    ================================================================================    */
// Example regular functions for comparison
void welcome(std::string str){    std::cout << str << std::endl;}

void fun2(int var){    std::cout << "fun2: var = " << var << std::endl;}

void fun1(void (*callback)(int))
{
    int data = 10;
    callback(data);
}

/*  ================================================================================
                        Main Function - Entry Point
    ================================================================================    */
int main()
{
    // --- 1. Assigning function pointers ---
    void (*ptr1)(std::string) = welcome;
    void (*ptr2)(int) = fun2;
    ptr1("Hello from function pointer!");
    ptr2(42);

    // --- 2. Passing function pointer as callback ---
    fun1(fun2);

    // --- 3. Basic lambda (no capture) ---
    auto lambda1 = [](int x) { std::cout << "lambda1: x = " << x << std::endl; };
    lambda1(100);

    // Assigning no-capture lambda to function pointer
    void (*lambda_ptr)(int) = [](int x) { std::cout << "lambda_ptr: x = " << x << std::endl; };
    lambda_ptr(200);

    // --- 4. Lambda with capture ---
    int a = 5, b = 10;
    auto lambda_by_value = [a, b](int x) { std::cout << "by value: " << (a + b + x) << std::endl; };
    auto lambda_by_ref = [&a, &b](int x) { a += x; b += x; std::cout << "by ref: " << (a + b) << std::endl; };
    auto lambda_all_by_value = [=](int x) { std::cout << "all by value: " << (a + b + x) << std::endl; };
    auto lambda_all_by_ref = [&](int x) { a += x; b += x; std::cout << "all by ref: " << (a + b) << std::endl; };
    auto lambda_mixed = [=, &b](int x) { b += x; std::cout << "mixed: " << (a + b + x) << std::endl; };

    lambda_by_value(1);
    lambda_by_ref(2);
    lambda_all_by_value(3);
    lambda_all_by_ref(4);
    lambda_mixed(5);

    // --- 5. Lambda with return type ---
    auto sum = [](int x, int y) -> int { return x + y; };
    std::cout << "sum(3,4): " << sum(3, 4) << std::endl;

    // --- 6. Lambda as std::function (needed for captures) ---
    int offset = 100;
    std::function<int(int, int)> lambda_with_capture = [offset](int x, int y) { return x + y + offset; };
    std::cout << "lambda_with_capture(1,2): " << lambda_with_capture(1, 2) << std::endl;

    // --- 7. Using lambdas with STL algorithms ---
    std::array<int, 5> arr = {5, 2, 9, 1, 7};
    std::sort(arr.begin(), arr.end(), [](int x, int y) { return x < y; }); // ascending
    std::cout << "Sorted ascending: ";
    for (auto v : arr) std::cout << v << " ";
    std::cout << std::endl;

    std::sort(arr.begin(), arr.end(), [](int x, int y) { return x > y; }); // descending
    std::cout << "Sorted descending: ";
    for (auto v : arr) std::cout << v << " ";
    std::cout << std::endl;

    // --- 8. Lambda as callback ---
    auto callback = [](int val) { std::cout << "Callback called with val = " << val << std::endl; };
    fun1(callback);

    // --- 9. Lambda with mutable (allows modifying captured by value) ---
    int n = 10;
    auto lambda_mutable = [n]() mutable { n += 5; std::cout << "mutable lambda n = " << n << std::endl; };
    lambda_mutable();
    std::cout << "n after mutable lambda = " << n << std::endl; // n is unchanged outside

    // --- 10. Lambda with noexcept and constexpr ---
    auto lambda_noexcept = [](int x) noexcept { std::cout << "noexcept lambda: " << x << std::endl; };
    lambda_noexcept(123);

#if __cplusplus >= 201703L // C++17 or later
    constexpr auto lambda_constexpr = [](int x) constexpr { return x * 2; };
    static_assert(lambda_constexpr(5) == 10, "constexpr lambda works!");
    std::cout << "constexpr lambda: " << lambda_constexpr(7) << std::endl;
#endif

    // --- 11. Lambda as function pointer vs auto ---
    auto no_capture = [](int x) { std::cout << "no_capture: " << x << std::endl; };
    void (*fp)(int) = no_capture; // OK: no capture
    fp(123);

    // auto type can always be used for any lambda
    auto any_lambda = [n](int x) { std::cout << "any_lambda: " << (n + x) << std::endl; };
    any_lambda(7);

    return 0;
}

/*
================================================================================
|   Interview Questions & Answers - Lambdas
|-------------------------------------------------------------------------------
| Q1: What is a lambda expression in C++?
| A1: An anonymous, locally-scoped function object, often used for short, inline code.
|
| Q2: What are lambda capture modes and when do you use them?
| A2: [] - no capture; [=] - all by value; [&] - all by reference; [x] - x by value; [&x] - x by ref;
|     [=, &y] - all by value, y by ref. Use by value for safety, by ref to modify.
|
| Q3: What keywords can be used with lambdas and why?
| A3: mutable (allows modifying captured-by-value), noexcept (guarantees no exceptions), constexpr (compile-time evaluation).
|     Use mutable if you need to change a captured-by-value variable inside the lambda.
|     Use noexcept for performance or API guarantees.
|     Use constexpr for compile-time constant lambdas (C++17+).
|
| Q4: Can you assign a lambda to a function pointer?
| A4: Only if the lambda has no capture. Otherwise, use std::function.
|
| Q5: What is the type of a lambda? What if you use auto?
| A5: Each lambda has a unique, unnamed type. Use auto for convenience, or std::function for generality.
|
| Q6: What is the 'mutable' keyword in lambdas?
| A6: Allows modifying variables captured by value inside the lambda body.
|
| Q7: How do you use lambdas with STL algorithms?
| A7: Pass them as comparators or callbacks, e.g., std::sort, std::for_each.
|
| Q8: What is the difference between a lambda and a regular function?
| A8: Lambdas are anonymous, can capture local variables, and are often used inline.
================================================================================
*/
