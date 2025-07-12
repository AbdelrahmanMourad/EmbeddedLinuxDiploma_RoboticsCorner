
/*========================================================================================================
    Task(13.1):  Page object class:
    ===============================

    - Requirements:
        In this task, you will work with a base class PageObject and two derived classes: Page and Copy.
        The goal is to create a basic structure for handling page-related objects and their
        operations, specifically for adding, removing, and deleting items from both Page and Copy objects.

    - Key Points:
        ○   Base Class (PageObject):
            This class has three virtual methods: addItem(), removeItem(), and deleteItem(),
            which provide a common interface for derived classes.
            It does not have any pure virtual methods, so it is not an abstract class, and
            you can instantiate it directly.
        ○   Derived Classes (Page and Copy):
            •   Page: This class overrides the addItem(), removeItem(), and deleteItem() methods
                to handle actions related to individual pages. Since Page provides concrete
                implementations of these methods, it is not an abstract class, meaning you can
                instantiate Page objects.
            •   Copy: This class manages a collection of PageObject items in a vector. It also
                implements the same virtual methods, allowing for operations related to multiple
                pages (or other PageObject items) in a copied context.
        ○   Task Goal (main):
            •   Create instances of Page, PageObject, and use the addItem() function to add a
                PageObject to a page.
            •   Use the provided methods in both classes to manipulate PageObject items and
                print relevant messages to the console when adding, removing, or deleting items.
        ○   Class diagram:
            use a UML tool (such as UMLet or draw.io) to create a class diagram for
            this structure. The class diagram should visually represent the inheritance hierarchy
            between the PageObject, Page, and Copy classes, including their methods.

    - Link to make the diagram: https://app.diagrams.net/
===========================================================================================================*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>

/*  -------------------------------------------------------------------
                        Declarations / Functions Prototype
    ------------------------------------------------------------------- */
// Base Class
class PageObject
{
public:
    virtual void addItem() { std::cout << "PageObject::addItem()\n"; }
    virtual void removeItem() { std::cout << "PageObject::removeItem()\n"; }
    virtual void deleteItem() { std::cout << "PageObject::deleteItem()"; }
    PageObject() { std::cout << "Constructor Called: PageObject.\n"; }
    ~PageObject() { std::cout << "Destructor Called: PageObject.\n"; }
};
// Derived Classed
class Page : public PageObject
{
public:
    void addItem() override { std::cout << "Page::addItem() - Item added to Page.\n"; }
    void removeItem() override { std::cout << "Page::removeItem() - Item removed from Page.\n"; }
    void deleteItem() override { std::cout << "Page::deleteItem() - Item deleted from Page.\n"; }
    Page() { std::cout << "Constructor Called: Page.\n"; }
    ~Page() { std::cout << "Destructor Called: Page.\n"; }
};
// Derived Class: Copy (manages multiple PageObjects)
class Copy : public PageObject
{
private:
    std::vector<PageObject *> v1; // Store pointers for polymorphic behavior

public:
    void addItem() override;
    void removeItem() override;
    void deleteItem() override;
    // For demonstration: show how many items are in the copy
    void printCount() const { std::cout << "Copy contains " << v1.size() << " PageObject(s).\n"; }
    Copy() { std::cout << "Constructor Called: Copy.\n"; }
    ~Copy()
    {
        std::cout << "Destructor Called: Copy.\n";
        // Clean up all PageObject pointers
        for (auto ptr : v1)
            delete ptr;

        v1.clear(); // *** Erase all the vectors elements ***
    }
};

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    std::cout << "\n--- Creating PageObject and Page ---\n";
    PageObject baseObj;
    baseObj.addItem();
    baseObj.removeItem();
    baseObj.deleteItem();

    std::cout << "\n--- Creating Page ---\n";
    Page pageObj;
    pageObj.addItem();
    pageObj.removeItem();
    pageObj.deleteItem();

    std::cout << "\n--- Creating Copy and manipulating PageObjects ---\n";
    Copy copyObj;
    copyObj.addItem();
    copyObj.addItem();
    copyObj.printCount();
    copyObj.removeItem();
    copyObj.printCount();
    copyObj.deleteItem();
    copyObj.printCount();

    std::cout << "\n--- Demonstrating polymorphism ---\n";
    PageObject *polyPtr = new Page();
    polyPtr->addItem();
    polyPtr->removeItem();
    polyPtr->deleteItem();
    delete polyPtr;

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
// class signal_list_t /*40k*/
// {
//     int y = 1;
// };

// class Example
// {
// private:
//     const int x_;
//     signal_list_t &&ref_x;

// public:
//     // Example() : x_{10}, ref_x{signal_list_t ref_x2}{}
//     // Example() {}
//     Example(int x, signal_list_t &&ref) : x_{x}, ref_x{ref}{}
//     void print(void) { std::cout << "x_ = " << x_ << std::endl; }
// };

// int main()
// {
//     // signal_list_t s1;
//     Example example1(5, signal_list_t s1);
//     example1.print();

//     return 0;
// }

/*========================================================================================================
    Task(13.1):  Page object class - Solution & Methodology Summary
==========================================================================================================
| Methodology & Design:
| - We use a base class (PageObject) with virtual methods for add, remove, and delete operations.
| - Page is a derived class representing a single page, overriding the methods to provide specific messages.
| - Copy is a derived class that manages a collection (vector) of PageObject items, simulating a "copy" of pages.
| - Demonstrates inheritance, method overriding, and composition (Copy "has a" vector of PageObject).
| - In main(), we create and manipulate Page, PageObject, and Copy objects, showing polymorphic behavior.
| - This structure is extensible for more complex document/page management systems.
========================================================================================================*/
/*========================================================================================================
| Summary:
| - Demonstrates inheritance, method overriding, and composition.
| - Shows how to manage collections of polymorphic objects (with pointers).
| - Illustrates safe cleanup and polymorphic destruction.
| - Use this structure as a foundation for more advanced document/page systems.
========================================================================================================*/