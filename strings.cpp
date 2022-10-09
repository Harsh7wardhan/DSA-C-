#include<bits/stdc++.h>
using namespace std;


/* ****************************CONVERT LOWERCASE TO UPPER AND UPPER TO LOWERCASE******************************************
int main()
{
    string str = "absdiabdkadlasdlandaskzzn";
 
    for(int i =0; i<str.size();i++)            
    {
        str[i]-=32;
    }
    cout<<str<<endl;


    for(int i=0;i<str.size();i++)
    {
        str[i]+=32;
    }

    cout<< str <<endl;


} *//* 
*************************************SHORTCUT METHOD ************************************************************ */
/* int main()
{
    string s="sadasbayyyyybaslscsvdbj";
    transform(s.begin(),s.end(),s.begin(),::toupper); 
    cout<<s<<endl;

    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s<<endl;
} */
/* ************************************BIGGEST NUM FROM NUM STRING ***********************************************
int main()
{
    string num="656789938390";
    sort(num.begin(),num.end(),greater<int>());
    cout<<num<<endl;
} */

/* int main()
{
    string s =" fnsolbfosbfosbfsfibos";
    int freq[26];

    for(int i=0;i<26;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<s.size();i++)
    {
        freq[s[i]-'a']++;
    }

    char ans = 'a';
    int maxF = 0;

    for(int i=0;i<26;i++)
    {
        if(freq[i]>maxF)
        {
            maxF=freq[i];
            ans= i + 'a';
        }
    }

    cout<<maxF<<" "<<ans<<endl;
} */

/* int main()
{
    int n;
    cin>>n;

    last digit = 
}




 */


















