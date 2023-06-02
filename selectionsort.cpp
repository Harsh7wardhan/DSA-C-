#include<bits/stdc++.h>
using namespace std;

void selectsort(int arr[],int n)
{
    for(int pos=0;pos<=n-2;pos++)
    {
        int current=arr[pos];
        int minimum_position=pos;
       for(int j=pos;j<n;j++)
       {
           if(arr[j]<arr[minimum_position])
           {
               minimum_position=j;
           }
       } 
       swap(arr[pos],arr[minimum_position]);
    }
}

int main()
{
   int arr[]={-2,3,4,-1,5,-12,6,1,3};
   int n=sizeof(arr)/sizeof(arr[0]);
    selectsort(arr,n);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
}