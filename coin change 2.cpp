// MEMOIZATION

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, -1));
        return f(coins, n - 1, amount, dp);
    }

    int f(vector<int> &coins, int ind, int amount, vector<vector<long>> &dp)
    {
        if (ind == 0)
        {
            return (amount % coins[0] == 0);
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        long notTaken = f(coins, ind - 1, amount, dp);

        long taken = 0;
        if (coins[ind] <= amount)
            taken = f(coins, ind, amount - coins[ind], dp);

        return dp[ind][amount] = notTaken + taken;
    }
};

// TABULATION
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long>> dp(n, vector<long>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
            // Else condition is automatically fulfilled,
            // as dp array is initialized to zero
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                long notTaken = dp[ind - 1][target];

                long taken = 0;
                if (coins[ind] <= target)
                    taken = dp[ind][target - coins[ind]];

                dp[ind][target] = notTaken + taken;
            }
        }

        return dp[n - 1][amount];
    }
};