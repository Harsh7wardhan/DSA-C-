#include <bits/stdc++.h>

using namespace std;
string reverse(string s)
{
    int x=0;
    int f=s.length()-1;
    while(x<s.length() && x<=f)
    {
        swap(s[x],s[f]);
        x++;
        f--;
    }
    return s;
}
bool isPalindrome(string str,string answer)
{
    if(answer==str)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string str = "A man, a plan, a canal: Panama";
    int i, j;
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    for(i = 0; str[i] != '\0'; ++i)
    {
        while (!( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0') )
        {
            for(j = i; str[j] != '\0'; ++j)
            {
                str[j] = str[j+1];
            }
            str[j] = '\0'; 
        }
    }
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
       
    }
    cout<<str<<endl;
    
    string answer=reverse(str);
    cout<<answer<<endl;
    
    
    if(str==answer)
    {
        cout<<"is a palindrome"<<endl;
    }
    else
    {
        cout<<"MAA CHUDA"<<endl;
    }
       
}