#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>>  v  {{ 1, 2, 3, 4 },
                            { 5, 0, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 }};
                            
    int n=4;
    int m=4;
    vector<int> r,c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==0)
            {
                r.push_back(i);
                c.push_back(i);
            }
        }
    }
   
    for(auto x:r)
    {
        for(int i=0;i<n;i++)
        {
            v[x][i]=0;
        }
    }
    for(auto y:c)
    {
        for(int i=0;i<n;i++)
        {
            v[i][y]=0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}