/*
================================================================================
|   C++ Prefix vs Postfix Increment/Decrement & Looping - Study Summary
|-------------------------------------------------------------------------------
| - Prefix (++i / --i): Increments/decrements the variable, then uses the new value.
|     int x = 10; int y = ++x; // x=11, y=11
| - Postfix (i++ / i--): Uses the current value, then increments/decrements.
|     int x = 10; int y = x++; // x=11, y=10
| - Use prefix when you don't need the old value (slightly more efficient for iterators).
| - Use postfix if you need the original value before increment/decrement.
|-------------------------------------------------------------------------------
| - Looping Examples:
|     * C-style for loop: for (int i = 0; i < N; i++)
|     * Range-based for loop: for (auto x : arr)
|     * Range-based for over list: for (int n : {1,2,3,4,5})
|     * Range-based for over std::list: for (auto element : my_list)
|-------------------------------------------------------------------------------
| Interview Questions & Answers:
| Q1: What is the difference between prefix and postfix increment?
| A1: Prefix (++i) increments first, then returns the new value. Postfix (i++) returns the old value, then increments.
|
| Q2: When should you use prefix vs postfix?
| A2: Use prefix (++i) when you don't need the old value, especially with iterators (can be more efficient).
|
| Q3: How do you loop over arrays and lists in C++?
| A3: Use C-style for for arrays, range-based for for arrays/containers, and range-based for for std::list.
|
| Q4: Can you use range-based for with std::list? With arrays?
| A4: Yes, range-based for works with any container that supports begin()/end(), including arrays and std::list.
================================================================================
*/

#include <iostream>
#include <list>

int main()
{
    // Postfix
    int x1 = 10;
    int y1 = x1++; // y1 =10   ,   x1 =11

    // Prefix
    int x2 = 10;
    int y2 = ++x2; // y1 =11   ,   x1 =11

    // C-style for loop
    int arr[] = {1, 2, 3, 4, 5}; // Array.
    std::cout << "___c-style for loop over array___\n";
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        std::cout << "number: " << arr[i] << "\n";
    }

    // Range based for loop - over array
    std::cout << "___range-based for loop over array___\n";
    for (auto element : arr)
    {
        std::cout << "number: " << element << "\n";
    }

    // Range based for loop - over list
    std::cout << "___range-based for loop over list___\n";
    for (int n : {1, 2, 3, 4, 5})
    {
        std::cout << "number: " << n << "\n";
    }

    // Range based for loop - over std::list
    std::cout << "___range-based for loop over std::list___\n";
    std::list<int> my_list{1, 2, 3, 4, 5};
    for (auto element : my_list)
    {
        std::cout << "number: " << element << "\n";
    }

    return 0;
}