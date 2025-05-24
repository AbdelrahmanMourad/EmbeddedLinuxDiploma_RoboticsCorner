

/*  =====================================================================================================
    Task(8.3):
    ==========

        Requirements:
            -   Write a program that defines an array of integers.
            -   Sort the array in a descending order using the "std::sort" function and a user-provided lambda
                function as a predicate.
            -   Let the user enter the number of elements followed by the elements of the array.

        Example:
            Input:
                Enter the size of the array: 5
                Enter 5 elements: 10 80 -7 90 -60
            Output:
                Original array: 10 80 -7 90 -60
                Sorted array in descending order: 90 80 10 -7 -60

    =====================================================================================================
*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <algorithm> // For std::sort

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    int n;                                        // Number of Elements {Array Size}.
    std::cout << "Enter the size of the array: "; //  Msg.
    std::cin >> n;                                // Get value from user.

    int *arr = new int[n];

    std::cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    // Print original array
    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Sort in descending order using std::sort and a lambda predicate
    std::sort(arr, arr + n, [](int a, int b)
              {
                  return a > b; // Descending order
              });

    // Print sorted array
    std::cout << "Sorted array in descending order: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    delete[] arr;
    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
