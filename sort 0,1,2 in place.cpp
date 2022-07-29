class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
         for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
         for(int i=0;i<nums.size();i++){
            if(nums[i]==2)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

//2nd approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // initialize variables:
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // logic:
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums[mid], nums[high--]); break;
            }
        }
    };
};