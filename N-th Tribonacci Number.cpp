class Solution {
public:
	int tribonacci(int n) {
		int dp[38] = {0, 1, 1, 2};
		for(int i = 4; i <= n; i++){
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		return dp[n];
	}
};