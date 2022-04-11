class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        int point = 1 ;
        sort(nums.begin(),nums.end(),greater<int>());
        int pre = nums[0];
        
        if(nums.size()==1 || nums.size()==2)
        {
            return nums[0];
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=pre)
            {
                point++;
                pre=nums[i];
            }
            if(point==3)
                return pre;
        }
        return nums[0];
        
    }
};