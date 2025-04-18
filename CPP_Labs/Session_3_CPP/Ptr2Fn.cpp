#include <iostream>
#include <array>
#include <algorithm>

/**
 *
 * Pointer to Functions.
 *
 *      returnType  (*Fptr) (ParamType)
 *
 *  */

// Function for example
int add(int a, int b)
{
    return a + b;
}
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    // declar a ptr to function.
    int (*calculator_ptr)(int, int);

    // Assign.
    calculator_ptr = &add;
    // calculator_ptr = add;   // both true, as fn name is a ptr itself

    // declare and assign.
    // int (*calculator_ptr)(int, int) = add;
    // int (*calculator_ptr)(int, int) = &add;

    // Invoke/Call ptr2fn.
    auto sum = calculator_ptr(10, 20);
    std::cout << "sum= " << sum << std::endl;

    // // Declare , assign ptr2fn.
    // int (*PFun)(int, int) = &fun;

    // array
    std::array<int, 6> nums{100, 99, 5, 180, 1000, 33};

    // sort
    std::sort(nums.begin(), nums.end(), compare);
    // a = 1000 , b = 5 , a > b (true)  <<<< descending order.
    // a = 1000 , b = 5 , a < b (false)  <<<< ascending order.

    for (auto element : nums)
    {
        std::cout << element;
    }

    return 0;
}
