

/*
=================================================================================
                        Included Libraries
=================================================================================*/
#include <iostream>
#include <array>

/*
=================================================================================
                        Main Function - Entry Point
=================================================================================*/
int main()
{
    std::array<int, 10> nums = {1, 1, 1, 7, 5, 10, 3, 3, 3, 11};
    std::array<int, 12> freq;
    for (int i = 0; i < 12; i++) // initalize freq with 0
    {
        freq[i] = 0;
    }

    for (int i = 0; i < nums.size(); i++) // cal frequency
    {
        freq[nums[i]]++;
    }

    for (int i = 0; i < freq.size(); i++) // printing frequency
    {
        std::cout << "Value = " << i << " , has frequency = " << freq[i] << std::endl;
    }

    int max_count = 0, ans_val = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[nums[i]] > max_count)
        {
            max_count = freq[nums[i]];
            ans_val = nums[i];
        }
    }

    std::cout << ans_val << " Most repeated value with frequency = "
              << max_count << std::endl;

    return 0;
}