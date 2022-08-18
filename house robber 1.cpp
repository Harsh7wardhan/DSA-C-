//MEMOIZATION
class Solution {
public:
    int helper(int ind,vector<int>& nums,vector<int> &dp){
        if(ind==0)return nums[ind];
        if(ind<0)return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        
        int pick = nums[ind] + helper(ind-2,nums,dp);
        int notpick = 0 + helper(ind-1,nums,dp);
        
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(n-1,nums,dp);
    }
};

//TABULATION
class Solution {
public:
    int helper(int ind,vector<int>& nums,vector<int> &dp,int n){
       
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1)pick+=dp[i-2];
            int notpick = 0+dp[i-1];
            
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(n-1,nums,dp,n);
    }
};


// SPACE OPTIMIZED
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev;
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};