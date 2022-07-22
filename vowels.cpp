#include<bits/stdc++.h>
using namespace std;


string vowelf(string s)
{
    string output;
    for(auto x: s)
    {
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
        {
            output.push_back(x);
        }
    }
    return output;
}
int main()
{
    string s="geeksforgeeks";
    int len=s.length();
    cout<<vowelf(s);
}