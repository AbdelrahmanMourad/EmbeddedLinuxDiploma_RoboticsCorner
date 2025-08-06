/*
================================================================================
|   C++ Arrays: Passing by Value vs Reference - Study & Lab Summary
|-------------------------------------------------------------------------------
| - In C, arrays decay to pointers when passed to functions (no size info).
| - In C++, std::array is a container (knows its size, supports STL).
| - Passing std::array by value copies the whole array (changes do NOT affect original).
| - Passing std::array by reference allows modifying the original array.
| - Always use reference (&) if you want to modify the array in a function.
| - Range-based for with reference (auto&) allows in-place modification.
| - Interview:
|     * What happens if you pass std::array by value? (copy, no effect on original)
|     * How to modify an array in a function? (pass by reference)
|     * What is the difference between C array and std::array in function calls?
================================================================================
*/

#include <iostream>
#include <array>
#include <algorithm>

void inputArray(int input[], int size)
{
    std::cout << "inputArray() (C-style, modifies original)\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << "C enter element: ";
        std::cin >> input[i];
    }
}

void input_byValue(std::array<int, 3> list)
{
    std::cout << "input_byValue() (copy, does NOT modify original)\n";
    for (auto &element : list)
    {
        std::cout << "enter element: ";
        std::cin >> element;
    }
}

void input_byReference(std::array<int, 3> &list)
{
    std::cout << "input_byReference() (modifies original)\n";
    for (auto &element : list)
    {
        std::cout << "Ref enter element: ";
        std::cin >> element;
    }
}

void output(const std::array<int, 3> &list)
{
    for (auto element : list)
    {
        std::cout << "element: " << element << std::endl;
    }
}

int main()
{
    // Create cpp-style array
    std::array<int, 3> arr{1, 2, 3};

    std::cout << "Initial array:\n";
    output(arr);

    // Modify by reference (changes original)
    input_byReference(arr);
    std::cout << "After input_byReference:\n";
    output(arr);

    // Modify by value (does NOT change original)
    input_byValue(arr);
    std::cout << "After input_byValue (should be unchanged):\n";
    output(arr);

    // C-style array example
    int c_arr[3] = {4, 5, 6};
    inputArray(c_arr, 3);
    std::cout << "C-style array after inputArray:\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "element: " << c_arr[i] << std::endl;
    }

    return 0;
}
