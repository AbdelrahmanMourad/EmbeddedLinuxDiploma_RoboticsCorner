/** ==============================================================================================
    Assignment Day 01: Student Info Management - C++ Mini Project:
    ==============================================================

    [Review C++ , String , Files]
        This program allows a user to input student details
        (name, age, grade), save them in a file, and retrieve
        them for display.

    Concepts used:
        - Structs
        - File Operations (ofstream, ifstream)
        - Basic Input/Output

    ----------------------------------------------------------------------------------------------
    You are required to write a C++ program that performs the following:
        🔹 (name, age, grade) from user input
        🔹 named students.txt
        🔹 back from the file and displays it in the console
        🔹 Use struct, string, file operations (ofstream, ifstream), and a loop

    📌 Delivers
        •   Submit a .cpp file of your code
        •   Output screenshot
        •   Make sure file input/output works correctly

    ==============================================================================================
**/

/*  -----------------------------------------------------------------
                            Included Libraries
    -----------------------------------------------------------------*/
#include <iostream> // For console input/output
#include <fstream>  // For file handling
#include <string>   // For handling string inputs

/*  -----------------------------------------------------------------
                            Declarations
    -----------------------------------------------------------------*/
// Define a struct to store student details
struct Student
{
    std::string name;  // Student's name
    int age;           // Student's age
    std::string grade; // Student's grade
};

/*  -----------------------------------------------------------------
                            Prototypes
    -----------------------------------------------------------------*/
void getStudentInfo(Student &student);                                // Function to get user input for a student
void saveToFile(const Student &student, const std::string &filename); // Function to save student data into a file
void loadFromFile(Student &student, const std::string &filename);     // Function to read student data from a file

/*  -----------------------------------------------------------------
                            Entry Point
    -----------------------------------------------------------------*/
int main()
{
    Student student;                       // Create object instance
    std::string filename = "students.txt"; // Define filename ("path/filename.txt")

    // Get student details
    getStudentInfo(student);

    // Save student data to file
    saveToFile(student, filename);

    // Load student data back from file
    loadFromFile(student, filename);

    // Display student data
    std::cout << "\nData read from file:" << std::endl;
    std::cout << "Name: \t" << student.name << std::endl;
    std::cout << "Age: \t" << student.age << std::endl;
    std::cout << "Grade: \t" << student.grade << std::endl;

    return 0; // Indicate successful program execution
}

/*  -----------------------------------------------------------------
                            Implementation
    -----------------------------------------------------------------*/
// Function to get user input for a student
void getStudentInfo(Student &student)
{
    std::cout << "Enter student's name: ";
    getline(std::cin, student.name); // Read full name with spaces

    std::cout << "Enter student's age: ";
    std::cin >> student.age;
    std::cin.ignore(); // Clear input buffer after integer input

    std::cout << "Enter student's grade: ";
    getline(std::cin, student.grade); // Read full grade description
}

// Function to save student data into a file
void saveToFile(const Student &student, const std::string &filename)
{
    std::ofstream outFile(filename); // Open file for writing
    if (outFile)
    { // Check if file opened successfully
        outFile << student.name << std::endl;
        outFile << student.age << std::endl;
        outFile << student.grade << std::endl;
    }
    else
    {
        std::cout << "Error: Unable to open file for writing." << std::endl;
    }
}

// Function to read student data from a file
void loadFromFile(Student &student, const std::string &filename)
{
    std::ifstream inFile(filename);     // Open file for reading
    if (inFile)
    {                                   // Check if file opened successfully
        getline(inFile, student.name);  // Read name from file
        inFile >> student.age;          // Read age
        inFile.ignore();                // Clear buffer after reading integer
        getline(inFile, student.grade); // Read grade
    }
    else
    {
        std::cout << "Error: Unable to open file for reading." << std::endl;
    }
}
