
#include <bits/stdc++.h>
using namespace std;

void rec(string &str , int i , int j)
{
    if(i>j)
    {
        return ;
    }
    
    swap(str[i],str[j]);
    i++;
    j--;
    rec(str,i,j);
    
    
}


int main()
{
    string str = "geeks";
   

    rec(str,0,str.length()-1);
    cout<<str;
}
