#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n)
{
    for(int times=1;times<n;times++)
    {
        for(int j=0;j<n-times;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main()
{
   int arr[]={-2,3,4,-1,5,-12,6,1,3};
   int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
}