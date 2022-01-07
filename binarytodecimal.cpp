#include<bits/stdc++.h>
using namespace std;

int binarytodecimal(string n , int len)
{
    int base = 1;
    int dec = 0;


    for (int i= len-1;i>=0;i--)
    {
        if(n[i]=='1')
        {
            dec+=base;
        }
        base=base*2;
    }
    
    return dec;

}

int main()
{
    string n = "1111";
    int len=n.length();
    cout<<binarytodecimal(n,len)<<endl;
}