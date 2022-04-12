
***********************METHOD-1***********************************
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        int i = -1, j = 0;
        while(j < n )
        {
            if(nums[j] != 0)
            {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
};
*************************METHOD-2***********************************
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();
        int i = -1, j = 0;
        while(j < n )
        {
            if(nums[j] != 0)
            {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
    }
};