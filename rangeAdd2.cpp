class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) 
    {
        for(const vector<int> &a : ops)
        {
            m=min(m,a[0]);
            n=min(n,a[1]);
        }
        return m*n;
    }
};