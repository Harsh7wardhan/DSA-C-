//recursion
#include<bits/stdc++.h>
int f(int day , int last , vector<vector<int>> &points)
{
    if(day==0){
        int maxi = 0;
        for(int task = 0;task<3;task++)
        {
            if(task!=last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + f(day-1,task,points);
            maxi = max(maxi,point);
        }
    }
    return maxi;
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    f(n-1,3,points);
}

//memoization
int helper(int day , vector<vector<int>> &points, int last,vector<vector<int>>& dp){
    if(day == 0){
        int maxi = 0;
        for(int i = 0 ; i <=2 ; i++){
            if(i != last){
                maxi = max(maxi , points[day][i]);
            }
        }
        return maxi;
    }
    
    if(dp[day][last] != -1) return dp[day][last];
    
    int maxi = 0;
    for(int i = 0 ; i <= 2 ; i++){
        if(i != last){
            int merit = points[day][i] + helper(day - 1 , points , i, dp);
            maxi = max(maxi, merit);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (4,-1));
    int ans = helper(n - 1, points , 3,dp);
    return ans;
}

//space optimized
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4,0); 
    dp[0] = max(points[0][1] , points[0][2]);
    dp[1] = max(points[0][0] , points[0][2]);
    dp[2] = max(points[0][1] , points[0][0]);
    dp[3] = max(points[0][0] , max(points[0][2] , points[0][1]));
    
    
    for(int day = 1 ; day < n ; day++){
        vector<int> temp(4,0);
        for(int last = 0 ; last < 4 ; last++){
            temp[last] = 0;
            for(int task = 0 ; task < 3 ; task++){
                if(task != last){
                    temp[last] = max(points[day][task] + dp[task], temp[last]);
                }
            }
        }
        
        dp = temp;
    }
    
    return dp[3];
}