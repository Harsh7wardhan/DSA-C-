class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        unordered_map<char, int>::iterator it;
        priority_queue<pair<int, char>> pq;
        string ans = "";
        
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
        }
        
        for (it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
        }
        
        while(pq.size() > 0) {
            int freq = pq.top().first;
            char elem = pq.top().second;
            
            for (int i = 1; i <= freq; i++) ans.push_back(elem);
            pq.pop();
        }
        
        return ans;
    }
};