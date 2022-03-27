#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[] , int size )
{
    //base case
    if(size==0 || size==1)
    {
        return true ;
    }

    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
        
        bool rem=isSorted(arr+1,size-1);
        return rem;
    }


}




int main()
{
    int arr[5]={2,1,3,4,5};
    int size=5;

    bool ans = isSorted(arr,size);
    if(ans)
    {
        cout<<"array is sorted"<<endl;
    }
    else
    {
        cout<<"not sorted"<<endl;
    }


}