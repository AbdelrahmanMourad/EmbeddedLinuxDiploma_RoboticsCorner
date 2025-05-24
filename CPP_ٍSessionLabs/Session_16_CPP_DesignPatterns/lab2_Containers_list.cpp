/*
    list container
        -   doubly linked list
        -   no random access
        -   no bounds checking
        -   no iterators
        -   no copy constructor
        -   no assignment operator
        -   no destructor
        -   no move constructor
        -   no move assignment operator
        -   no swap function
        -   no clear function
        -   no size function
        -   no empty function
*/

#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    // Create Lists.
    std::list<int> list_{1, 2, 3}; // initializer list
    std::list<int> nums_1{list_};  // copy constructor
    std::list<int> nums_2;
    nums_2.assign(list_.begin(), list_.end()); // Use Modifier Method. {Search: list cpp reference}.
    // Using Algorithms with it.
    std::for_each(list_.begin(), list_.end(), [](int &element)
                  { element *= 2; });

    for (auto element : list_)
    {
        std::cout << "List element: " << element << std::endl;
    }

    return 0;
}