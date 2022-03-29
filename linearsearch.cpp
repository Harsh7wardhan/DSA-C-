#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int *arr , int size , int key)
{
    if(size==0)
    {
        return false;
    }
    
    if(arr[0]==key)
    {
        return true;
    }
    else
    {
        return linearSearch(arr+1,size-1,key);
    }
    
    
}


int main()
{
    int arr[5]={1,2,3,4,5};
    int size=5;
    int start;
    bool ans = linearSearch(arr,5,3);
    
    if(ans)
    {
        cout<<"haa";
    }
    else{
        cout<<"naa";
    }
    
    
    
    
    
}