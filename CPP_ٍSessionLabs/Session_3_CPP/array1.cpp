#include <iostream>
#include <array>

/**
 *
 *
 * // How it's implemented inside std namespace for example
namespace my_std
{
    template <class T>
    struct myArray_t
    {
        // Pointer to character
        T *pch;
    }
}
// When using
my_std::myArray_t<T>
 *
 */

int main()
{
    // C-style array.
    // int arr1[5] = {1,2,3,4,5};
    // int arr2[] = {1,2,3,4,5};

    // // cpp-style array.
    // std::array<char, 5> word; // allocate in Stack. {garbage}

    // std::cout << "please enter array elements\n";
    // for (char element : word)
    // {
    //     std::cin >> element; // fill the array word elements one by one. "Example: letter"
    // }
    // for (char element : word)
    // {
    //     std::cout << element << std::endl; // print the array word elements one by one.
    // }


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


    return 0;
}