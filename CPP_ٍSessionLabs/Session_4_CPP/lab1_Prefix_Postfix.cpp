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