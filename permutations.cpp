class Solution {
private:
    void solve(vector<vector<int>> &ans,vector<int> nums,int index)
    {
        //base case
        if(index>=nums.size())
        {
            ans.push_back(output);
        }
        
        
        for(int j=index;j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            solve(ans,output,nums,index+1);
            //backtrack
            swap(nums[index],nums[j]);
            
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(ans,nums,index);
        return ans;
    }
};