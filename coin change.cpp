// MEMOIZATION
class Solution
{
public:
    int helper(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int notpick = 0 + helper(ind - 1, coins, amount, dp);
        int pick = INT_MAX;
        if (coins[ind] <= amount)
            pick = 1 + helper(ind, coins, amount - coins[ind], dp);

        return dp[ind][amount] = min(pick, notpick);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, coins, amount, dp);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// TABULATION
#include <bits/stdc++.h>

using namespace std;

int minimumElements(vector<int> &arr, int T)
{

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(T + 1, 0));

    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {

            int notTake = 0 + dp[ind - 1][target];
            int take = 1e9;
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];

            dp[ind][target] = min(notTake, take);
        }
    }

    int ans = dp[n - 1][T];
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3};
    int T = 7;

    cout << "The minimum number of coins required to form the target sum is "
         << minimumElements(arr, T);
}