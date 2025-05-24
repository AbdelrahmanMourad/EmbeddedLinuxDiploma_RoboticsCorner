/*  =====================================================================================================
    Task(8.2):
    ==========

        Requirements:
            -   Write a C++ program to sort an array of integers in ascending order using function pointers.
            -   Allow the user to choose between different sorting algorithms (e.g., bubble sort, selection sort)
                using function pointers.

        Example:
            Input:
                Enter the number of elements: 5
                Enter 5 integers: 50 70 80 -7 10
                Choose a sorting algorithm:
                1. Bubble Sort
                2. Selection Sort
                Enter your choice (1 or 2): 1


            Output:
                Sorted array: -7 10 50 70 80

    =====================================================================================================
*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void printArray(const int arr[], int size);
/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */

int main()
{
    int size;

    // Get the number of elements
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    int *arr = new int[size]; // Dynamic memory allocation for array

    // Get the elements from the user
    std::cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    // Choose the sorting algorithm
    char choice;
    std::cout << "Choose a sorting algorithm:\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    // Function pointer for sorting
    void (*sortFunction)(int[], int) = nullptr;

    // Assign the correct sorting function
    if (choice == 1)
    {
        sortFunction = bubbleSort;
    }
    else if (choice == 2)
    {
        sortFunction = selectionSort;
    }
    else
    {
        std::cout << "Invalid choice! Exiting...\n";
        delete[] arr;
        return 1;
    }

    // Call the selected sorting function
    sortFunction(arr, size);

    // Print the sorted array
    std::cout << "Sorted array: ";
    printArray(arr, size);

    // Cleanup dynamically allocated memory
    delete[] arr;

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
// Function to perform Bubble Sort
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]); // Swap elements
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Update min index
            }
        }
        std::swap(arr[i], arr[minIndex]); // Swap elements
    }
}

// Function to print the array
void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
