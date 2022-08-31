// RECURSION
class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &obstacleGrid)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        int up = f(i - 1, j, obstacleGrid);
        int left = f(i, j - 1, obstacleGrid);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return f(m - 1, n - 1, obstacleGrid);
    }
};
// memoization
class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = f(i - 1, j, obstacleGrid, dp);
        int left = f(i, j - 1, obstacleGrid, dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};

// tabulation
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return helper(obstacleGrid, m - 1, n - 1, dp);
    }
    int helper(vector<vector<int>> &obstacleGrid, int m, int n, vector<vector<int>> &dp)
    {
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = 0, lh = 0;
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        lh = dp[i][j - 1];
                    }
                    dp[i][j] = up + lh;
                }
            }
        }

        return dp[m][n];
    }
};