
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

class Inventory
{
private:
    std::vector<Item> Inventory_vec;

public:
    Inventory() = default;
    // Inventory(Inventory &inventory) = delete;
    // Inventory(Inventory &&inventory) = delete;
    ~Inventory() = default;

    void add_Item(Item &item) { Inventory_vec.push_back(item); }
    void add_Item(Item &&item) { Inventory_vec.push_back(item); }
    void update_price(std::string name, float price) { for (auto &item : Inventory_vec) { if (item.Name == name) { item.Price = price; } } }
    float Calculate_total_value(void)
    {
        float total{0};
        for (auto &item : Inventory_vec) { total += (item.Price * item.Quantity); }
        return total;
    }
    bool isOutOfStock (std::string name)
    {
        for(auto &item : Inventory_vec)
        {
            if(item.Name == name) // if exist.
                return false;     // in stock.
        }
        return true; // out of stock.
    }
    void Display(void){
        std::cout<<"\n--------------\nInventory Report:\n--------------\n";
        for(auto i = 0; i <Inventory_vec.size(); i++)
        {
            std::cout<< "Item="<<Inventory_vec[i].Name<<
                    "\t,Price="<<Inventory_vec[i].Price<<
                   "\t,Stock= "<<Inventory_vec[i].Quantity<<
                    std::endl;
        }
    }
};

/*  -------------------------------------------------------------------
                        Entry Point
    ------------------------------------------------------------------- */
int main()
{
    // 1. Create an Inventory
    Inventory inventory;
    inventory.add_Item({"Laptop", 700, 5});
    inventory.add_Item({"SmartPhone", 900, 12});
    inventory.add_Item({"Teblet", 400, 8});

    // 2. Lambda to Update Price
    std::function<void(std::string, float)> updatePrice = [&inventory](std::string name, float new_price) -> void
    { inventory.update_price(name, new_price); };

    // 3. Lambda to Check if Item is Out of Stock (capture by value)
    std::function<bool(std::string)> isOutOfStock = [inventory](std::string name) mutable -> bool { return inventory.isOutOfStock(name); };

    // 4. Lambda to Calculate Total Inventory Value
    std::function<float(void)> calculateTotalValue = [&inventory](void) -> float
    { return inventory.Calculate_total_value(); };

    // === Demonstration === Main Program: ===
    // • Updating the price of an item (e.g., "Smartphone").
    updatePrice("Smartphone", 1100);

    // • Checking if an item (e.g., "Laptop") is out of stock.
    if (isOutOfStock("Laptop"))
        std::cout << "Laptop is out of stock\n";
    else
        std::cout << "Laptop is in stock\n";

    // • Calculating the total value of the inventory
    std::cout << "Total Value of Inventory= " << calculateTotalValue() << std::endl;

    inventory.Display();

    return 0;
}
