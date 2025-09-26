
/*  =======================================================================================================
    Task(11.2):
    ===========

    1.  Abstract Class: LibraryItem
        ○   This is the base class representing a generic library item. It defines the following
            pure virtual methods, which must be implemented by derived classes:
            •   displayInfo(): Outputs details about the library item.
            •   isAvailable(): Returns a boolean indicating whether the item is available for borrowing.
            •   borrowItem(): Handles the logic for borrowing the item.
            •   returnItem(): Handles the logic for returning the item.
        ○   A virtual destructor is provided to ensure proper cleanup of derived classes when they are deleted.

    2.  Derived Class: Book
        ○   Inherits from LibraryItem and represents a book in the library.
        ○   Private members include:
            •   title: The title of the book.
            •   author: The author of the book.
            •   available: A boolean flag indicating if the book is available for borrowing.
        ○   Implements the abstract methods:
            •   displayInfo(): Prints the book's title, author, and availability status.
            •   isAvailable(): Returns the availability status.
            •   borrowItem(): Marks the book as borrowed if it is available; otherwise, it prints an error message.
            •   returnItem(): Marks the book as available again and prints a confirmation message.
    3.  Derived Class: Magazine
        ○   Similar to Book, it inherits from LibraryItem and represents a magazine in the library.
        ○   Private members include:
            •   title: The title of the magazine.
            •   issueNumber: The issue number of the magazine.
            •   available: A boolean flag indicating if the magazine is available for borrowing.
        ○   Implements the same set of abstract methods as the Book class, tailored to magazine
            specific attributes.
    4.  Main Function
        ○   The main() function initializes the system:
            •   A vector of pointers to LibraryItem objects is created to store different library items.
            •   Instances of Book and Magazine are created and added to the vector.
            •   Information about each item is displayed using the displayInfo() method.
            •   The program demonstrates borrowing and returning functionality:
        ○   A user can borrow available items, and if an item is already borrowed, the system provides an appropriate message.
        ○   Items can be returned, updating their availability status.
        ○   Finally, the dynamically allocated memory for the library items is cleaned up to prevent memory leaks

    ======================================================================================================
*/

/*  •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
                    Included Libraries.
    ••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••• */
#include <iostream>
#include <vector>
#include <memory>

/*  •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
                        Functions Prototype
    ••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••• */
// Base Abstract Class.
class LibraryItem
{
public:
    virtual void displayInfo(void) const = 0;
    virtual bool isAvailable(void) const = 0;
    virtual void borrowItem(void) = 0;
    virtual void returnItem(void) = 0;
    LibraryItem() { std::cout << "Constructor Called: LibraryItem\n"; }
    virtual ~LibraryItem() { std::cout << "Destructor Called: LibraryItem\n"; }
};
// Derived Classes.
class Book : public LibraryItem
{
private:
    std::string title_;
    std::string author_;
    bool available_;

public:
    Book(std::string inputTitle, std::string inputAuthor) : title_{inputTitle}, author_{inputAuthor}, available_{true} { std::cout << "Constructor Called: Book.\n"; }
    ~Book() { std::cout << "Destructor Called: Book"; }
    void displayInfo(void) const override { std::cout << "Boot - Title: " << title_ << " ,Author: " << author_ << " ,Availability: " << (available_ ? "Yes" : "No") << std::endl; }
    bool isAvailable(void) const override { return this->available_; }
    void borrowItem(void) override; // Prototype
    void returnItem(void) override; // Prototype
};
class Magazine : public LibraryItem
{
private:
    std::string title_;
    int issue_number_;
    bool available_;

public:
    Magazine(std::string inputTitle, int inputIssueNumber) : title_{inputTitle}, issue_number_{inputIssueNumber}, available_{true} { std::cout << "Constructor Called: Magazine.\n"; }
    ~Magazine() { std::cout << "Destructor Called: Magazine"; }
    void displayInfo(void) const override { std::cout << "Magazine - Title: " << title_ << " ,Issue Nnumber: " << issue_number_ << " ,Availability:" << (available_ ? "Yes" : "No") << std::endl; }
    bool isAvailable(void) const override { return this->available_; }
    void borrowItem(void) override; // Prototype
    void returnItem(void) override; // Prototype
};

/*  •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
                        Entry Point
    ••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••• */
int main()
{
    // // Create vector of Pointers to items representing the library.
    // std::vector<LibraryItem *> library;

    // // Create instances of Book, Magazine
    // library.push_back(new Book("The Pragmatic Programmer", "Andrew Hunt"));
    // library.push_back(new Magazine("National Geographic", 202));

    // // Display items
    // for (const auto &item : library)
    // {
    //     item->displayInfo();
    // }
    // std::cout << std::endl;

    // // Borrow items
    // for (auto &item : library)
    // {
    //     item->borrowItem();
    // }
    // std::cout << std::endl;

    // // Try borrowing again
    // for (auto &item : library)
    // {
    //     item->borrowItem();
    // }

    // std::cout << std::endl;

    // // Return items
    // for (auto &item : library)
    // {
    //     item->returnItem();
    // }

    // // Clean up
    // for (auto &item : library)
    // {
    //     delete item;
    // }

    // ___________________Try with smart pointers___________________
    // Create vector of Unique Pointers to items representing the library.
    std::vector<std::unique_ptr<LibraryItem>> library;

    // // Create instances of Book, Magazine.
    library.push_back(std::make_unique<Book>("The Pragmatic Programmer", "Andrew Hunt"));
    library.push_back(std::make_unique<Magazine>("National Geographic", 202));

    for (const auto &item : library)
        item->displayInfo();
    std::cout << std::endl;

    for (const auto &item : library)
        item->borrowItem();
    std::cout << std::endl;

    for (const auto &item : library)
        item->borrowItem(); // Trying to borrow again
    std::cout << std::endl;

    for (const auto &item : library)
        item->returnItem();
    std::cout << std::endl;

    // No manual deletion needed!
    return 0;
}

/*  ○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○
                        Functions implementation
    ○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○ */
void Book::borrowItem(void)
{
    if (this->available_)
    {
        available_ = false;
        std::cout << "You've borrowed the Book: \"" << title_ << "\" ,(Autohr: " << author_ << ")" << std::endl;
    }
    else
    {
        std::cout << "Sorry, the Book \"" << title_ << "\" ,(Author: " << author_ << ") is already borrowed." << std::endl;
    }
}
void Book::returnItem(void)
{
    this->available_ = true;
    std::cout << "Book \"" << title_ << "\" ,(Author: " << author_ << ") has been returned." << std::endl;
}

void Magazine::borrowItem(void)
{
    if (this->available_)
    {
        available_ = false;
        std::cout << "You've borrowed the Magazine: \"" << title_ << "\" ,(issue: " << issue_number_ << ")" << std::endl;
    }
    else
    {
        std::cout << "Sorry, the magazine \"" << title_ << "\" ,(Issue: " << issue_number_ << ") is already borrowed." << std::endl;
    }
}
void Magazine::returnItem(void)
{
    this->available_ = true;
    std::cout << "Magazine \"" << title_ << "\" ,(Issue: " << issue_number_ << ") has been returned." << std::endl;
}
