#include<bits/stdc++.h>
using namespace std;

int power(int n , int p)
{
    
    
    if(p==0)
    {
        return 1;
    }
    
    return n*power(n,p-1);
    
    
}


int fastPower(int n,int p)
{
    if(p==0)
        return 1;
    int subProb=fastPower(n,p/2);
    int subSq=subProb*subProb;
    if(n&1)
    {
        return n*subProb;
    }
    else
    {
        return subSq;
    }
    
}

int main()
{
    int n = 5 ;
    int p = 2 ;
    cout<<power(5,2);
    cout<<endl;
    cout<<fastPower(5,2);
}