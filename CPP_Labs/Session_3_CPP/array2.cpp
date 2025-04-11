#include <iostream>
#include <array>
#include <algorithm>

int main()
{

    std::array<char, 6> word; // allocate in Stack. {garbage}

    // to fill all elements in the array with 0
    // word.fill(0);
    // word.fill('0');
    word.fill('m');

    for (char element : word)
    {
        // std::cout << element << "\n";                   // m
        printf("%X  ", element);                        // 6d
        std::cout << static_cast<int>(element) << "\n"; // m
    }

    // initialize array
    std::array<char, 6> welcome_word{"hello"};
    // std::array<char,6> welcome_word {'h','e','l','l','o'};

    // swap array func
    welcome_word.swap(word);

    for (char element : welcome_word)
    {
        std::cout << element;
    }

    // sort and print.
    std::sort(welcome_word.begin(), welcome_word.end());
    // std::sort(welcome_word.begin(), welcome_word.end()); // How to make ascending/descending ???
    for (char element : welcome_word)
    {
        std::cout << element;
    }

    return 0;
}

