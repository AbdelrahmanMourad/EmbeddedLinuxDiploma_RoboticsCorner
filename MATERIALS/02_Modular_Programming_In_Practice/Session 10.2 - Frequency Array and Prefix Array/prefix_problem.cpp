// http://leetcode.com/problems/find-pivot-index/submissions/1595919781/?envType=problem-list-v2&envId=prefix-sum

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            array<int, 10000> pref;
            for(int i = 0; i < nums.size(); i++)
            {
                if(i == 0)
                {
                    pref[i] = nums[i];
                }
                else
                {
                    pref[i] = nums[i] + pref[i - 1];
                }
            }
            int ans = -1;
    
            for(int i = 0; i < nums.size(); i++)
            {
                int st1 = 0, end1 = i - 1;
                int st2 = i + 1, end2 = nums.size() - 1;
                int sumleft = 0, sumright = 0;
                if(i != 0)
                {
                    sumleft = pref[end1];
                }
    
                if(i != nums.size() - 1)
                {
                    sumright = pref[end2] - pref[st2 - 1];
                    // if(i != 0)
                    // {
                    //     sumright -= pref[st2 - 1];
                    // }
                }
    
                if(sumleft == sumright)
                {
                    ans = i;
                }
    
            }
    
            return ans;
        }
    };