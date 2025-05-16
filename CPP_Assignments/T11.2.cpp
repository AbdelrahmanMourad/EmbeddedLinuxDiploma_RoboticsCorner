
/*  =======================================================================================================
    Task(11.2):
    ===========

    1.  Abstract Class: LibraryItem
        ○   This is the base class representing a generic library item. It defines the following pure virtual methods,
        ○   which must be implemented by derived classes:
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
        ○   Implements the same set of abstract methods as the Book class, tailored to magazine○specific attributes.
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

/*  •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
                        Functions Prototype
    ••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••• */
    


/*  •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
                        Entry Point
    ••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••• */
int main()
{

    return 0;
}

/*  ○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○
                        Functions implementation
    ○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○○ */










