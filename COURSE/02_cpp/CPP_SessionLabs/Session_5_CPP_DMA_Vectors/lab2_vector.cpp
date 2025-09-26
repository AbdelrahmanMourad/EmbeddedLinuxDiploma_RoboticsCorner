/*
================================================================================
|   C++ std::vector - Study & Lab Summary
|-------------------------------------------------------------------------------
| - std::vector is a dynamic array from the STL.
| - Size can grow/shrink at runtime; memory is managed automatically (heap).
| - Provides random access, efficient insertion/removal at the end, and many utility functions.
| - Syntax & Initialization:
|     std::vector<int> v1;              // empty
|     std::vector<int> v2(5);           // 5 zeros
|     std::vector<int> v3(5, 100);      // 5 elements, all 100
|     std::vector<int> v4{1,2,3,4,5};   // initializer list
| - Common Operations:
|     push_back(val), pop_back(), size(), capacity(), resize(), clear(), erase(), insert(), at(), operator[], sort()
| - Iteration:
|     Range-based for, index-based, iterator-based (auto or explicit)
| - Tips:
|     * Capacity may be larger than size for efficiency.
|     * Use reserve(n) to pre-allocate.
|     * Use erase-remove idiom to remove by value.
|     * Prefer vector over raw arrays for safety and flexibility.
| - Interview Q&A at the end.
================================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm> // for lambdaa expression

/*  -------------------------------------------------------------------
    Session Agenda:
    ---------------
        - Dynamic Arrays.
        - Intro to OOP.
    -------------------------------------------------------------------
*/
/*  -------------------------------------------------------------------
                Vector (Dynamic allocated arrays)
    -------------------------------------------------------------------
    STL (Standard Template Libraries):
        - Containers
            - Array
            - Vector
        - Algos
            - Sort
            - for_each
        - Iterators
            -

    ----------------------------Using Vectors----------------------------------------
    #include <vector>

    // vector
    std::vector<int> list1;         // zero number of elements
    std::vector<int> list2(5);      // 5 of zero elements
    std::vector<int> list3(5, 100); // 5 element each of their values equal 100
                                    // |100|100|100|100|100|
    list3.push_back(6);             // will add at the end same size {5 element} , 1st is 6, rest are zeros
                                    // |100|100|100|100|100|6|0|0|0|0|


    --------------------------------------------------------------------
*/

namespace HelpingFunctions
{
    void PrintSeparatorFn(void)
    {
        std::cout << "---------------------\n";
    }
    void PrintTextFn(std::string text)
    {
        std::cout << text << std::endl;
    }
}

int main()
{
    // --- Initialization examples ---
    std::vector<int> list1;         // zero elements
    std::vector<int> list2(5);      // 5 zeros
    std::vector<int> list3(5, 100); // 5 elements, all 100
    list3.push_back(6);             // add 6 at the end

    // vector
    std::vector<int> list1;         // zero number of elements
    std::vector<int> list2(5);      // 5 of zero elements
    std::vector<int> list3(5, 100); // 5 element each of their values equal 100
                                    // |100|100|100|100|100|
    list3.push_back(6);             // will add at the end same size {5 element} , 1st is 6, rest are zeros
                                    // |100|100|100|100|100|6|0|0|0|0|

                                        // --- Capacity and size behavior ---
    // NOTE: if not assigning size, automatically it assigns "1 bytes"
    std::vector<int> nums1;
    nums1.push_back(100);
    std::cout << "size of vector = \t\"" << nums1.size() << "\"\t Bytes." << std::endl;

    /* NOTE: if assign size{5 Bytes},...
            with each push_back()
                -> size increase by 1
                        - if enough capacity it remains the same.
                        - if enough capacity it increase by the initial size {5 in this example}.

                        {Size > Capacity ... then increase Capacity x2}
    */
    // std::vector<int> nums2{5};
    // // {Size > Capacity ... then increase Capacity x2}
    // nums2.push_back(100); //    [Size=6,Capacity=10]
    // nums2.push_back(100); //    [Size=7,Capacity=10]
    // std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    // std::cout << "Capacity of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=8,Capacity=10]
    // nums2.push_back(100); //    [Size=9,Capacity=10]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=10,Capacity=10]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=11,Capacity=15]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=12,Capacity=15]
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;
    // nums2.push_back(100); //    [Size=13,Capacity=15]
    // std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    // std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;

    std::vector<int> nums2{5, 100};
    // {Size > Capacity ... then increase Capacity x2}
    nums2.push_back(100); //    [Size=6,Capacity=10]
    nums2.push_back(100); //    [Size=7,Capacity=10]
    std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;

    HelpingFunctions::PrintSeparatorFn();

    nums2.push_back(100); //    [Size=8,Capacity=10]
    nums2.push_back(100); //    [Size=9,Capacity=10]
    nums2.push_back(100); //    [Size=10,Capacity=10]
    nums2.push_back(100); //    [Size=11,Capacity=15]
    nums2.push_back(80);  //    [Size=12,Capacity=15]
    nums2.push_back(100); //    [Size=13,Capacity=15]
    std::cout << "size of vector = \t\"" << nums2.size() << "\"\t Bytes." << std::endl;
    std::cout << "Capacity of vector = \t\"" << nums2.capacity() << "\"\t Bytes." << std::endl;

    HelpingFunctions::PrintSeparatorFn();

    // --- Range-based for ---
    for (auto element : nums2)
    {
        // Print elements.
        std::cout << "n = \t" << element << "\n";
    }

    HelpingFunctions::PrintSeparatorFn();

    // --- Index-based for ---
    for (int i = 0; i < nums2.size(); i++)
    {
        std::cout << nums2[i] << "\n";
    }
    HelpingFunctions::PrintSeparatorFn();

    // --- Iterator-based for ---
    std::vector<int>::iterator it; // it's a pointer    // can replace with auto
    for (it = nums2.begin(); it != nums2.end(); ++it)
    {
        std::cout << "*it =\t" << *it << "\n";
    }

    // // Or with auto:
    // for (auto it = nums2.begin(); it != nums2.end(); ++it)
    // {
    //     std::cout << "*it =\t" << *it << "\n";
    // }

    /*
        You can use functions as with arrays:   (Check CPP_Reference_Website)
            push_back(), size(), erase(), etc.
    */

    HelpingFunctions::PrintSeparatorFn();
    HelpingFunctions::PrintTextFn("Sort():");
    HelpingFunctions::PrintSeparatorFn();

    // --- Sorting with lambda (descending) ---
    std::sort(nums2.begin(), nums2.end(), [](int a, int b) { return a > b; });

    for (auto it = nums2.begin(); it != nums2.end(); ++it)
    {
        std::cout << "*it =\t" << *it << "\n";
    }

    // --- Erase-remove idiom to remove all 80s ---
    nums2.erase(std::remove(nums2.begin(), nums2.end(), 80), nums2.end());

    HelpingFunctions::PrintSeparatorFn();
    HelpingFunctions::PrintTextFn("erase element = 80:");
    HelpingFunctions::PrintSeparatorFn();

    for (auto it = nums2.begin(); it != nums2.end(); ++it)
    {
        std::cout << "*it =\t" << *it << "\n";
    }

    return 0;
}

/*
================================================================================
|   Interview Questions & Answers - std::vector
|-------------------------------------------------------------------------------
| Q1: What is the difference between vector and array?
| A1: Array has fixed size at compile time; vector is dynamic and can grow/shrink at runtime.
|
| Q2: How does vector manage memory?
| A2: Allocates memory on the heap and resizes automatically as elements are added/removed.
|
| Q3: What is the difference between size and capacity?
| A3: Size is the number of elements; capacity is the allocated storage (may be larger than size).
|
| Q4: How do you remove all occurrences of a value?
| A4: Use erase-remove idiom: v.erase(std::remove(v.begin(), v.end(), value), v.end());
|
| Q5: How do you sort a vector in descending order?
| A5: std::sort(v.begin(), v.end(), [](int a, int b){ return a > b; });
|
| Q6: What happens if you access out-of-bounds index?
| A6: v[i] is undefined behavior; v.at(i) throws std::out_of_range exception.
|
| Q7: Can you store custom objects in a vector?
| A7: Yes, as long as they are copyable/movable.
================================================================================
*/
/*
================================================================================
|   Interview Questions & Answers - std::vector
|-------------------------------------------------------------------------------
| Q1: What is the difference between vector and array?
| A1: Array has fixed size at compile time; vector is dynamic and can grow/shrink at runtime.
|
| Q2: How does vector manage memory?
| A2: Allocates memory on the heap and resizes automatically as elements are added/removed.
|
| Q3: What is the difference between size and capacity?
| A3: Size is the number of elements; capacity is the allocated storage (may be larger than size).
|
| Q4: How do you remove all occurrences of a value?
| A4: Use erase-remove idiom: v.erase(std::remove(v.begin(), v.end(), value), v.end());
|
| Q5: How do you sort a vector in descending order?
| A5: std::sort(v.begin(), v.end(), [](int a, int b){ return a > b; });
|
| Q6: What happens if you access out-of-bounds index?
| A6: v[i] is undefined behavior; v.at(i) throws std::out_of_range exception.
|
| Q7: Can you store custom objects in a vector?
| A7: Yes, as long as they are copyable/movable.
|
| Q8: What is the difference between std::vector and std::array?
| A8: std::vector is dynamic (size can change at runtime, heap-allocated), std::array is fixed-size (size known at compile time, stack-allocated by default).
|
| Q9: How do you dynamically allocate a std::vector?
| A9: std::vector<int>* pv = new std::vector<int>(10); // rarely needed, prefer stack allocation.
|
| Q10: What is the erase-remove idiom in C++?
| A10: A common pattern to remove elements by value from a container:
|      v.erase(std::remove(v.begin(), v.end(), value), v.end());
|
| Q11: How do you iterate over a vector in C++?
| A11: Use range-based for, index-based for, or iterator-based for loops.
|
| Q12: What is the difference between push_back() and emplace_back()?
| A12: push_back() copies/moves an object into the vector; emplace_back() constructs the object in-place, avoiding unnecessary copies/moves.
|
| Q13: How do you pre-allocate memory for a vector?
| A13: Use reserve(n) to allocate capacity without changing the size.
|
| Q14: What happens if you exceed the capacity of a vector?
| A14: The vector automatically allocates more memory (usually doubles the capacity).
================================================================================
*/