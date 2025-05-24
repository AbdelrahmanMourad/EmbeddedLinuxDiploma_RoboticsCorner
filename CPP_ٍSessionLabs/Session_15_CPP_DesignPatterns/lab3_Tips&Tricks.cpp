#include <iostream>      // For input/output operations
#include <vector>        // For using std::vector container
#include <utility>       // For std::pair (not used here, but included)
#include <algorithm>     // For std::sort

// Define a structure to hold a person's name and address
struct Record
{
    std::string name;    // Person's name
    std::string addr;    // Person's address
};

// Functor (function object) to compare Records by address
struct compareByAddress
{
    // Overload operator() to compare two Records by their address
    bool operator()(const Record &a, const Record &b) const
    {
        return a.addr < b.addr; // Returns true if a's address is less than b's
    }
};

// Functor to compare Records by name
struct CompareByName
{
    // Overload operator() to compare two Records by their name
    bool operator()(const Record &a, const Record &b) const
    {
        return a.name < b.name; // Returns true if a's name is less than b's
    }
};

int main()
{
    // Create a vector to store Record objects
    std::vector<Record> records;

    // Create first record and set its name and address
    Record r1;
    r1.name = "Ahmed";
    r1.addr = "Cairo";

    // Create second record using initializer list
    Record r2{"Mohamed", "Alex"};

    // Add both records to the vector
    records.push_back(r1);
    records.push_back(r2);

    // Sort the records by name using CompareByName functor
    std::sort(records.begin(), records.end(), CompareByName());
    std::cout << "Sorted by Name:" << std::endl;
    // Print all records after sorting by name
    for (auto record : records)
    {
        std::cout << "\tName: " << record.name << "\t, Address: " << record.addr << std::endl;
    }

    // Sort the records by address using compareByAddress functor
    std::sort(records.begin(), records.end(), compareByAddress());
    std::cout << "Sorted by Address:" << std::endl;
    // Print all records after sorting by address
    for (auto record : records)
    {
        std::cout << "\tName: " << record.name << "\t, Address: " << record.addr << std::endl;
    }

    // The following code is commented out and not used in this example:
    // std::vector<int> nums(5);
    // nums.push_back(5);
    // nums.push_back(10);//6
    // std::vector<std::pair<int, int>> pairs;

    return 0; // Indicate successful program termination
}