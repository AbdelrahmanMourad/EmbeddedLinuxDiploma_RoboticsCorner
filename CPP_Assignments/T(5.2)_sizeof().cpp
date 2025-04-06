/*________________________________________________________________________________________________________

    Task(5.2):
    ----------
        Write a Program to Find the Size of int, float, double, and char.

    In C++, each datatype requires some memory to store data and the specific size can vary
    based on the programming language, compiler, and system architecture. In this program,
    you have to print the required memory (i.e. size in bytes) for int, float, double, and char
    data types on the console.

    For Example:Output:
        size of int: 4 bytes
        size of float: 4 bytes
        size of double: 8 bytes
        size of char: 1 bytes
___________________________________________________________________________________________________________*/

/* Include Section */
#include <iostream>

/* Entry Point */
int main()
{
    // Printing Statement.
    std::cout << "Sizeof(bool)          = " << sizeof(bool)         << " Bytes" << std::endl;
    std::cout << "Sizeof(char)          = " << sizeof(char)         << " Bytes" << std::endl;
    std::cout << "Sizeof(short)         = " << sizeof(short)        << " Bytes" << std::endl;
    std::cout << "Sizeof(int)           = " << sizeof(int)          << " Bytes" << std::endl;
    std::cout << "Sizeof(long)          = " << sizeof(long)         << " Bytes" << std::endl;
    std::cout << "Sizeof(long int)      = " << sizeof(long int)     << " Bytes" << std::endl;
    std::cout << "Sizeof(long long int) = " << sizeof(long long int)<< " Bytes" << std::endl;
    std::cout << "Sizeof(float)         = " << sizeof(float)        << " Bytes" << "\n";
    std::cout << "Sizeof(double)        = " << sizeof(double)       << " Bytes" << "\n";
    std::cout << "Sizeof(long double)   = " << sizeof(long double)  << " Bytes" << "\n";
    std::cout << "Sizeof(string)        = " << sizeof(std::string)  << " Bytes" << "\n";

    // Return E_OK Status.
    return 0;
}