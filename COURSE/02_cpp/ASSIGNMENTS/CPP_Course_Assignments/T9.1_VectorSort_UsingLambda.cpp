
/*________________________________________________________________________________________________________

    Task(9.1):
    ----------

        Write a program that checks if a series of integers entered by the user are consecutive numbers.
            1.  Input the Number of Elements:
                *   First, read an integer n from the user, which specifies how many numbers the user will input.
            2.  Input Elements into a Vector:
                *   Create a std::vector nums.
                *   Use a loop to input n integers from the user and store them in the vector.
            3.  Test Function:
                *   Implement the function """"bool test(std::vector<int> nums)"""" that:
                    -   Sorts the vector in ascending order using std::sort().
                    -   Loops through the sorted vector to check if every number is consecutive
                        (i.e., each number should be exactly 1 greater than the previous one).
                    -   Returns true if all numbers are consecutive, otherwise returns false.
            4.  Main Function:
                *   After accepting the user input, call the test() function.
                *   Print "True" if the numbers are consecutive, otherwise print "False".

___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <algorithm>

/*  -------------------------------------------------------------------
                        Functions
    ------------------------------------------------------------------- */
namespace Help_Debug
{
    void print_vec(const std::vector<int> &vec = std::vector<int>(), const std::string &&str1 = " ", const std::string &&str2 = " ")
    {
        std::cout << str1 << "\t";
        for (auto element : vec)
            std::cout << element << "\t";
        std::cout << str2 << "\n";
    }
}

bool test(std::vector<int> nums)
{
    // Sort the vector ascendingly.
    std::sort(nums.begin(), nums.end(), [](int x1, int x2) -> bool
              { return x1 < x2; });

    Help_Debug::print_vec(nums, "After sort:");

    // Check if every number is consecutive.
    for (auto i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return false;
    }
    return true;
}


/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // Take input size of numbers {n} from user.
    int n = 0;
    std::cout << "Please Enter how many numbers you want to enter: ";
    std::cin >> n;

    // Create a vector of the same size; to manage storing and operating on numbers.
    std::vector<int> num_vec(n);

    // Take the numbers from the user into the vector.
    std::cout << "Please enter the numbers now:\n";
    for (auto &element : num_vec)
        std::cin >> element;

    Help_Debug::print_vec(num_vec, "You entered:");

    int state = test(num_vec);

    if (state)
        std::cout << "True.\n";
    else
        std::cout << "False.\n";

    return 0;
}
