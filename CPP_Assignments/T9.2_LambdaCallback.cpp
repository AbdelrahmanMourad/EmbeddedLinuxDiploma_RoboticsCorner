
/*________________________________________________________________________________________________________

    Task(9.2): Lambda Callback:
    ---------------------------

    Steps:
        1.  Input Two Vectors:
            ○   Accept an integer n from the user, which represents the size of the two vectors.
            ○   Input n integers for the first vector (v1) and the second vector (v2).
        2.  Calculate Function:
            ○   Implement the function """void Calculate(std::function<bool(void>) swap, std::function<bool(void>) print)"""" that:
                -   Takes two lambda functions: one for swapping and sorting (swap) and one for printing (print).
                -   Calls the swap function, which swaps the elements between v1 and v2 and sorts v2.
                -   If the swapping is successful (i.e., swap returns true), the print function is
                    called to display the result. Otherwise, print an error message.
        3.  Swap Lambda Function:
            ○   Define a lambda function swab that:
                -   Sorts v2 using std::sort to arrange its elements in ascending order.
                -   Swaps elements between v1 and v2:
                    ▪  Iterates through both vectors, swapping each corresponding element.
                    ▪  The elements in v1 are replaced by the sorted elements from v2, and
                        the elements in v2 are replaced by the original values from v1.
                -   Returns true to indicate a successful swap.
        4.  Print Lambda Function:
            ○   Define a lambda function print that:
                -   Prints a message indicating that the elements have been swapped.
                -   Displays the contents of both vectors (v1 and v2) after the swap.
                -   v1 now holds the sorted elements from v2, and v2 holds the original elements from v1.
        5.  Main Function:
            ○   In the main() function, prompt the user to input the elements of the two vectors.
            ○   Call the Calculate() function, passing the swab lambda function for swapping and
                the print lambda function for displaying the results.

___________________________________________________________________________________________________________○▪•-
*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <functional> // for std::function
#include <algorithm>  // for std::sort, std::random_shuffle, std::swap

/*  -------------------------------------------------------------------
                        Functions Prototype
    ------------------------------------------------------------------- */
namespace HelpingFunctions
{
    void print_vector(const std::string &&str1 = " ",                   /* string to print before */
                      const std::vector<int> &vec = std::vector<int>(), /* vector to print in the middle */
                      const std::string &&str2 = " ")                   /* string to print after */
    {
        std::cout << str1 << "\t";        // Print the provided 1st string message.
        for (auto element : vec)          // Iterate the vector.
            std::cout << element << "\t"; // Print the vector values on one line.
        std::cout << str2 << std::endl;   // Print the provided 2nd string message.
    }
}

void Calculate(std::function<bool(void)> swap, std::function<bool(void)> print)
{
    // call the swap function to sort v2 and swap elements between v1 and v2
    if (swap())
        print(); // if swap is successful, we call the print.
    else
        std::cout << "Error: swap/sort operation failed.\n"; // print error message if swap was failed.
}

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // Take input size of vectors {n} from user.
    int n = 0;
    std::cout << "Please Enter vector size: ";
    std::cin >> n;

    // Define the two vectors , size=n
    std::vector<int> v1(n);
    std::vector<int> v2(n);

    HelpingFunctions::print_vector("v1 at initialize:", v1);
    HelpingFunctions::print_vector("v2 at initialize:", v2, "\n");

    // Assignation of vectors with random numbers.
    for (auto i = 0; i < v1.size(); i++)
    {
        v1[i] = (rand() + rand()) % 100;
        v2[i] = (rand() + rand()) % 100;
    }

    // Print after swapping.
    HelpingFunctions::print_vector("v1 random values:", v1);
    HelpingFunctions::print_vector("v2 random values:", v2, "\n");

    // Shuffle v1 elements randomly... Not assigning random values.
    std::random_shuffle(v1.begin(), v1.end());
    std::random_shuffle(v2.begin(), v2.end());

    // Print after shuffle.
    HelpingFunctions::print_vector("v1 after shuffle:", v1);
    HelpingFunctions::print_vector("v2 after shuffle:", v2, "\n");

    /**************************************************************************************/
    // Implement two lambda functions:
    auto lambda_1_swap = [&]() -> bool
    {
        // sort v2 in ascending (small to large) order using std::sort
        std::sort(v2.begin(), v2.end(), [](int a, int b)
                  { return a < b; });

        // iterate through both vectors, swapping each corresponding element
        for (auto i = 0; i < v1.size(); i++)
            std::swap(v1[i], v2[i]); // swaps elements between v1 and v2.

        // to indicate a successful swap, return true.
        return true;
    };

    auto lambda_2_print = [&v1, &v2]() -> bool
    {
        // Print a message indicating that the elements in both vectors has been successfully swapped.
        std::cout << "The swap was successfully done.\n";

        // Display vectors content after swap.
        HelpingFunctions::print_vector("v1 after v2 sort and swap:", v1);
        HelpingFunctions::print_vector("v2 after v2 sort and swap:", v2, "\n");

        return true;
    };

    // Call the calculate function, passing the two lambdas as parameters.
    Calculate(lambda_1_swap, lambda_2_print);

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
