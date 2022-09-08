// MEMOIZATION
class Solution
{
public:
    int cutRodUtil(int ind, int price[], int n, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return n * price[0];
        }

        if (dp[ind][n] != -1)
            return dp[ind][n];

        int notTaken = 0 + cutRodUtil(ind - 1, price, n, dp);

        int taken = INT_MIN;
        int rodLength = ind + 1;
        if (rodLength <= n)
            taken = price[ind] + cutRodUtil(ind, price, n - rodLength, dp);

        return dp[ind][n] = max(notTaken, taken);
    }
    int cutRod(int price[], int n)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return cutRodUtil(n - 1, price, n, dp);
    }
};

// TABULATION
#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &price, int N)
{

    vector<vector<int>> dp(N, vector<int>(N + 1, -1));

    for (int i = 0; i <= N; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int ind = 1; ind < N; ind++)
    {
        for (int length = 0; length <= N; length++)
        {

            int notTaken = 0 + dp[ind - 1][length];

            int taken = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= length)
                taken = price[ind] + dp[ind][length - rodLength];

            dp[ind][length] = max(notTaken, taken);
        }
    }

    return dp[N - 1][N];
}

int main()
{

    vector<int> price = {2, 5, 7, 8, 10};

    int n = price.size();

    cout << "The Maximum price generated is " << cutRod(price, n);
}