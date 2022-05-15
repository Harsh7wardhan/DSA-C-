class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j] && (i*j)%k==0)
                {
                    ans.push_back({i,j});
                }
            }
        }
        int res = ans.size();
        return res;
    }
};