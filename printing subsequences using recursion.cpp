#include<bits/stdc++.h>
using namespace std;

void printf(int ind,vector<int> &ds,vector<int> &arr,int n)
{
    if(ind==n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }

    //take or pick
    ds.push_back(arr[ind]);
    printf(ind+1,ds,arr,n);
    ds.pop_back();

    //do not take or pick
    printf(ind+1,ds,arr,n);
}

int main()
{
    vector<int> arr = {3,1,2};
    int n =3;
    vector<int> ds;
    printf(0,ds,arr,n);
    return 0;
}