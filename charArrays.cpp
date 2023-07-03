#include<bits/stdc++.h>
using namespace std;

/* **********************************BASIC DECLARATION******************************************
int main()
{
    char arr[100]="apple";
    int i=0;
    
    while(arr[i]!='\0')
    {
        cout<<arr[i]<<endl;
        i++;
    }
} */

//************************************PALINDROME OR NOT*********************************************************
/* int main()
{
    int n;
    cin>>n;

    char arr[n+1];
    cin>>arr;

    bool check = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[n-1-i])
        {
            check=0;
            break;
        }
    }
    
    if (check == true)
    {
        cout<<"Palindrome";
    }
    else{
        cout<<"not palindrome";
    }

}
**********************palindrome 2nd method*******************************
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = str.length() - 1;
 
    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
} */
