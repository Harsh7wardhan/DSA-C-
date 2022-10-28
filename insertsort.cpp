#include<bits/stdc++.h>
using namespace std;

void insertsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int current=arr[i];
        int prev = i-1;
        while(prev>=0 && prev > current)
        {
            arr[prev+1]=arr[prev];
            prev=prev-1;
        }
        arr[prev+1]=current;
    }
}


int main()
{
   int arr[]={-2,3,4,-1,5,-12,6,1,3};
   int n=sizeof(arr)/sizeof(arr[0]);
    insertsort(arr,n);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
}