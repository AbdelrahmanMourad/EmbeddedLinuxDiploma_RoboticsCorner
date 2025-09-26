#include <iostream>
#include <vector>
#include <array>

int main()
{
    // endless loop
    // 1, 2, 3

    int N_ELEMENTS = 8; // elements

    int *array_c = {new int[N_ELEMENTS * sizeof(int)]};

    for (auto i = 0; i < N_ELEMENTS; i++)
    {
        array_c[i] = i + 20;
        std::cout << array_c[i] << " ";
    }
    std::cout << std::endl;

    delete[] array_c;
    /**************************************************************************/
    std::array<int, 5> arr_cpp{1, 2, 3, 4, 5};

    std::vector<int> vec{1, 2, 3};

    // for (auto &x : vec)
    //     std::cout << x << " ";

    // std::cout << std::endl;
    // for (auto &x : vec)
    //     x *= 2;

    // for (auto &x : vec)
    //     std::cout << x << " ";

    return 0;
}