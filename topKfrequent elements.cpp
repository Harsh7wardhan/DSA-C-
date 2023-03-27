class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> min_heap ;
        
        for(auto &i : mp){
            min_heap.push({i.second , i.first});
            if(min_heap.size() > k)
                min_heap.pop();
        }
        
        vector<int> res;
        
        while(k--){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
        
    }
};