#include <iostream>
// #include <string>
#include <cstring> // For strlen and strcpy.

class MyString
{
private:
    char *str_; // Pointer to a char[] that holds a c-style string.

public:
    MyString();                       // No-args constructor.
    MyString(const char *s);          // Parameterized/Overloaded Constructor
    MyString(const MyString &source); // Copy Constructor.
    MyString(MyString &&source);      // Move Constructor.
    ~MyString();                      // Destructor.

    MyString &operator=(const MyString &rhs); // Copy assignment operator.
    MyString &operator=(MyString &&rhs);      // Move assignment operator.

    // *** Unary operators *** are not needed in this example, but can be added if required.
    MyString operator-() const;
    // MyString operator++() const;
    // MyString operator++() const;
    // MyString operator!() const;

    // *** Binary operators *** are not needed in this example, but can be added if required.
    bool operator==(const MyString &rhs) const
    {
        return (strcmp(str_, rhs.str_) == 0); // Compare the strings for equality.
    }
    bool operator!=(const MyString &rhs) const
    {
        return !(*this == rhs); // Use the equality operator to check for inequality.
    }
    bool operator<(const MyString &rhs) const
    {
        return (strcmp(str_, rhs.str_) < 0); // Compare the strings lexicographically.
    }
    bool operator>(const MyString &rhs) const
    {
        return (strcmp(str_, rhs.str_) > 0); // Compare the strings lexicographically.
    }
    bool operator<=(const MyString &rhs) const
    {
        return !(*this > rhs); // Use the greater than operator to check for less than or equal to.
    }
    bool operator>=(const MyString &rhs) const
    {
        return !(*this < rhs); // Use the less than operator to check for greater than or equal to.
    }
    bool operator!() const
    {
        return (strlen(str_) == 0); // Check if the string is empty.
    }
    MyString operator+(const MyString &rhs) const
    {
        char *new_str = new char[strlen(str_) + strlen(rhs.str_) + 1]; // Allocate memory for the new string.
        strcpy(new_str, str_);                                         // Copy the current string to new_str.
        strcat(new_str, rhs.str_);                                     // Concatenate the rhs string to new_str.
        MyString temp{new_str};                                        // Create a temporary MyString object with the new string.
        delete[] new_str;                                              // Free the allocated memory for new_str.
        return temp;                                                   // Return the temporary MyString object.
    }
    MyString operator-(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator*(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator/(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator%(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator&(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator|(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator^(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator~() const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator<<(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator>>(const MyString &rhs) const
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return MyString(); // Return an empty MyString object for now.
    }
    MyString operator+=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator-=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator*=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator/=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator%=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator&=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator|=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator^=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }

    MyString operator<<=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }
    MyString operator>>=(const MyString &rhs)
    {
        // This operator is not implemented in this example.
        // It can be implemented to perform some operation on the strings.
        return *this; // Return the current object for now.
    }

    // Methods
    void Display() const; // Print function.

    // Getters
    int get_length() const;      /// Returns the length of the string.
    const char *get_str() const; /// Returns the string.
};

MyString::MyString() { std::cout << "Default Constructor Called.\n"; } // No-args constructor.

// Parameterized/Overloaded Constructor.
MyString::MyString(const char *s) : str_{nullptr} // Initialize str_ to nullptr to avoid dangling pointer.
{
    if (s) // Check if the input string is not null.
    {
        str_ = new char[strlen(s) + 1]; // Allocate memory for the new string.
        strcpy(str_, s);                // Copy the string from s to this object.
    }
    else
    {
        str_ = new char[1]; // Allocate memory for an empty string.
        str_[0] = '\0';     // Set it to an empty string.
    }
    std::cout << "Parameterized Constructor Called.\n"; // Print message.
}

// Copy Constructor.
MyString::MyString(const MyString &source) : str_{nullptr} // Initialize str_ to nullptr to avoid dangling pointer.
{
    str_ = new char[strlen(source.str_) + 1];  // Allocate memory for the new string.
    strcpy(str_, source.str_);                 // Copy the string from source to this object.
    std::cout << "Copy Constructor Called.\n"; // Print message.
}

// Move Constructor.
MyString::MyString(MyString &&source) : str_{source.str_} // (Steal) Initialize str_ with the source's str_ pointer.
{
    source.str_ = nullptr;                     // (Then Null) Set the source's str_ to nullptr to avoid dangling pointer.
    std::cout << "Move Constructor Called.\n"; // Print message.
}

// Destructor.
MyString::~MyString() { std::cout << "Destructor Called.\n"; }

// Copy assignment operator.
MyString &MyString::operator=(const MyString &rhs)
{
    std::cout << "Copy Assignment Operator Called.\n"; // Print message.

    if (this == &rhs) // Check for self-assignment.
    {
        return *this; // If self-assignment, return this object.
    }
    else
    {
        delete[] this->str_;                   // Delete the current string to avoid memory leak.
        str_ = new char[strlen(rhs.str_) + 1]; // Allocate new memory for the string.
        strcpy(str_, rhs.str_);                // Copy the string from rhs to this object.
        return *this;                          // Return the current object.
    }
}

// Move assignment operator.
MyString &MyString::operator=(MyString &&rhs)
{
    std::cout << "Move Assignment Operator Called.\n"; // Print message.

    if (this == &rhs) // Check for self-assignment.
    {
        return *this; // If self-assignment, return this object.
    }
    else
    {
        delete[] this->str_; // Delete the current string to avoid memory leak.
        str_ = rhs.str_;     // Steal the pointer from rhs.
        rhs.str_ = nullptr;  // Nullify the rhs pointer to avoid dangling pointer.
        return *this;        // Return the current object.
    }
}

void MyString::Display() const // Print function.
{
    std::cout << "String: " << str_ << ", Length: " << get_length() << std::endl;
}

// Getters.
int MyString::get_length() const
{
    return strlen(str_); // Return the length of the string.
}

const char *MyString::get_str() const
{
    return str_; // Return the string.
}

int main()
{
    std::cout << "--------------------Testing.operator=(const Type &rhs)---<MOVE>---------------------------------\n";
    MyString a{"Hello"};  // Overloaded/Parameterized constructor.
    a = MyString{"Hola"}; // Overloaded/Parameterized constructor, then move assignment operator, then Destructor.
    a = "Bonjour";        // Overloaded/Parameterized constructor, then move assignment operator, then Destructor.
    a.Display();          // Display the string.

    std::cout << "--------------------Testing.operator=(Type &&rhs)---<COPY>---------------------------------\n";
    MyString s1;                // Default constructor.
    MyString s2("Hello");       // Parameterized constructor.
    MyString s3(s2);            // Copy constructor.
    MyString s4(std::move(s2)); // Move constructor.

    s1 = s3; // Copy assignment operator.

    s1.Display();

    s1 = std::move(s4); // Move assignment operator.
    s1.Display();

    std::cout << "-----------------Testing.opearator+(const Type &rhs)------------------------------------\n";
    // Testing the overloaded operator+ for string concatenation.
    MyString larry{"Larry"};
    MyString moe{"Moe"};
    MyString stooges{"is one of the three stooges."};

    MyString result = larry + stooges; // Using the overloaded operator+ to concatenate strings.
    // MyString result = larry.operator+(stooges); // This is equivalent to the above line.

    result = moe + "is also a stooge"; // Using the overloaded operator+ with a string literal.
    // MyString result = moe.operator+("is also a stooge"); // This is equivalent to the above line.

    // XXX Will NOT WORK, because the operator+ is not defined for string literals.
    result = "Moe + stooges"; // Using the overloaded operator+ with a string literal. 
    // MyString result = "Moe + stooges".operator+(stooges); // This is equivalent to the above line.

    result.Display(); // Display the concatenated string.
    std::cout << "-----------------------------------------------------\n";

    return 0;
}

/// @brief this function overloads the unary minus operator (-) to convert the string to lower case.
/// @details This function creates a new MyString object with the characters of the original string converted to lower case.
/// It allocates memory for the new string, copies the original string into a buffer, converts each character to lower case, and then returns a new MyString object with the lower case string.
/// @note The original string remains unchanged.
/// @param None
/// @return A new MyString object with the lower case string.
MyString MyString::operator-() const // Make Lokwer case
{
    char *buff = new char[strlen(str_) + 1]; // Allocate memory for the new string.
    std::strcpy(buff, str_);                 // Copy the string from this object to buff.
    for (size_t i = 0; i < std::strlen(buff); i++)
    {
        buff[i] = std::tolower(buff[i]); // Convert each character to lower case.
    }
    MyString temp{buff}; // Create a temporary MyString object with the lower case string.
    delete[] buff;       // Free the allocated memory for buff.
    return temp;         // Return the temporary MyString object.
}