#include<bits/stdc++.h>
using namespace std;

bool compare(string a,string b)
{
    if(a.length()==b.length())
        return a<b;//lexicographic

    else
        return a.length()<b.length();
}



void solve(string str , int index, string output , vector<string> &ans,vector<string>&list)
{
    //base case
    if(index>=str.length())
    {
        if(str.length()>0)
        {
            ans.push_back(output);
            string temp(output);
            list.push_back(temp);
            return;
        }
    }

    //exclude
    solve(str,index+1,output,ans,list);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str,index+1,output,ans,list);
    

}

vector<string> subseq(string str,vector<string>&list)
{
    string output ="";
    //int index = 0;
    vector<string> ans;
    solve(str,0,output,ans,list);
    return ans;
}

int main()
{
    vector<string> list;
    subseq("abc",list);
    sort(list.begin(),list.end(),compare);
    for(auto x : list)
    {
        cout<<x<<" ";
    }cout<<endl;
    return 0;    
}