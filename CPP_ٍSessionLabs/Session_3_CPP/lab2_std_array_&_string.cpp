/*
================================================================================
|   std::array<char, N> - Study & Lab Summary
|-------------------------------------------------------------------------------
| - std::array is a fixed-size, stack-allocated array (C++11+).
| - Elements are NOT initialized by default (may contain garbage).
| - .fill(val): Set all elements to a value.
| - Initialization:
|     * std::array<char, 6> arr{"hello"}; // fills with 'h','e','l','l','o','\0'
|     * std::array<char, 6> arr{'h','e','l','l','o'}; // last element is '\0'
| - .swap(other): Swaps contents with another array of same type/size.
| - Iteration: Use range-based for for readability.
| - Printing:
|      *   Use printf("%X", val) for hex,
|      *   static_cast<int>(char) for ASCII.
| - Sorting:
|       Use std::sort(begin, end) for ascending (Default).
|       Use std::greater<> for descending.. std::sort(arr.begin(),arr.end(),std::greater<char>())
|       Use std::less<> for descending..... std::sort(arr.begin(),arr.end(),std::less<char>())
| - Looping on arrays of phrases:
|     * To loop character by character: use nested loops or range-based for.
|     * To loop word by word: use array of std::string or char* and loop outer array.
| - Tips:
|     * Always .fill() if you want a known initial value.
|     * Swapping is fast (no heap allocation).
|     * Sorting works like with C-style arrays.
| - Interview:
|     * What happens if you initialize with a string shorter than the array? (rest is '\0')
|     * How to sort descending? (std::sort(arr.begin(), arr.end(), std::greater<>()))
|     * How to loop on a large array of phrases character by character? Word by word?
================================================================================
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <functional> // for std::greater<> , std::less<>
#include <string>
#include <vector>

int main()
{
    // 1. Declaration (uninitialized, contains garbage)
    std::array<char, 6> word;

    // 2. Fill all elements with 'm'
    word.fill('m');

    // 3. Print each element in hex and as int (ASCII)
    std::cout << "word (filled with 'm') in hex and ASCII:\n";
    for (char element : word)
    {
        printf("%X  ", element);                        // Hex value
        std::cout << static_cast<int>(element) << "\n"; // ASCII value
    }

    // 4. Initialization with string literal (fills with 'h','e','l','l','o','\0')
    std::array<char, 6> welcome_word{"hello"};
    // Alternative: std::array<char,6> welcome_word {'h','e','l','l','o','\0'};

    // 5. Swap contents with another array
    welcome_word.swap(word);

    std::cout << "\nwelcome_word after swap (should be all 'm'):\n";
    for (char element : welcome_word)
    {
        std::cout << element;
    }
    std::cout << std::endl;

    // 6. Sort in ascending order and print (Default).
    std::sort(welcome_word.begin(), welcome_word.end());
    std::cout << "welcome_word after ascending sort (Default):\n";
    for (char element : welcome_word)
    {
        std::cout << element;
    }
    std::cout << std::endl;

    // 7. Sort in descending order and print
    std::sort(welcome_word.begin(), welcome_word.end(), std::greater<char>());
    std::cout << "welcome_word after descending sort:\n";
    for (char element : welcome_word)
    {
        std::cout << element;
    }
    std::cout << std::endl;

    // 8. Sort in ascending order and print
    std::sort(welcome_word.begin(), welcome_word.end(), std::less<char>());
    std::cout << "welcome_word after ascending sort:\n";
    std::cout << "Looping on char element : welcome_word:\n";
    for (char element : welcome_word)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // --- Looping on a large array of phrases ---

    // Example 1: Array of C-strings (const char*)
    const char *phrases1[] = {"Hello world", "C++ is fun", "Array of phrases"};
    int num_phrases1 = sizeof(phrases1) / sizeof(phrases1[0]);

    std::cout << "\nLooping character by character (C-string array):\n";
    for (int i = 0; i < num_phrases1; ++i)
    {
        std::cout << "Phrase " << i << ": ";
        for (const char *p = phrases1[i]; *p != '\0'; ++p)
        {
            std::cout << *p << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nLooping word by word (C-string array):\n";
    for (int i = 0; i < num_phrases1; ++i)
    {
        std::cout << "Phrase " << i << ": " << phrases1[i] << std::endl;
    }

    // Example 2: std::array of std::string
    std::array<std::string, 3> phrases2 = {"Modern C++", "std::array example", "Looping words"};
    std::cout << "\nLooping character by character (std::array<std::string>):\n";
    for (size_t i = 0; i < phrases2.size(); ++i)
    {
        std::cout << "Phrase " << i << ": ";
        for (char ch : phrases2[i])
        {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nLooping word by word (std::array<std::string>):\n";
    for (const auto &phrase : phrases2)
    {
        std::cout << phrase << std::endl;
    }

    // Example 3: std::vector of std::string
    std::vector<std::string> phrases3 = {"Vector phrase one", "Another phrase", "Last phrase"};
    std::cout << "\nLooping character by character (std::vector<std::string>):\n";
    for (size_t i = 0; i < phrases3.size(); ++i)
    {
        std::cout << "Phrase " << i << ": ";
        for (char ch : phrases3[i])
        {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nLooping word by word (std::vector<std::string>):\n";
    for (const auto &phrase : phrases3)
    {
        std::cout << phrase << std::endl;
    }

    return 0;
}

/*
================================================================================
|   Interview Q&A (added for phrases):
|-------------------------------------------------------------------------------
| Q: If we have a large array of multiple phrases, how can we loop on it character by character?
| A: Use nested loops: outer for each phrase, inner for each character in the phrase.
|
| Q: How can we loop on it word by word?
| A: Loop on the array/vector itself; each element is a word/phrase.
================================================================================
*/