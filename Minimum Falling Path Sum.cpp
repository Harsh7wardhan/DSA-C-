// recursion

class Solution
{
public:
    int solve(vector<vector<int>> &mat, int i, int j, int n)
    {
        if (j < 0 || j >= n)
            return 1e9; // Base Case 1: out of bound
        if (i == 0)
            return mat[i][j]; // Base Case 2: end point - 0th row
        int top = mat[i][j] + solve(mat, i - 1, j, n);
        int top_left = mat[i][j] + solve(mat, i - 1, j - 1, n);
        int top_right = mat[i][j] + solve(mat, i - 1, j + 1, n);
        return min(top, min(top_left, top_right));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int min_path_sum = 1e9;
        for (int j = 0; j < n; j++)
        {
            min_path_sum = min(min_path_sum, solve(matrix, n - 1, j, n));
        }
        return min_path_sum;
    }
};

// memoization

class Solution
{
public:
    int solve(vector<vector<int>> &mat, int i, int j, int m, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= m)
            return 1e9; // out of bound
        if (i == 0)
            return mat[i][j]; // end point - 0th row
        if (dp[i][j] != -1)
            return dp[i][j]; // Memoization
        int top = mat[i][j] + solve(mat, i - 1, j, m, dp);
        int top_left = mat[i][j] + solve(mat, i - 1, j - 1, m, dp);
        int top_right = mat[i][j] + solve(mat, i - 1, j + 1, m, dp);
        return dp[i][j] = min(top, min(top_left, top_right));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int min_path_sum = 1e9;
        for (int j = 0; j < m; j++)
        {
            min_path_sum = min(min_path_sum, solve(matrix, n - 1, j, m, dp));
        }
        return min_path_sum;
    }
};

// tabulation

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size(); // rows
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int min_path_sum = 1e9;
        for (int j = 0; j < n; j++) // Base Case : (i == 0) precompute 1st row
            dp[0][j] = mat[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int down = mat[i][j] + dp[i - 1][j];
                int right_diagonal = 1e9, left_diagonal = 1e9;
                // Check for Base condition : out of bounds
                if (j - 1 >= 0)
                    left_diagonal = mat[i][j] + dp[i - 1][j - 1];
                if (j + 1 < n)
                    right_diagonal = mat[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(down, min(left_diagonal, right_diagonal));
            }
        }
        // Our answer will be the minimum of all path sum in last row
        for (int j = 0; j < n; j++)
            min_path_sum = min(min_path_sum, dp[n - 1][j]);
        return min_path_sum;
    }
};

// space optimization

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size(); // rows
        vector<int> prev(m, 0), curr(m, 0);

        int min_path_sum = 1e9;
        for (int j = 0; j < n; j++) // Base Case : (i == 0) precompute 1st row
            prev[j] = mat[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int down = mat[i][j] + prev[j];
                int right_diagonal = 1e9, left_diagonal = 1e9;
                // Check for Base condition : out of bounds
                if (j - 1 >= 0)
                    left_diagonal = mat[i][j] + prev[j - 1];
                if (j + 1 < n)
                    right_diagonal = mat[i][j] + prev[j + 1];
                curr[j] = min(down, min(left_diagonal, right_diagonal));
            }
            prev = curr;
        }
        // Our answer will be the minimum of all path sum in last row
        for (int j = 0; j < n; j++)
            min_path_sum = min(min_path_sum, prev[j]);
        return min_path_sum;
    }
};