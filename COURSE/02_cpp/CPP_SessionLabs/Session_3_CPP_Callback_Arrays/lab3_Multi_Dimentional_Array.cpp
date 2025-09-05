/*
================================================================================
|   C++ Multi-Dimensional Arrays - Study & Lab Summary
|-------------------------------------------------------------------------------
| Types:
|   1. C-style multi-dimensional array:      int arr[2][3] = { {1,2,3}, {4,5,6} };
|   2. std::array of std::array:             std::array<std::array<int,3>,2> arr = {{{1,2,3},{4,5,6}}};
|   3. std::vector of std::vector:           std::vector<std::vector<int>> v = {{1,2,3},{4,5,6}};
|
| Initialization:
|   - C-style: int arr[2][3] = { {1,2,3}, {4,5,6} }; // All elements set
|   - std::array: std::array<std::array<int,3>,2> arr = {{{1,2,3},{4,5,6}}};
|   - std::vector: std::vector<std::vector<int>> v = {{1,2,3},{4,5,6}};
|
| Indexing & Access:
|   - arr[i][j]: classic index for all types
|   - *(arr[i] + j): pointer arithmetic for C-style
|   - .at(i).at(j): bounds-checked for std::array and std::vector
|
| Looping:
|   - Classic nested for: for(int i=0; i<rows; ++i) for(int j=0; j<cols; ++j) ...
|   - Range-based for: for(auto& row : arr) for(auto val : row) ...
|
| Passing to Functions:
|   - C-style: void foo(int arr[][3], int rows)
|   - std::array: void foo(std::array<std::array<int,3>,2>& arr)
|   - std::vector: void foo(std::vector<std::vector<int>>& v)
|
| Methods:
|   - std::array: .size(), .at(), .begin(), .end(), .front(), .back(), .data()
|   - std::vector: .size(), .at(), .push_back(), .resize(), .clear(), .empty(), .front(), .back(), .insert(), .erase(), .data()
|
| Tips & Tricks:
|   - Prefer std::vector for dynamic size, std::array for fixed size.
|   - Use .at() for bounds-checked access.
|   - Range-based for is cleanest for readability.
|   - std::vector can grow dynamically, C-style and std::array are fixed.
|   - Jagged arrays (rows of different lengths) are best handled with std::vector<std::vector<T>>.
|   - Use std::vector for non-rectangular arrays (jagged).
|   - C-style arrays decay to pointers when passed to functions, so specify all but the first dimension.
|   - std::array and std::vector maintain size information, so no need to pass dimensions.
|
| NOTES:
|   - Multi-dimensional arrays can be thought of as arrays of arrays.
|   - Multi-dimensional arrays are useful for representing matrices, grids, and tables.
|   - Multi-dimentional arrays..{Used more in AI & Robotics}, {Not Preferred in Embedded C++}.
|   - dataType arr[rows][cols][depth]; for 3D arrays.
|   - int arr[3][3][3] // 3D array.
|   - dataType arr_NAme[size_1][size_2]...[size_n]; for Multi-Dimensional arrays.
|
| Performance:
|   - C-style arrays are fast, but lack safety and flexibility.
|   - std::array is fast, stack-allocated, and has fixed size.
|   - std::vector is slower due to dynamic memory management, but provides flexibility.
|   - Use std::vector for dynamic arrays, std::array for fixed-size arrays.
|   - C-style arrays allow pointer arithmetic, std::array and std::vector do not.
|   - std::vector has overhead for dynamic resizing, but is more flexible.
|   - std::array is more efficient than std::vector for fixed-size arrays due to no dynamic memory allocation.
|   - C-style arrays are stack-allocated, std::array is also stack-allocated, std::vector is heap-allocated.
|   - std::vector provides automatic memory management, while C-style requires manual management.
|   - std::vector supports dynamic resizing, while C-style and std::array do not.
|
| Common Operations:
|   - Accessing elements: arr[i][j] for all types, .at(i).at(j) for std::array and std::vector.
|   - Iterating: Nested loops or range-based for.
|   - Passing to functions: C-style requires all but first dimension, std::array and std::vector pass by reference.
|   - Memory management: C-style arrays are stack-allocated, std::array is also stack-allocated, std::vector is heap-allocated.
|   - Pointer arithmetic: C-style allows pointer arithmetic, std::array and std::vector do not.
|   - Jagged arrays: Use std::vector<std::vector<T>> for rows of different lengths.
|   - Bounds checking: Use .at() for std::array and std::vector to avoid out-of-bounds access.
|   - Range-based for loops: Clean and readable for iterating over elements.
|
| Interview Tips:
|   - Understand the differences between C-style, std::array, and std::vector.
|   - Be able to explain how to declare, initialize, access, and iterate over 2D arrays.
|   - Know how to pass 2D arrays to functions and the implications of each type.
|   - Be familiar with the advantages of std::vector for dynamic arrays and jagged arrays.
|   - Practice common interview questions about 2D arrays.
|   - Be ready to explain when to use each type and their performance implications.
|   - Understand how to use pointer arithmetic with C-style arrays.
|   - Be able to write code snippets for common operations on 2D arrays.
|   - Practice writing functions that take 2D arrays as parameters.
|   - Be prepared to discuss memory management implications of each type.
|   - Understand the trade-offs between fixed-size and dynamic-size arrays.
|   - Be able to explain the use of .at() for bounds-checked access in std::array and std::vector.
|   - Know how to handle jagged arrays with std::vector<std::vector<T>>.
|   - Be familiar with the use of range-based for loops for iterating over 2D arrays.
|
| Interview Q&A:
|   Q1: How do you declare a 2D array in C++?
|      A1: int arr[rows][cols]; or std::array<std::array<int,cols>,rows>; or std::vector<std::vector<int>>.
|   Q2: How do you access elements?
|      A2: arr[i][j] for all types; .at(i).at(j) for bounds-checked.
|   Q3: How do you pass a 2D array to a function?
|      A3: For C-style, specify all but the first dimension: void foo(int arr[][cols], int rows).
|   Q4: How do you iterate over all elements?
|      A4: Nested loops or range-based for.
|   Q5: When to use vector<vector<T>>?
|      A5: When you need dynamic resizing or non-rectangular ("jagged") arrays.
================================================================================
*/

#include <iostream>
#include <array>
#include <vector>

// --- C-style 2D array ---
void print_c_2d(int arr[][3], int rows)
{
    std::cout << "C-style 2D array:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < 3; ++j)
            std::cout << "arr[" << i << "][" << j << "]=" << arr[i][j] << (j == 2 ? "\n" : " ");
}

// --- std::array 2D ---
void print_std_array_2d(const std::array<std::array<int, 3>, 2> &arr)
{
    std::cout << "std::array 2D:\n";
    for (const auto &row : arr)
    {
        for (auto val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}

// --- std::vector 2D ---
void print_vector_2d(const std::vector<std::vector<int>> &v)
{
    std::cout << "std::vector 2D:\n";
    for (const auto &row : v)
    {
        for (auto val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
}

int main()
{

    // Breif difference. {C-style vs C++ style}:
    int matrix_c[2][2];                           // Uninitialized 2D array, Allocate in stack {Garbage values}.
    std::array<std::array<int, 2>, 2> matrix_cpp; // Uninitialized 2D std::array, Allocate in stack {Garbage values}.

    // --- C-style 2D array ---
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}}; // C-style initialization
    int arr2[2][3]{{7, 8, 9}, {10, 11, 12}}; // C++11 list initialization, same result
    print_c_2d(arr1, 2);
    print_c_2d(arr2, 2);

    // Accessing using pointer arithmetic
    std::cout << "C-style pointer arithmetic: arr1[1][2] = " << *(*(arr1 + 1) + 2) << std::endl;

    // --- std::array of std::array ---
    std::array<char, 6> word1;                   // Uninitialized 1D std::array of char, Allocate in stack {Garbage values}.
    std::array<std::array<int, 3>, 2> sentence1; // Uninitialized 2D std::array of std::array ,Allocate in stack {Garbage values}.

    // NOTE:
    // The following two initializations are functionally equivalent in C++11 and later.
    // Both create a 2D std::array with the same contents. The difference is only in syntax style:
    //   - The first uses '=' (copy/list initialization).
    //   - The second omits '=' (direct list initialization, also called uniform initialization).
    // There is NO difference in the resulting array or its behavior.

    std::array<std::array<int, 3>, 2> stdarr1 = {{{13, 14, 15}, {16, 17, 18}}}; // C++11 copy initialization
    std::array<std::array<int, 3>, 2> stdarr2{{{19, 20, 21}, {22, 23, 24}}};    // C++11 list initialization
    print_std_array_2d(stdarr1);
    print_std_array_2d(stdarr2);

    // Accessing using .at() and .data()
    std::cout << "std::array at: stdarr1.at(1).at(2) = " << stdarr1.at(1).at(2) << std::endl;
    std::cout << "std::array pointer: *(stdarr1[1].data()+2) = " << *(stdarr1[1].data() + 2) << std::endl;

    // --- std::vector of std::vector ---
    std::vector<std::vector<int>> vec1 = {{25, 26, 27}, {28, 29, 30}};
    std::vector<std::vector<int>> vec2{{31, 32, 33}, {34, 35, 36}}; // List initialization
    print_vector_2d(vec1);
    print_vector_2d(vec2);

    // Accessing using .at() and .data()
    std::cout << "std::vector at: vec1.at(1).at(2) = " << vec1.at(1).at(2) << std::endl;
    std::cout << "std::vector pointer: *(vec1[1].data()+2) = " << *(vec1[1].data() + 2) << std::endl;

    // --- Range-based for loop for all types ---
    std::cout << "Range-based for (std::array): ";
    for (const auto &row : stdarr1)
        for (auto val : row)
            std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Range-based for (std::vector): ";
    for (const auto &row : vec1)
        for (auto val : row)
            std::cout << val << " ";
    std::cout << std::endl;

    // --- Classic nested for loop for all types ---
    std::cout << "Classic nested for (C-style): ";
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            std::cout << arr1[i][j] << " ";
    std::cout << std::endl;

    // --- Jagged vector example (rows of different lengths) ---
    std::vector<std::vector<int>> jagged = {{1, 2}, {3, 4, 5}, {6}};
    std::cout << "Jagged vector:\n";
    for (const auto &row : jagged)
    {
        for (auto val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }

    return 0;
}
