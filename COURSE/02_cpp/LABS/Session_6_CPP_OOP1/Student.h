#include <iostream>
#include <vector>

/*-------------------Class Declaration-------------------*/
class Student
{
public:
    // Setters()
    void setId(int id);
    void setName(std::string name);
    void setAge(int age);
    void addSubject(std::string subject);
    void removeSubject(std::string subject);
    // Getters()
    int getId();
    int getAge();
    std::string getCountry();
    std::string getName();
    

private:
    int id;
    int age;
    std::string name;
    std::string country;
    std::vector<std::string> Subject{10};
};