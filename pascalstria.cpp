#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> fulo(int size)
{
    vector<vector<int>>ans;
    for(int i=0;i<size;i++)
    {
        vector<int> v(i+1,1);
        for(int j=1;j<i;j++)
        {
            v[j]=ans[i-1][j]+ans[i-1][j-1];
        }
        ans.push_back(v);
    }
    return ans;   
}




int main()
{
    int size=5;

    fulo(5);
}   
