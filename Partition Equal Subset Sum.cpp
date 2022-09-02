// MEMOIZATION
class Solution
{
public:
    bool f(int i, int target, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (target == 0)
            return true;
        if (i == 0)
            return nums[0] == target;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool nottake = f(i - 1, target, nums, dp);
        bool take = false;
        if (target >= nums[i])
            take = f(i - 1, target - nums[i], nums, dp);

        return dp[i][target] = nottake || take;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2)
            return false;
        else
        {
            int k = sum / 2;
            vector<vector<int>> dp(n, vector<int>(k + 1, -1));
            return f(n - 1, k, nums, dp);
        }
    }
};

// tabulation
#include <bits/stdc++.h>
using namespace std;

bool canPartition(int n, vector<int> &arr)
{

    int totSum = 0;

    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }

    if (totSum % 2 == 1)
        return false;

    else
    {
        int k = totSum / 2;
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
}

int main()
{

    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";
}