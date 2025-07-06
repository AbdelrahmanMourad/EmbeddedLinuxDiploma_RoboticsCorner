
/*________________________________________________________________________________________________________

    Task(10.1): Inventory management:
    ---------------------------------

    In this task, you will implement a simple inventory management system using C++
    structs, vectors, and lambda functions. The system keeps track of items in an
    inventory, including their name, price, and quantity. The focus of this task is
    on using lambda expressions to update the inventory and perform calculations dynamically.

    Key Features to Implement:
        1.  Struct Definition for Items:
            ○   Define a struct called Item to represent an item in the inventory.
                The Item should have the following attributes:
                •   name (std::string): The name of the item.
                •   price (float): The price of the item.
                •   quantity (int): The quantity of the item available in stock.
        2.  Create an Inventory:
            ○   Create a std::vector to store multiple Item objects, representing the
                inventory of a store.
                Initialize it with a few sample items such as "Laptop","Smartphone",
                and "Tablet", each with a specific price and quantity.
        3.  Lambda Functions:
            ○   Update Item Price: Write a lambda function updatePrice that captures the
                inventory by reference (&inventory). It takes an item's name and a new
                price as input, and updates the price of the specified item.
            ○   Check Stock Availability: Create a lambda function isOutOfStock that
                captures the inventory by value. This function takes an item's name as
                input and returns a boolean indicating whether the item is out of stock
                (i.e., quantity = 0).
            ○   Calculate Total Inventory Value: Implement a lambda calculateTotalValue
                that captures the inventory by reference. This function computes and
                returns the total value of the inventory, which is the sum of all items'
                prices multiplied by their quantities.
        4.  Main Program:
            ○   Demonstrate the use of these lambdas by:
                •   Updating the price of an item (e.g., "Smartphone").
                •   Checking if an item (e.g., "Laptop") is out of stock.
                •   Calculating the total value of the inventory
___________________________________________________________________________________________________________*/

/*  -------------------------------------------------------------------
                    Included Libraries.
    ------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <functional>

/*  -------------------------------------------------------------------
                        Declarations / Functions Prototype
    ------------------------------------------------------------------- */
struct Item
{
    std::string Name;
    float Price;
    int Quantity;
};

/*  -------------------------------------------------------------------
                        Entry Point - Main Function
    ------------------------------------------------------------------- */
int main()
{
    // 1. Create an Inventory
    // std::vector<Item> inventory;
    // inventory.push_back({"Laptop", 700, 5});
    // inventory.push_back({"SmartPhone", 900, 12});
    // inventory.push_back({"Teblet", 400, 8});

    std::vector<Item> inventory = {
        {"Laptop", 1200.0f, 5},
        {"Smartphone", 699.0f, 0},
        {"Tablet", 450.0f, 12}};

    // 2. Lambda to Update Price
    std::function<void(std::string, float)> updatePrice = [&inventory](const std::string &&itemName, const float &&newPrice) -> void
    {
        for (auto &item : inventory)
        {
            if (item.Name == itemName)
            {
                item.Price = newPrice;
                std::cout << "Updated price of " << itemName << " to $" << newPrice << "\n";
                return;
            }
        }
        std::cout << "Item \"" << itemName << "\" not found in inventory.\n";
    };

    // 3. Lambda to Check if Item is Out of Stock (capture by value)
    std::function<bool(std::string)> isOutOfStock = [inventory](const std::string &&name) mutable -> bool
    {
        /*Check if the quantity==0 or not*/
        for (auto &item : inventory)
        {
            if (item.Name == name)
                return false; // is is stock.
        }
        return true; // is out of stock
    };

    // 4. Lambda to Calculate Total Inventory Value
    std::function<float(void)> calculateTotalValue = [&inventory](void) -> float
    {
        float total = 0;                           // Temp container.
        for (auto item : inventory)                // Loop
            total += (item.Price * item.Quantity); // Calc
        return total;                              // Return
    };

    // === Demonstration ===
    updatePrice("Smartphone", 749.99f);

    std::string testItem = "Laptop";
    std::cout << testItem << (isOutOfStock(testItem) ? " is out of stock.\n" : " is in stock.\n");

    std::cout << "Total Inventory Value: $ " << calculateTotalValue() << "\n";

    return 0;
}

/*  -------------------------------------------------------------------
                        Functions implementation
    ------------------------------------------------------------------- */
