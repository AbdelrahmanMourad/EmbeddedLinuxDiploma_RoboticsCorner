/*  ________________________________________________________________________________________________________

    Task(7.3):
    ----------
        Write a C++ program to find the largest three numbers in an array.

        instructions:
            - The array can be hard coded in the code, but try with different values to make sure
            - that the algorithm works as expected before submitting.

        Example:
            - Original array: 7 12 9 15 19 32 56 70
            - Three largest elements are: 70, 70, 32
    ___________________________________________________________________________________________________________

    
   =====================================================================================
   | Approach        | Time Complexity    | Space Complexity | Notes                   |
   |=================|====================|==================|=========================|
   | Sort & Pick     | O(n log n)         | O(1)             | Simple, but slower      |
   | Linear Scan     | O(n)               | O(1)             | Fastest for known top k |
   | Min-Heap        | O(n log 3) ≈ O(n)  | O(3)             | Best for streaming data |
   =====================================================================================
   
   Recommendations:
        - If the vector is **small**, sorting (`sort()` then picking top 3) works fine.
        - If the vector is **large**, prefer **linear scan** (`O(n) approach`).
        - If processing **real-time/streaming data**, use **Min-Heap (`priority_queue`)**.
    
   ___________________________________________________________________________________________________________
*/

/*  -------------------------------------------------------------------
                        Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <algorithm> // Sorting vector.
#include <queue>     // Priority-Queue for Min-Heap Method.

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
void findTopThreeSorted(std::vector<int> vec /*By Value to not change the original input*/);
void findTopThreeLinearScan(const std::vector<int> &vec);
void findTopThreeHeap(const std::vector<int> &vec);

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // Initialize vector {Hard-Coded}.
    std::vector<int> numbers_vector{7, 12, 9, 15, 19, 32, 56, 70};

    // Find top three.
    findTopThreeSorted(numbers_vector);
    findTopThreeLinearScan(numbers_vector);
    findTopThreeHeap(numbers_vector);

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
// 1. Sort the Vector (Simple Approach)
// Sort the vector in descending order and pick the top three numbers.
// ✅ Easy, but requires full sorting (O(n log n)).
void findTopThreeSorted(std::vector<int> vec /*By Value to not change the original input*/)
{
    std::sort(vec.begin(), vec.end(), std::greater<int>()); // Sort in descending order
    std::cout << "Three largest elements are: " << vec[0] << ", " << vec[1] << ", " << vec[2] << std::endl;
}

// 2. Using a Linear Scan (O(n))
// Maintain three variables for the largest, second largest, and third largest values.
// ✅ Much faster (O(n)), avoids sorting.
void findTopThreeLinearScan(const std::vector<int> &vec)
{
    int first = 0, second = 0, third = 0;

    for (int num : vec)
    {
        if (num > first)
        {
            third = second;
            second = first;
            first = num;
        }
        else if (num > second)
        {
            third = second;
            second = num;
        }
        else if (num > third)
        {
            third = num;
        }
    }
    std::cout << "Three largest elements are: " << first << ", " << second << ", " << third << std::endl;
}

// 3. Using a Min-Heap (O(n log 3) ≈ O(n))
// Use a priority queue (min-heap) of size 3 to track the top numbers dynamically.
// ✅ Efficient with a priority queue, useful for real-time processing
void findTopThreeHeap(const std::vector<int> &vec)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int num : vec)
    {
        minHeap.push(num);
        if (minHeap.size() > 3)
        {
            minHeap.pop(); // Keep only top 3 largest numbers
        }
    }

    std::vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    std::cout << "Three largest elements are: ";
    for (auto it = result.rbegin(); it != result.rend(); ++it)
    { // Reverse order
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
