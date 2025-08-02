/*
================================================================================
|   C++ Arrays - Study Summary
|-------------------------------------------------------------------------------
| Types:
|   1. C-style array:      int arr[5] = {1,2,3,4,5};
|   2. std::array:         std::array<int, 5> arr = {1,2,3,4,5}; // C++11+
|   3. std::vector:        std::vector<int> v = {1,2,3,4,5};     // dynamic size
|   4. String as array:    char str1[] = "hello"; std::string str2 = "hello";
|________________________________________________________________________________
|
| Initialization:
|   - C-style: int arr[5] = {1,2,3}; // rest zero, int arr[5]{}; // all zero
|   - C++11:   int arr[5]{1,2,3};    // list initialization, rest zero
|   - std::array: std::array<int,5> a{}; // all zero, std::array<int,5> a = {1,2,3,4,5};
|   - std::vector: std::vector<int> v(5, 0); // 5 zeros, std::vector<int> v = {1,2,3};
|
| Difference between = and {} for initialization:
|   - For built-in types and arrays, int arr[] = {4,5,6,7,8}; and int arr[]{4,5,6,7,8}; are equivalent in C++11+.
|   - For std::array and std::vector, = { ... } and { ... } are also equivalent in C++11+.
|   - {} is called "list initialization" and is preferred for uniformity and safety (prevents narrowing).
|________________________________________________________________________________
|
| Indexing & Access:
|   - arr[i] : classic index
|   - *(arr + i) : pointer arithmetic
|   - std::array and std::vector: .at(i) (bounds-checked), [i] (no check)
|
| Multiple ways to index/access arrays:
|   - arr[i], *(arr + i), *(&arr[0] + i)
|   - std::array: arr[i], arr.at(i), *(arr.data() + i)
|   - std::vector: v[i], v.at(i), *(v.data() + i)
|________________________________________________________________________________
|
| Good/Bad:
|   - C-style: Fast, but no size info, no bounds check, error-prone.
|   - std::array: Fixed size, stack-allocated, safer, .size(), .at(), supports STL.
|   - std::vector: Dynamic size, heap-allocated, .size(), .at(), .push_back(), .resize(), best for variable-length.
|   - std::string: Safer than char[], supports many string operations.
|________________________________________________________________________________
|
| Passing to Functions:
|   - C-style: Pass pointer and size: void foo(int* arr, int size)
|   - std::array: Pass by reference: void foo(std::array<int,5>& arr)
|   - std::vector: Pass by reference: void foo(std::vector<int>& v)
|________________________________________________________________________________
|
| Looping:
|   - Classic for: for(int i=0; i<size; ++i)
|   - Range-based for: for(auto x : arr)
|   - Iterator: for(auto it=arr.begin(); it!=arr.end(); ++it)
|________________________________________________________________________________
|
| std::array Methods:
|   - .size(), .at(i), .fill(val), .begin(), .end(), .front(), .back(), .data()
|
| std::vector Methods:
|   - .size(), .at(i), .push_back(val), .pop_back(), .resize(n), .clear(), .empty(), .front(), .back(), .insert(), .erase(), .data()
|________________________________________________________________________________
|
| Tips & Tricks:
|   - Prefer std::array for fixed size, std::vector for dynamic.
|   - Use .at() for bounds-checked access.
|   - Use range-based for for readability.
|   - std::vector can be returned from functions (no decay to pointer).
|   - std::string is safer and more powerful than char[].
|________________________________________________________________________________
|
| Interview Questions & Answers:
|   Q1: Difference between C-style array and std::array?
|       A1: std::array is safer, knows its size, supports STL, fixed size.
|   Q2: How to get array size?
|       A2: C-style: sizeof(arr)/sizeof(arr[0]), std::array: arr.size(), std::vector: v.size()
|   Q3: What happens if you access out of bounds?
|       A3: C-style: undefined behavior, std::array/vector: .at() throws exception, [] is unsafe.
|   Q4: How to pass arrays to functions?
|       A4: C-style: pointer+size, std::array/vector: pass by reference.
|   Q5: When to use std::vector?
|       A5: When you need dynamic, resizable arrays.
|   Q6: How to initialize all elements to zero?
|       A6: int arr[5]{}; std::array<int,5> a{}; std::vector<int> v(5,0);
|   Q7: How to copy arrays?
|       A7: std::array and std::vector support copy assignment. C-style: use std::copy or loops.
================================================================================
*/

// --------------------------------------------------------------
// #include <array> // Static allocated array library.
// // How it's implemented inside std namespace for example
// namespace my_std
// {
//     template <class T>
//     struct myArray_t
//     {
//         // Pointer to character
//         T *pch;
//     }
// }
// // When Using:
// my_std::myArray_t<int> my_array;
// --------------------------------------------------------------

/*  ================================================================================
                            Included Libraries / Modules
    ================================================================================    */
#include <iostream>
#include <array>
#include <vector>
#include <string>

/*  ================================================================================
                            Declarations / Prototypes
    ================================================================================    */
// Function examples for passing arrays
void print_c_array(const int *arr, int size);
void print_std_array(const std::array<int, 5> &arr);
void print_vector(const std::vector<int> &v);

// Function to input C-style int array
void input_c_array(int *arr, int size);

// Function to input std::array<int, N>
template <size_t N>
void input_std_array(std::array<int, N> &arr);

// Function to input std::vector<int>
void input_vector(std::vector<int> &v, int size);

// Function to input C-style char array (as word)
void input_c_char_array(char *arr, int size);

// Function to input std::array<char, N>
template <size_t N>
void input_std_char_array(std::array<char, N> &arr);

// Function to input std::string
void input_string(std::string &s);

/*  ================================================================================
                            Main() = Entry Point
    ================================================================================    */
int main()
{
    // --- C-style array initialization ---
    int arr1[5] = {1, 2, 3};      // rest zero
    int arr2[5]{};                // all zero
    int arr3[] = {4, 5, 6, 7, 8}; // size deduced, 5 elements
    int arr4[]{4, 5, 6, 7, 8};    // C++11 list initialization, same as above

    // Difference? For arrays, int arr3[] = {4,5,6,7,8}; and int arr4[] {4,5,6,7,8}; are equivalent in C++11+.
    print_c_array(arr3, 5);
    print_c_array(arr4, 5);

    // --- std::array initialization ---
    std::array<int, 5> stdarr1 = {10, 20, 30, 40, 50}; // classic
    std::array<int, 5> stdarr2{60, 70, 80, 90, 100};   // list initialization (C++11+)
    // Difference? For std::array, = { ... } and { ... } are equivalent in C++11+.
    print_std_array(stdarr1);
    print_std_array(stdarr2);

    // --- std::vector initialization ---
    std::vector<int> vec1 = {101, 102, 103, 104, 105}; // classic
    std::vector<int> vec2{201, 202, 203, 204, 205};    // list initialization (C++11+)
    // Difference? For std::vector, = { ... } and { ... } are equivalent in C++11+.
    print_vector(vec1);
    print_vector(vec2);

    // --- String as array of characters ---
    char cstr1[] = "hello";     // C-style string (null-terminated)
    std::string str1 = "world"; // std::string

    std::cout << "C-string: " << cstr1 << std::endl;
    std::cout << "std::string: " << str1 << std::endl;

    // --- Multiple ways to index/access arrays ---
    std::cout << "\nIndexing C-style array:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << "arr1[" << i << "]=" << arr1[i] << ", *(arr1+" << i << ")=" << *(arr1 + i)
                  << ", *(&arr1[0]+" << i << ")=" << *(&arr1[0] + i) << std::endl;

    std::cout << "\nIndexing std::array:\n";
    for (size_t i = 0; i < stdarr1.size(); ++i)
        std::cout << "stdarr1[" << i << "]=" << stdarr1[i]
                  << ", stdarr1.at(" << i << ")=" << stdarr1.at(i)
                  << ", *(stdarr1.data()+" << i << ")=" << *(stdarr1.data() + i) << std::endl;

    std::cout << "\nIndexing std::vector:\n";
    for (size_t i = 0; i < vec1.size(); ++i)
        std::cout << "vec1[" << i << "]=" << vec1[i]
                  << ", vec1.at(" << i << ")=" << vec1.at(i)
                  << ", *(vec1.data()+" << i << ")=" << *(vec1.data() + i) << std::endl;

    // --- Looping examples ---
    std::cout << "\nClassic for loop (C-style): ";
    for (int i = 0; i < 5; ++i)
        std::cout << arr1[i] << " ";
    std::cout << "\nRange-based for (std::array): ";
    for (auto x : stdarr1)
        std::cout << x << " ";
    std::cout << "\nIterator loop (std::vector): ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // --- std::array and std::vector methods ---
    stdarr1.fill(7); // fill all with 7
    std::cout << "stdarr1 after fill: ";
    for (auto x : stdarr1)
        std::cout << x << " ";
    std::cout << std::endl;

    vec1.push_back(999);
    vec1.pop_back();
    vec1.resize(7, 42); // now size 7, new elements = 42
    std::cout << "vec1 after push_back, pop_back, resize: ";
    for (auto x : vec1)
        std::cout << x << " ";
    std::cout << std::endl;

    // --- Passing arrays to functions ---
    print_c_array(arr1, 5);
    print_std_array(stdarr1);
    print_vector(vec1);

    // --- Input examples ---
    // --- C-style int array ---
    int arr[5];
    input_c_array(arr, 5);
    std::cout << "You entered (C-style int array): ";
    for (int i = 0; i < 5; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // --- std::array<int, 5> ---
    std::array<int, 5> stdarr;
    input_std_array(stdarr);
    std::cout << "You entered (std::array<int,5>): ";
    for (auto x : stdarr)
        std::cout << x << " ";
    std::cout << std::endl;

    // --- std::vector<int> ---
    std::vector<int> vec;
    input_vector(vec, 5);
    std::cout << "You entered (std::vector<int>): ";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << std::endl;

    // --- C-style char array as word ---
    char cword[10];
    input_c_char_array(cword, 10);
    std::cout << "You entered (C-style char array): " << cword << std::endl;

    // --- std::array<char, 6> ---
    std::array<char, 6> stdword;
    input_std_char_array(stdword);
    std::cout << "You entered (std::array<char,6>): ";
    for (char ch : stdword)
        std::cout << ch;
    std::cout << std::endl;

    // --- std::string ---
    std::string s;
    input_string(s);
    std::cout << "You entered (std::string): " << s << std::endl;

    return 0;

    // cpp-style array.
    std::array<char, 5> word; // allocate in Stack. {garbage}

    std::cout << "please enter array elements\n";
    for (char element : word)
    {
        std::cin >> element; // fill the array word elements one by one. "Example: letter"
    }
    for (char element : word)
    {
        std::cout << element << std::endl; // print the array word elements one by one.
    }

    /* Will not work and output garbage: As it's passed by copy not by reference */

    std::array<char, 6> word; // allocate in Stack. {garbage}

    std::cout << "please enter array elements\n";
    for (char &element : word)
    {
        std::cin >> element; // fill the array word elements one by one. "Example: letter"
    }
    for (char element : word)
    {
        std::cout << element << std::endl; // print the array word elements one by one.
    }
}

/*  ================================================================================
                            Implementation
    ================================================================================    */
// Function examples for passing arrays
void print_c_array(const int *arr, int size)
{
    std::cout << "C-array: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void print_std_array(const std::array<int, 5> &arr)
{
    std::cout << "std::array: ";
    for (auto x : arr)
        std::cout << x << " ";
    std::cout << std::endl;
}

void print_vector(const std::vector<int> &v)
{
    std::cout << "std::vector: ";
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;
}

// Function to input C-style int array
void input_c_array(int *arr, int size)
{
    std::cout << "Enter " << size << " integers (C-style array): ";
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];
}

// Function to input std::array<int, N>
template <size_t N>
void input_std_array(std::array<int, N> &arr)
{
    std::cout << "Enter " << N << " integers (std::array): ";
    for (size_t i = 0; i < N; ++i)
        std::cin >> arr[i];
}

// Function to input std::vector<int>
void input_vector(std::vector<int> &v, int size)
{
    v.resize(size);
    std::cout << "Enter " << size << " integers (std::vector): ";
    for (int i = 0; i < size; ++i)
        std::cin >> v[i];
}

// Function to input C-style char array (as word)
void input_c_char_array(char *arr, int size)
{
    std::cout << "Enter a word of up to " << size - 1 << " characters: ";
    std::cin >> arr;
}

// Function to input std::array<char, N>
template <size_t N>
void input_std_char_array(std::array<char, N> &arr)
{
    std::cout << "Enter " << N << " characters (std::array): ";
    for (size_t i = 0; i < N; ++i)
        std::cin >> arr[i];
}

// Function to input std::string
void input_string(std::string &s)
{
    std::cout << "Enter a string: ";
    std::cin >> s;
}