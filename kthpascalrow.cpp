vector<int> Solution::getRow(int k) {
    vector<int>ans;
    ans.push_back(1);
    if(k==0)
    {
        return ans;
    }

    for(int i=1;i<k;i++)
    {
        int val=(ans[i-1]*(k+1-i))/i;
        ans.push_back(val);
    }
    ans.push_back(1);


    return ans;
};