#include <iostream>
#include <array>
#include <algorithm>

/*
    Muti-dimensional Arrays. {Used in AI & Robotics}. {Not preferred in Cpp}.
        dataType name_of_array[size1][size2]...[size_n];
        int arr[3][3];  // 3-D array.
*/
int main()
{
    // Create cpp-style array
    std::array<char, 6> word; // allocate in Stack. {garbage}

    // 2D array.
    int matrix_c [2][2];
    std::array<std::array<int, 4>, 3> matrix_cpp ;

    

    return 0;
}
