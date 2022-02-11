#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
    string result;
    int i = 0;
    int n = s.length();

    while(i < n){
        while(i < n && s[i] == ' ') i++;
        if(i >= n) break;
        int j = i + 1;
        while(j < n && s[j] != ' ') j++;
        string sub = s.substr(i, j-i);
        if(result.length() == 0) result = sub;
        else result = sub + " " + result;
        i = j+1;
    }
    return result;
    }
int main()
{
    string s = "the sky is blue";
    cout<<reverseWords(s);

    return 0;
}
// ***#2*********
// class Solution {
// public:
// void reverseWords(string s) {
   
//    stack<string> st;
//    int i=0;
//    int end=s.length();
//    for(int i=0;i<end;i++)
//    {
//        string result="";
//        while(s[i]!=' ' && i<end)
//        {
//            result+=s[i];
//            i++;
//        }
//        st.push(result);
//     }
//    while(!st.empty())
//    {
//        cout<<st.top()<<" ";
//        st.pop();
//    }cout<<endl;
// };