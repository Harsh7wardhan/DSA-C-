#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5]={8,1,3,4,6};
    int n=5;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {   
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}