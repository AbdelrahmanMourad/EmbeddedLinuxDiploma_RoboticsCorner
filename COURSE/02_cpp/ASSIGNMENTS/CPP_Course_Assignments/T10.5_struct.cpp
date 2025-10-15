#include <iostream>
#include <array>

struct Fruit  // define 
{
    double price;
    float weight;

    double Caltotalprice()
    {
        return price * weight;
    }
};

int main()
{
    std::array<Fruit, 5> my_fruits;
    Fruit orange; // instance
    Fruit apple;

    orange.price = 15;
    orange.weight = 5;

    std::cout << "total value = " << orange.Caltotalprice()
     << std::endl;

    my_fruits[0] = orange;
    my_fruits[1] = apple;
    
    return 0;
}