#include <iostream>
#include <array>
#include <algorithm>

/*  Search: cpp reference -> cpp array  */

int main()
{
    std::array<int, 4U> nums = {8, 9, 70, 8};
    std::array<int, 4U> list;

    list.swap(nums);

    // auto element = list[0]; /* "auto": takes the same data type of RHS and assign it to LHS  */

    for (auto element : list)
    {
        std::cout << "element= " << element << std::endl;
    }

    /*
        it == iterator
        can be var or int or array element data type
    */
    printf("_______________\n");
    for (/*std::array<int, 4U>::iterator*/ auto it = list.begin(); it != list.end(); ++it) // iterator to integer element in array.
    {
        std::cout << "list befor sort, element = " << it << "\n";
    }

    /*__________________Algorithms__________________*/
    std::sort(list.begin(), list.end()); // sort from begin to end.

    std::array<char, 3U> word{'m', 'a', 'n'};
    
    std::sort(word.begin(), word.end()); // sort from begin to end.

    printf("_______________\n");
    for (/*std::array<int, 4U>::iterator*/ auto it = list.begin(); it != list.end(); ++it) // iterator to integer element in array.
    {
        std::cout << "list element = " << it << "\n";
    }

    printf("_______________\n");
    for (/*std::array<int, 4U>::iterator*/ auto it = word.begin(); it != word.end(); ++it) // iterator to integer element in array.
    {
        std::cout << "word element = " << it << "\n";
    }

    return 0;
}