class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int minvalue=INT_MAX;
        int profit=0;

        for(int i=0;i<n;i++)
        {
            minvalue=min(minvalue,prices[i]);
            profit=max(profit,prices[i]-minvalue);
        }
        return profit;
    }
};