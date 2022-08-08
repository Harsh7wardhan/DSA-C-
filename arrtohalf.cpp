class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto x : arr){
            m[x]++;
        }
        multimap<int,int,greater<int>> mm;
        for(auto it : m){
            mm.insert({it.second,it.first});
        }
        
        int n = arr.size();
        int sum = n;
        int cnt = 0;
        
        for(auto x : mm){
           sum-=x.first;
           cnt++;
           if(sum<=n/2){
               return cnt;
           } 
            
        }
        
        return cnt;
        
    }
};