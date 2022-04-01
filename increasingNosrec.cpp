#include<bits/stdc++.h>
using namespace std;

int jolo(int n)
{
    //base case
    if(n==0)
        return -1;
    
    jolo(n-1);
    cout<<n<<endl;
}

int main()
{
    int n = 5 ;
    jolo(5);
}