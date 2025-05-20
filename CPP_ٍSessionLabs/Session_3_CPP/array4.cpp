#include <iostream>
#include <array>
#include <algorithm>


/*
*   NOTE:   
        array in c are pointers.
        array in cpp are containers.
*/

/*
 *   Passing array by value/reference
 */
void inputArray(int input[])
{
}

void input_byValue(std::array<int, 3> list)
{
    std::cout << "input_byValue()n\n";
    for (auto element : list)
    {
        std::cout << "enter element: ";
        std::cin >> element;
    }
}

void input_byReference(std::array<int, 3> &list)
{
    std::cout << "input_byReference()n\n";
    for (auto &element : list)
    {
        std::cout << "Ref enter element: ";
        std::cin >> element;
    }
}

void output(std::array<int, 3> list)
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

    output(arr);
    input_byReference(arr);
    output(arr);
    input_byValue(arr);
    output(arr);

    return 0;
}
