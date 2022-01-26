#include<bits/stdc++.h>
using namespace std;
int findUnique(int arr[],int size)
{
    int ans = 0;
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}   

int main()
{
    int arr[5]={2,4,7,2,7};
    int size=5;

    cout<<findUnique(arr,size);
}