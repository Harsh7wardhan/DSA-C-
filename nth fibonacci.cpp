#include<bits/stdc++.h>
using namespace std;

// TOP DOWN  RECURSION + MEMOIZATION
int fib(int n , vector<int> &dp){
    if(n<=1)
        return n;
    
    //step 3
    if(dp[n]!=-1)
        return dp[n];
        
    //step2
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    
    //step 1
    vector<int> dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    
    cout<<fib(n,dp)<<endl;
    
}


// BOTTOM UP TABULATION
#include<bits/stdc++.h>
using namespace std;

int main()
{
       int n;
    cin>>n;
    
    //step 1
    vector<int> dp(n+1);
    
    //step 2
    dp[0]=0;
    dp[1]=1;
    
    //step 3
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    
}




