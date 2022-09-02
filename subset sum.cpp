// aditya verma
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (j == 0)
                {
                    t[i][j] = true;
                }
                else if (i == 0)
                {
                    t[i][j] = false;
                }
                else if (j >= arr[i - 1])
                {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
};

// memoization striver
class Solution
{
public:
    bool f(int i, vector<int> arr, int sum, vector<vector<int>> &dp)
    {

        // base cases
        if (sum == 0)
            return true;
        if (i == 0)
            return arr[0] == sum;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool nottake = f(i - 1, arr, sum, dp);
        bool take = false;
        if (sum >= arr[i])
            take = f(i - 1, arr, sum - arr[i], dp);

        return dp[i][sum] = take || nottake;
    }

    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, arr, sum, dp);
    }
};

// tabulation
class Solution
{
public:
    bool isSubsetSum(vector<int> a, int sum)
    {
        int n = a.size();
        bool dp[n + 1][sum + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 or j == 0)
                {
                    if (i == 0)
                        dp[i][j] = false;
                    if (j == 0)
                        dp[i][j] = true;
                }
                else if (a[i - 1] <= j)
                {

                    dp[i][j] = (dp[i - 1][j] or dp[i - 1][j - a[i - 1]]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

// striver

#include <bits/stdc++.h>

using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with given target found";
    else
        cout << "Subset with given target not found";
}