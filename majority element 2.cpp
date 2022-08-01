class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        int t = n/3;
        for(auto it : nums){
            mp[it]++;
        }
        
        vector<int> v;
        for(auto x : mp){
            if(x.second>t){
                v.push_back(x.first);
            }
        }
        
        return v;
        
    }
};