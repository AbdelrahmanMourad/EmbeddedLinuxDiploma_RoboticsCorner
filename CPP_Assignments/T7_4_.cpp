/*  ________________________________________________________________________________________________________

    Task(7.4):
    ----------
        Write a C++ program to find the most frequent element in an array of integers.

        Example:
            Original array: 4 5 9 12 9 22 45 7
            Most occurred number: 9

        HINT:
            use another array to count the frequency
    ___________________________________________________________________________________________________________
*/

// Include libraries.
#include <iostream>
#include <vector>
#include <unordered_map>

// Prototypes.
void PrintVector(const std::vector<int> &arr);
void findMostFrequentWithArray(const std::vector<int> &arr_original);
void findMostFrequentWithUnodrderdMap(const std::vector<int> &arr);

// Entry Point.
int main()
{
    // Initialize vector with data.
    std::vector<int> numbers_vector = {4, 5, 9, 12, 9, 22, 45, 7};

    // Print Original.
    std::cout << "Original array: ";
    PrintVector(numbers_vector);

    findMostFrequentWithArray(numbers_vector);
    findMostFrequentWithUnodrderdMap(numbers_vector);

    return 0;
}

// Implementation.
void PrintVector(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void findMostFrequentWithArray(const std::vector<int> &arr_original)
{
    const int MAX_NUMBER_VALUE = 100; // Adjust based on known value range
    int arr_frequency[MAX_NUMBER_VALUE] = {0};
    int mostFrequent = arr_original[0], maxCount = 0;

    for (int num : arr_original)
    {
        arr_frequency[num]++;
        if (arr_frequency[num] > maxCount)
        {
            maxCount = arr_frequency[num];
            mostFrequent = num;
        }
    }

    std::cout << "Most occurred number: " << mostFrequent << std::endl;
}

void findMostFrequentWithUnodrderdMap(const std::vector<int> &arr)
{
    std::unordered_map<int, int> frequency;
    int mostFrequent = arr[0];
    int maxCount = 0;

    // Count occurrences
    for (int num : arr)
    {
        frequency[num]++;
        if (frequency[num] > maxCount)
        {
            maxCount = frequency[num];
            mostFrequent = num;
        }
    }

    std::cout << "Most occurred number: " << mostFrequent << std::endl;
}
