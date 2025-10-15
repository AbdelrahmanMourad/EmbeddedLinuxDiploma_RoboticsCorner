#include<iostream>
#include<array>

int main()
{
    std::array<int, 5> days_expans = {12, -5, 15, 30, 5};
    std::array<int, 5> prefix;
    for(int i = 0; i < 5; i++)
    {
        if(i == 0)
        {
            prefix[i] = days_expans[i];
        }
        else
        {
            prefix[i] = days_expans[i] + prefix[i - 1];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        std::cout << prefix[i] << " "; 
    }
    std::cout << std::endl;

    int start = 2, end = 5;  // days

    start--;
    end--;

    std::cout << prefix[end] - prefix[start - 1] << std::endl;

    return 0;
}