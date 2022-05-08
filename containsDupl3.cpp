class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            res.push_back({nums[i],i});
        }
        sort(res.begin(),res.end());
        for(int i = 0; i < res.size(); i++)
        {
            for(int j = i+1; j<res.size(); j++)
            {
                if(abs((long)res[i].first - (long)res[j].first) <= t)
                {
                    if(abs(res[i].second - res[j].second) <= k)
                        return true;
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }
};