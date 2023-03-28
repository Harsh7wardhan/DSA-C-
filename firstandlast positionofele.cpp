class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int i = 0, j = nums.size()-1;
        int start = -1, end = -1;
        while(i <= j)
        {
            int mid = (i+j)/2;
            if(nums[mid] == target){
               int temp = mid;
                while(mid > 0 && nums[mid-1] == target) //iterating left side of mid until target value is found
                    mid--;
                start = mid;
                while(temp < nums.size()-1 && nums[temp+1] == target) //iterating right side of mid until target value is found (here temp is equal to mid)
                    temp++;
                end = temp;
                
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
            else if(nums[mid] > target)
                j = mid-1;
            else
                i = mid+1;
        }
        
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};