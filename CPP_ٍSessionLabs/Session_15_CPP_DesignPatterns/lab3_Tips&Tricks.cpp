#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct Record
{
    std::string name;
    std::string addr;
};

struct compareByAddress
{
    bool operator()(const Record &a, const Record &b) const
    {
        return a.addr < b.addr;
    }
};

struct CompareByName
{
    bool operator()(const Record &a, const Record &b) const
    {
        return a.name < b.name;
    }
};

int main()
{
    std::vector<Record> records;

    Record r1;
    r1.name = "Ahmed";
    r1.addr = "Cairo";

    Record r2{"Mohamed", "Alex"};

    records.push_back(r1);
    records.push_back(r2);

    std::sort(records.begin(), records.end(), CompareByName());
    std::cout << "Sorted by Name:" << std::endl;
    for (auto record : records)
    {
        std::cout << "\tName: " << record.name << "\t, Address: " << record.addr << std::endl;
    }

    std::sort(records.begin(), records.end(), compareByAddress());
    std::cout << "Sorted by Address:" << std::endl;
    for (auto record : records)
    {
        std::cout << "\tName: " << record.name << "\t, Address: " << record.addr << std::endl;
    }

    // std::vector<int> nums(5);

    // nums.push_back(5);
    // nums.push_back(10);//6

    // std::vector<std::pair<int, int>> pairs;

    return 0;
}