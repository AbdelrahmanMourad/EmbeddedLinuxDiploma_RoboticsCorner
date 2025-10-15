/*  ===================================================================
                            Included Libraries.
    =================================================================== */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
/*  ===================================================================
                            Functions
    =================================================================== */
void printVector(const std::vector<int> &vec, const std::string &msg)
{
    std::cout << msg << ":\n\t\t\t\t";
    // for (int num : vec)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    for (auto i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}
/*  ===================================================================
                            Main function - Entry Point
    =================================================================== */
int main()
{
    std::vector<int> vec = {50, 20, 70, 10, 90};

    // Original Vector
    printVector(vec, "Original Vector");

    // Sorting (Ascending Order)
    std::sort(vec.begin(), vec.end());
    printVector(vec, "Sorted Vector (Ascending)");

    // Sorting (Descending Order)
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    printVector(vec, "Sorted Vector (Descending)");

    // Searching (Binary Search)
    std::sort(vec.begin(), vec.end());
    bool found = std::binary_search(vec.begin(), vec.end(), 70);
    std::cout << "Binary Search (70 exists?): " << (found ? "Yes" : "No") << std::endl;

    // Finding Min/Max
    int minVal = *std::min_element(vec.begin(), vec.end());
    int maxVal = *std::max_element(vec.begin(), vec.end());
    std::cout << "Min Element: " << minVal << ", Max Element: " << maxVal << std::endl;

    // Reversing the Vector
    std::reverse(vec.begin(), vec.end());
    printVector(vec, "Reversed Vector");

    // Accumulate (Sum of Elements)
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of Elements: " << sum << std::endl;

    // Remove Duplicates
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    printVector(vec, "Vector after Removing Duplicates");

    return 0;
}