// https://leetcode.com/problems/count-elements-with-maximum-frequency/

#include<array>
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        array<int, 105> freq;
        for(int i = 0; i < freq.size(); i++)
        {
            freq[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        int max_count = 0;
        for(int i = 0; i < freq.size(); i++)
        {
            if(freq[i] > max_count)
            {
                max_count = freq[i];
            }
        }
        int nums_max = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(freq[nums[i]] == max_count)
            {
                nums_max++;
            }
        }
        return nums_max;
    }
};