#include <iostream>
#include <set>

struct Person
{
    Person(int pAge, std::string pName) : age{pAge}, name{pName}
    {
    }

    int age;
    std::string name;
};

struct PersonCompare
{
    bool operator()(const Person &a, const Person &b) const
    {
        return a.age < b.age;
    }
};

int main()
{
    std::set<Person> people;

    people.insert(Person(32, "Mohame"));
    people.insert(Person(20, "Abdelrahman"));

    for (auto person : people)
    {
        std::cout << "person name: " << person.name << "\n";
    }

    return 0;
}