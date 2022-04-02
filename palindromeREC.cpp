
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str,int i,int j)
{
    //base
    if(i>j)
        return true;
    if(str[i]!=str[j])
        return false;
    else
        return checkPalindrome(str,i+1,j-1);
}


int main()
{
    string str="hooh";
    bool isPal=checkPalindrome(str,0,str.length()-1);
    
    if(isPal)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}