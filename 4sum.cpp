class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            // vector<int> v;
            for (int j = i + 1; j < n - 2; j++)
            {
                int l = j + 1, h = n - 1;

                while (l < h)
                {
                    long long int ss = (long long)target - nums[i] - nums[j];
                    long long temp = nums[l] + nums[h];
                    if (ss == temp)
                    {
                        vector<int> temp;
                        st.insert({nums[i], nums[j], nums[l], nums[h]});
                        l++, h--;
                    }
                    else if (ss > temp)
                    {
                        l++;
                    }
                    else
                    {
                        h--;
                    }
                }
            }
        }
        for (auto i : st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};