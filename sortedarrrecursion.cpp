
#include <iostream>

using namespace std;

bool sorted(int arr[] , int size)
{
    if(size==0 || size==1)
    {
        return true;
    }
    if(arr[0]<arr[1] && sorted(arr+1,size-1))
    {
        return true;
    }
    return false;
    
}


int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<sorted(arr,5);
    
}