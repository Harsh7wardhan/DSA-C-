class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
      if(k<=1)
          return 0;
        
      int prod=1,res=0,i=0,j=0;
       
      for(int j=0;j<nums.size();j++)
      {
          
          prod=prod*nums[j];
          
          while(prod>=k)
          {
              prod=prod/nums[i];
              i++;
          }
          
          res+=j-i+1;
      }
        
        
        return res;
        
    }
};