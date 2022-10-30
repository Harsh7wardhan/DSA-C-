#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n)
{   
    //largest element
    int largest=INT_MIN;
    for(int i=0;i<n;i++)
    {
        largest=max(largest,arr[i]);
    }

    //dynamic array
    vector<int> freq(largest+1,0);

    //update the freq array
    for(int i=0;i<n;i++)
    {

        
        freq[arr[i]]++;
    }

    //put back elements from freq o orignal array
    int j=0;
    for(int i=0;i<=largest;i++)
    {
        if (freq[i]>0)
        {
            arr[j]=i;
            freq[i]--;
            j++;
        }
        
    }
    return ;
}







int main()
{
   int arr[]={-2,3,4,-1,5,-12,6,1,3};
   int n=sizeof(arr)/sizeof(arr[0]);
    countsort(arr,n);
    for(auto x : arr)
    {
        cout<<x<<" ";
    }
}