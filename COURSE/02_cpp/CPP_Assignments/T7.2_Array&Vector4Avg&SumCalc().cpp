/*  ________________________________________________________________________________________________________
    Task(7.2):
    ----------
       Create a C++ program that takes 5 integers as input from the user and stores them in an array.
       Then, find the sum and average of the numbers in the array and display the results.

       Example:
           Input:
               array: 7 12 9 15 19
           Output:
               Total sum = 62
               Average = 12.4
    ___________________________________________________________________________________________________________
    Key Concepts Used:
        - Range-based for loops simplify iteration.
        - Traditional for loops using .beging() and .end()
        - Different ways to pass an array:
            - By Value:                 Makes a copy (less efficient, not modifying original).
            - By Pointer:               Uses raw array pointers (flexible).
            - By Reference:             Direct access without copying.
            - By Constant Reference:    Prevents modification while optimizing performance.
        - Different ways to pass a vector:
            - by value                  (makes a copy of the vector)
            - by pointer                (uses raw access)
            - by reference              (avoids copying)
            - by constant reference     (efficient read-only access)
    ___________________________________________________________________________________________________________
*/

/*  -------------------------------------------------------------------
                        Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
// #include <span>         // C++20

/*  -------------------------------------------------------------------
                        Definitions & Global Variables
    ------------------------------------------------------------------- */
const int ARRAY_SIZE = 5;

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
// __Array__
// Function 1.1: Pass array **by value** (creates a copy)
void calculateByArrayValue(int arr[ARRAY_SIZE]);
// Function 1.2: Pass array **by pointer**
void calculateByArrayPointer(int *arr);
// Function 1.3: Pass array **by reference**
void calculateByArrayReference(int (&arr)[ARRAY_SIZE]);
// Function 1.4: Pass array **by constant reference** --ReadOnly (Safe Passing)
void calculateByArrayConstReference(const int (&arr)[ARRAY_SIZE]);

// __Array_UnknwonSize__
// Function 1.1: Pass array **by pointer**
void calculateByArrayValue_UnknwonSize(int arr[], int size);
// Function 1.2: Pass array **by pointer**
void calculateByArrayPointer_UnknwonSize(int *arr, int size);
// Function 1.3: Pass array **by reference (fixed-size arrays)**
template <size_t N> // Comiple-time template to get the size implicitly.
void calculateByArrayReference_UnknwonSize(int (&arr)[N]);
// Function 1.4: Pass array **by constant reference**
template <size_t N> // Comiple-time template to get the size implicitly.
void calculateByArrayConstReference_UnknwonSize(const int (&arr)[N]);

// __Vector__
// Function 2.1: Pass vector **by value** (creates a copy)
void calculateByVectorValue(std::vector<int> vec);
// Function 2.2: Pass vector **by pointer**
void calculateByVectorPointer(std::vector<int> *vec);
// Function 2.3: Pass vector **by reference**
void calculateByVectorReference(std::vector<int> &vec);
// Function 2.4: Passing vector **by const reference** --ReadOnly (Safe Passing)
void calculateByVectorConstReference(const std::vector<int> &vec);

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // Define Variables Array vs Vector vs Span (C++20).cls
    int numbers_array[ARRAY_SIZE];   // Declaration of Array.
    std::vector<int> numbers_vector; // Declaration of Vector.

    // ___getArrayInput___
    std::cout << "Enter " << ARRAY_SIZE << " integers:\n";
    for (int &num : numbers_array)
    { // Using reference to directly modify array elements
        std::cin >> num;
    }

    // ___getVectorInputs___
    std::cout << "Enter 5 integers:\n";
    // int input;
    for (int i = 0, input = 0; i < 5; i++)
    {
        std::cin >> input;
        numbers_vector.push_back(input); // Dynamically growing the vector
    }

    // ___Calculate using different methods___
    // Array
    std::cout << "\n___UsingArray___\n";
    calculateByArrayValue(numbers_array);
    calculateByArrayPointer(numbers_array);
    calculateByArrayReference(numbers_array);
    calculateByArrayConstReference(numbers_array);
    // Array_UnknwonSize
    std::cout << "\n___UsingArray_UnknownSize___\n";
    int size = (sizeof(numbers_array) / sizeof(numbers_array[0])); // Compute array length dynamically
    calculateByArrayValue_UnknwonSize(numbers_array, size);
    calculateByArrayPointer_UnknwonSize(numbers_array, size);
    calculateByArrayReference_UnknwonSize(numbers_array);
    calculateByArrayConstReference_UnknwonSize(numbers_array);
    // Vector
    std::cout << "\n___UsingVector___\n";
    calculateByVectorValue(numbers_vector);
    calculateByVectorPointer(&numbers_vector);
    calculateByVectorReference(numbers_vector);
    calculateByVectorConstReference(numbers_vector);
    // Span {To Be Implemented when I update my Compiler.}

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
// Function 1.1: Pass array **by value** (creates a copy)
void calculateByArrayValue(int arr[ARRAY_SIZE])
{
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) // Use traditional indexing
    {
        sum += arr[i];
    }
    std::cout << "By Value - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / ARRAY_SIZE << std::endl;
}

// Function 1.2: Pass array **by pointer**
void calculateByArrayPointer(int *arr)
{
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum += arr[i];
    }
    std::cout << "By Pointer - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / ARRAY_SIZE << std::endl;
}

// Function 1.3: Pass array **by reference**
void calculateByArrayReference(int (&arr)[ARRAY_SIZE])
{
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    }
    std::cout << "By Reference - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / ARRAY_SIZE << std::endl;
}

// Function 1.4: Pass array **by constant reference**
void calculateByArrayConstReference(const int (&arr)[ARRAY_SIZE])
{
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    }
    std::cout << "By Const Reference - \tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / ARRAY_SIZE << std::endl;
}

// Function 1.1: Pass array **by value**
void calculateByArrayValue_UnknwonSize(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    { // Using dynamic size
        sum += arr[i];
    }
    std::cout << "By Value - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / size << std::endl;
}

// Function 1.2: Pass array **by pointer**
void calculateByArrayPointer_UnknwonSize(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    { // No hardcoded size
        sum += arr[i];
    }
    std::cout << "By Pointer - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / size << std::endl;
}

// Function 1.3: Pass array **by reference (fixed-size arrays)**
template <size_t N> // Comiple-time template to get the size implicitly.
void calculateByArrayReference_UnknwonSize(int (&arr)[N])
{
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    }
    std::cout << "By Reference - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / N << std::endl;
}

// Function 1.4: Pass array **by constant reference**
template <size_t N> // Comiple-time template to get the size implicitly.
void calculateByArrayConstReference_UnknwonSize(const int (&arr)[N])
{
    int sum = 0;
    for (int num : arr)
    {
        sum += num;
    }
    std::cout << "By Const Reference - \tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / N << std::endl;
}

// // Function 6: Passing span **by const reference**
// void calculateBySpan(std::span<int> &arr)
// {
//     int sum = 0;
//     for (auto it = arr.begin(); it != arr.end(); ++it)
//     {
//         sum += *it;
//     }
//     std::cout << "By Span - Sum: " << sum << ", Average: " << static_cast<double>(sum) / arr.size() << std::endl;
// }

// Function 2.1: Pass vector **by value** (creates a copy)
void calculateByVectorValue(std::vector<int> vec)
{
    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        sum += *it;
    }
    std::cout << "By Value - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / vec.size() << std::endl;
}

// Function 2.2: Pass vector **by pointer**
void calculateByVectorPointer(std::vector<int> *vec)
{
    int sum = 0;
    for (auto it = vec->begin(); it != vec->end(); ++it)
    {
        sum += *it;
    }
    std::cout << "By Pointer - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / vec->size() << std::endl;
}

// Function 2.3: Pass vector **by reference**
void calculateByVectorReference(std::vector<int> &vec)
{
    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        sum += *it;
    }
    std::cout << "By Reference - \t\tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / vec.size() << std::endl;
}

// Function 2.4: Passing vector **by const reference** --ReadOnly (Safe Passing)
void calculateByVectorConstReference(const std::vector<int> &vec)
{
    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        sum += *it;
    }
    std::cout << "By Const Reference - \tSum: " << sum << "\t, Average: " << static_cast<double>(sum) / vec.size() << std::endl;
}
