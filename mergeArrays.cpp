#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {7,1,3,9,5};
    
    vector<int> c;
    a.insert( a.end(), b.begin(), b.end() );
    sort(a.begin(),a.end());
    for(auto x:a)
    {
        cout<<x<<" ";
    }
    
}

