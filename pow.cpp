class Solution {
public:
    double myPow(double x, int n) {
    double ans=1;
    if (n == INT_MAX) return x;
    else if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
    if(n==0)
    {
        return 1;
    }
    //positive
    
    else if(n>0)
    {
        for(int i=0;i<n;i++)
        {
             ans=ans*x;
        }
        return ans; 
    }
    //negative
    
    else
    {
        int num=abs(n);
        for(int i=0;i<num;i++)
        {
            //  x=1/x;
             ans=ans*(1/x);
        }
        return ans;
    }
        
        
        
        
   }
};