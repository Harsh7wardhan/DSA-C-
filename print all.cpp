#include<bits/stdc++.h>
using namespace std;

void printS(int ind,vector<int> &ds,int s,int sum,int arr[],int n)
{
    if(ind==n){
        if(s==sum){
            for(auto it : ds)
            {
                cout<<it<<" ";
            }
        }
        return;
    }

    //pick
    ds.push_back(arr[ind]);
    s+=arr[i];
    printS(ind+1,ds,0,sum,arr,n);
    ds.pop_back();
    s-=arr[i];

    //dont pick
    printS(ind+1,ds,0,sum,arr,n);

}


int main()
{
    int arr[]={1,2,1};
    int n = 3;
    int sum =2;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}