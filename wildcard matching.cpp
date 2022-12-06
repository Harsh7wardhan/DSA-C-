class Solution
{
public:
    int f(int j, int i, string s, string p)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (p[i] == s[j] || p[i] == '?')
        {
            return f(j - 1, i - 1, s, p);
        }

        if (p[i] == '*')
        {
            return f(j, i - 1, s, p) | f(j - 1, i, s, p);
        }

        return false;
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        return f(n - 1, m - 1, s, p);
    }
};

// memoization
class Solution
{
public:
    int f(int j, int i, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[j][i] != -1)
            return dp[j][i];
        if (p[i] == s[j] || p[i] == '?')
        {
            return dp[j][i] = f(j - 1, i - 1, s, p, dp);
        }

        if (p[i] == '*')
        {
            return dp[j][i] = f(j, i - 1, s, p, dp) || f(j - 1, i, s, p, dp);
        }

        return dp[j][i] = false;
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, s, p, dp);
    }
};

// strriverrr

#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp)
{

    // Base Conditions
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

    else
    {
        if (S1[i] == '*')
            return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}

bool wildcardMatching(string &S1, string &S2)
{

    int n = S1.size();
    int m = S2.size();

    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}

int main()
{

    string S1 = "ab*cd";
    string S2 = "abdefcd";

    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";
}