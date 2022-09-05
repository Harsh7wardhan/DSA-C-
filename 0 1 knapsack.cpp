
// memoization
int f(int ind, vector<int> &weight, vector<int> &value, int maxWeight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        return 0;
    }

    if (dp[ind][maxWeight] != -1)
    {
        return dp[ind][maxWeight];
    }

    int nottake = 0 + f(ind - 1, weight, value, maxWeight, dp);
    int take = INT_MIN;
    if (weight[ind] <= maxWeight)
    {
        take = value[ind] + f(ind - 1, weight, value, maxWeight - weight[ind], dp);
    }
    return dp[ind][maxWeight] = max(take, nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(n - 1, weight, value, maxWeight, dp);
}

// tabulation
int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base Condition

    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {

            int notTaken = 0 + dp[ind - 1][cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];

            dp[ind][cap] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];
}

// space optimizaation using prev and curr
int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // Base Condition

    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {

            int notTaken = 0 + prev[cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];

            curr[cap] = max(notTaken, taken);
        }
        prev = curr;
    }

    return prev[W];
}

// single array space optimization

int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<int> prev(W + 1, 0);

    // Base Condition

    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = W; cap >= 0; cap--)
        {

            int notTaken = 0 + prev[cap];

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];

            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[W];
}