#include <iostream>
// #include <string>

using namespace std;

/*  ---------------------------------------------------------------------------------
                        Declaration
---------------------------------------------------------------------------------*/
// ENCAPSULATION.
// ABSTRACTION.
// struct Human        // Default is public
// {

//     // parameters
//     std::string name;
//     int age;
//     double weight;
//     // functions (methods)

//     void setAge(int ageInput)
//     {
//         age = ageInput;
//         std::cout << "Age set to: " << age << "\n";
//     }
//     int getAge(void)
//     {
//         return age;
//     }
//     void printHuman()
//     {
//         std::cout << "Age=" << age << " weight=" << weight << std::endl;
//     }
// };

// implementation

// class Human // Default is private
// {
// public:
//     /* Constructor:
//             - Same Name of class
//             - No ReturnType
//             - Called automatically when creating new instance/Object
//     */
//     // Human() = default;
//     Human();
//     Human(int age):  age_{age}, weight_{90}, name{"Unknown"}

//     void setAge(int age);
//     int getAge(void);
//     void printHuman();

// private:
//     // parameters
//     std::string name;
//     int age_;
//     double weight_;
//     // functions (methods)
// };

/*  ---------------------------------------------------------------------------------
                        Main
---------------------------------------------------------------------------------*/
int main()
{
    // Human Mohsen;
    // MyHelpingFunctions::print();

    // // Mohsen.age = 20;
    // Mohsen.setAge(20);
    // // Mohsen.weight = 100;
    // // std::cout << "Age= " << Mohsen.getAge() << "\n";
    // Mohsen.printHuman();

    // std::cout << sizeof(double) << " Bytes\t" << sizeof(float) << " Bytes\n";

    char arr_char[20]{"Mohamed"};
    std::string arr_str[20]{"Mohsen"};
    int arr_int[20]{1, 2, 3, 4, 5, 6, 78, 9};
    cout << "char arr= \t" << *arr_char << "\tAddrees=\t" << arr_char << "\n";
    cout << "int arr= \t" << *arr_int << "\tAddrees=\t" << arr_int << "\n";
    cout << "string arr= \t" << *arr_str << "\tAddrees=\t" << arr_str << "\n";

    double x06 = 5.55;
    long double x07 = 5.55;
    long double x07 = 5.55;
    
    cout << sizeof(x06) << "\t" << x06 << "\n";
    cout << sizeof(x07) << "\t" << x07 << "\n";
    cout << "-------------------------";
    int x0 = 5.5;
    long x05 = 5.5;
    long int x1 = 5.5;
    long long x2 = 5.5;
    long long int x3 = 5.5;
    cout << sizeof(x05) << "\t" << x05 << "\n";
    cout << sizeof(x0) << "\t" << x0 << "\n";
    cout << sizeof(x1) << "\t" << x1 << "\n";
    cout << sizeof(x2) << "\t" << x2 << "\n";
    cout << sizeof(x3) << "\t" << x3 << "\n";

    cout << "size=" << sizeof(long long) << "\n";
    return 0;
}

// void Human::setAge(int age)
// {
//     this->age_ = age;
//     std::cout << "Age set to: " << this->age_ << "\n";
// }

// int Human::getAge(void)
// {
//     return age_;
// }

// void Human::printHuman()
// {
//     std::cout << "Age=" << this->age_ << " weight=" << this->weight_ << std::endl;
// }

// namespace MyHelpingFunctions
// {
//     void print(void) { std::cout < "Eliwa\n"; }
// }