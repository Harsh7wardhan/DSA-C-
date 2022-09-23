class Solution
{
public:
    void helper(vector<int> &nums, int freq[], vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                helper(nums, freq, ans, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for (int i = 0; i < n; i++)
            freq[i] = 0;
        helper(nums, freq, ans, ds);
        return ans;
    }
};

// 2
class Solution
{
public:
    vector<vector<int>> result;

    // Backtracking
    void permutation(vector<int> &nums, int i, int n)
    {
        if (i == n)
        {
            result.push_back(nums);
            return;
        }

        for (int j = i; j <= n; j++)
        {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        permutation(nums, 0, nums.size() - 1);

        return result;
    }
};