class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ma = prices[n-1];
        int mi = prices[0];
        vector<int> dp(n,0);

        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1],ma-prices[i]);
        }
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],dp[i]+(prices[i]-mi));
        }

        return dp[n-1];
    }
};