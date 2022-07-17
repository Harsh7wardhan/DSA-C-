#include<bits/stdc++.h>
using namespace std;
//iterative approach
int main()
{
    vector<int>A;
    int Val;
    cin>>Val;
    int lower_bound=INT_MIN, n=A.size();
    
    for(int i=0;i<n;i++){
        lower_bound = (A[i]>lower_bound && A[i]<=Val) ? A[i] : lower_bound;
    }
    
    if(lower_bound==INT_MIN)
    lower_bound = -1;
    
    return lower_bound;
}