/*________________________________________________________________________________________________________

    Task(15.3):  Struct and Lambda:
    ------------------------------

    Requirements:
        1.  Record Structure:
            *   Define a struct called Record with the following attributes:
                -   name: a string representing the name of a character.
                -   power_level: an integer representing the character’s power level.
            *   Include a Print_Data() method in Record that prints the name and power level in the format:
                -   Name: <name>, Power Level: <power_level>.
        2.  Lambdas for Sorting:
            *   Create two lambda functions to sort the records:
                -   CmpareByName: A lambda that sorts records in descending order by name.
                -   CmpareByPowerLevel: A lambda that sorts records in descending order by power_level.
        3.  Vector of Records:
            *   Create a std::vector of Record objects with initial data, e.g.,
                { "Erin", 100 }, {"Armin", 80 }, etc.
        4.  Sorting and Displaying Data:
            *   Use std::sort and the created lambdas to sort the vector:
                -   First, sort by name and print the results.
                -   Then, sort by power_level and print the results.

___________________________________________________________________________________________________________*/

/*  ===================================================================
                    Included Libraries.
    =================================================================== */
#include <iostream>   // For input/output operations.
#include <vector>     // For std::vector container.
#include <algorithm>  // For std::sort function.
#include <functional> // For std::function.

/*  ===================================================================
                        Functions Prototype
    =================================================================== */
// Define the Record structure.
struct Record
{
    std::string name; // Character's name.
    int power_level;  // Character's power level.

    // Method to print the data of the Record.
    void Print_Data() const { std::cout << "Name: <" << this->name << ">\t, Power Level: <" << this->power_level << ">\n"; }
};

// Namespace for helper functions.
namespace HelpingFunc
{
    // Function to display all records in a vector.
    void DisplayVector(const std::vector<Record> &vec)
    {
        for (auto &obj : vec)
            obj.Print_Data(); // Call the Print_Data method for each Record.
    }
};

/*  ===================================================================
                        Entry Point
    =================================================================== */
int main()
{
    // Step 1: Create a vector of Record objects with initial data.
    std::vector<Record> records{
        {"Erin", 100},
        {"Armin", 80},
        {"Zeke", 120},
        {"Levi", 150},
        {"Mikasa", 90}};

    // Step 2: Display the original vector.
    std::cout << "Original Records:\n";
    HelpingFunc::DisplayVector(records);

    /*_______________CompareByName_______________*/
    // Step 3: Lambda function to sort records by name in descending order.
    std::function<bool(const Record &, const Record &)> CompareByName = [](const Record &a, const Record &b) -> bool
    {
        return a.name > b.name; // Descending order by name.
    };

    // Step 4: Sort the vector by name using std::sort and the lambda.
    std::sort(records.begin(), records.end(), CompareByName);

    // Step 5: Display the sorted vector by name.
    std::cout << "\nRecords Sorted by Name (Descending):\n";
    HelpingFunc::DisplayVector(records);

    /*_______________CmpareByPowerLevel_______________*/
    // Step 6: Lambda function to sort records by power_level in descending order.
    std::function<bool(const Record &, const Record &)> CompareByPowerLevel = [](const Record &a, const Record &b) -> bool
    {
        return a.power_level > b.power_level; // Descending order by power_level.
    };

    // Step 7: Sort the vector by power_level using std::sort and the lambda.
    std::sort(records.begin(), records.end(), CompareByPowerLevel);

    // Step 8: Display the sorted vector by power_level.
    std::cout << "\nRecords Sorted by Power Level (Descending):\n";
    HelpingFunc::DisplayVector(records);

    return 0;
}

/*___________________________________________________________________________________________________________
    Summary of Steps:
    -----------------
    1. Defined a `Record` struct with attributes `name` and `power_level` and a method `Print_Data`.
    2. Created a vector of `Record` objects with initial data.
    3. Used a lambda function to sort the vector by name in descending order.
    4. Used another lambda function to sort the vector by power_level in descending order.
    5. Displayed the vector before and after sorting.

    Interview Questions:
    --------------------
    1. What is the difference between `std::sort` and `std::stable_sort`?
    2. How do lambda functions work in C++? Can you explain their syntax?
    3. What is the difference between composition and aggregation in object-oriented programming?
    4. Why is `std::vector` preferred over raw arrays in modern C++?
    5. How does the `std::function` type work, and when should it be used?
___________________________________________________________________________________________________________*/