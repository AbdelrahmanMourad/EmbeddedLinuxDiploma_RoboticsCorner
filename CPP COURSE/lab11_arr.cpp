#include <iostream>
#include <array>

// Call By Value.
// void processing(std::array<int, 5> list)
// {
//     for (int element : list)
//     {
//         element *=2;
//     }
// }

// Call By Address.
void processing(std::array<int, 5> &list)
{
    for (int &element : list)
    {
        element *= 2;
    }
}

void AutomaticArray(const int size)
{   
    // Automatic array gets allocated and deallocated automatically.
    int num[size] = {1, 2, 3, 4, 5};
}

int main()
{
    std::array<int, 5> list_num{100, 200, 300, 400, 500};

    for (int element : list_num)
    {
        std::cout << "Number =  " << element << "\n";
    }

    processing(list_num);
    std::cout << "----------\n";

    for (int element : list_num)
    {
        std::cout << "Number =  " << element << "\n";
    }

    return 0;
}