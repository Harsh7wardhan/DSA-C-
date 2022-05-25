class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int sum = 0;
        for(auto x : nums)
        {
            mp[x]++;
        }
        
        for(auto x : mp)
        {
            if(x.second==1)
            {
                sum+=x.first;
            }
        }
        
        return sum;
    }
};