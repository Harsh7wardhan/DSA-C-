/* #include<bits/stdc++.h>
using namespace std;
 */
/* ***********************************************REVERSE ARRAY*********************************************************************
void reverse(int *arr,int size)
{
    int s=0;
    int e=size-1;
    while(s<e){
        swap(arr[s],arr[e]);
    s+=1;
    e-=1;
    }
    

}



int main()
{
    int size;
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    reverse(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    } 
} */
/* *****************************************************BINARY SEARCH*******************************************************************
#include<iostream>
using namespace std;

int binarySearch(int *arr , int size , int key)
{
    int start=0;
    int end=size-1;
    int mid =(start+end)/2;
    while(start<end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
    int key;
    cout<<"enter key"<<endl;
    cin>>key;
    int index=binarySearch(arr,size,key);
    if(index!=-1)
    {
        cout<<key<<" is present at "<<index;
    }
    else{
        cout<<key<<" is not found "<<endl;
    }
}    */
//********************************PRINT ALL PAIRS IN A ARRAY************************************************
/* #include<bits/stdc++.h>
using namespace std;
void printf(int arr[],int n)
{
    for(int i=0; i<n ; i++)
    {  int x=arr[i];
        for(int j=0;j<n;j++)
        {
            int y = arr[j];
            cout<< x <<","<<y<< endl;
        }
        cout<<endl;
    }
    
}

int main()
{

    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf(arr,n);

} */
//********************************PRINT ALL SUB ARRAYS IN A ARRAY / SUM OF SUBARRAYS ************************************************
#include<bits/stdc++.h>
using namespace std;
/* int printsubarrays(int arr[],int n) // brute force O(n3)
{
    int largestsum=0;
    for(int i=0;i<n;i++)
    {
        for ( int j =i ; j<n; j++ )
        {
            int Subsum=0;
            for(int k=i;k<=j;k++)
            {
                Subsum+=arr[k];
            }  
            largestsum=max(largestsum,Subsum);
           
        }
        
    }
    return largestsum;

}

int printsubarrays2(int arr[],int n) // prefix sum algorithm o(n2)
{
    //prefix sums
    int prefix[100]={0};
    prefix[0]=arr[0];

    for(int i =1 ;i<n ; i++)
    {
        prefix[i] = prefix[i-1]+arr[i];
    }

    //largest sum logic
    int largestsum=0;

    for(int i=0;i<n;i++)
    {
        for ( int j =i ; j<n; j++ )
        {
            int Subsum=i>0 ? prefix[j]-prefix[i-1]: prefix[j];
            largestsum=max(largestsum,Subsum);
           
        }
        
    }
    return largestsum;

}

int kadanealg(int arr[], int n )   //kadanes algorithm ** O(N) linear approach
{
    int cs=0;
    int largestsum=0;
    for(int i = 0;i<n;i++)
    {
        cs+=arr[i];
        if(cs<0)
        {
            int cs=0;
        }
        largestsum=max(largestsum,cs);
    }
    return largestsum;
}
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


   cout<< printsubarrays(arr,n) << endl;
   
   cout<< printsubarrays2(arr,n) << endl;

   cout<< kadanealg(arr,n) << endl;



    return 0;
} */

//***********************SUBARRAY SUMS USING VECTORS*******************

//LOWER BOUND
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    vector<int> A;
    int size;
    cin>>size;

    cout<<"enter array";
    for(int i=0;i<size;i++)
    {   
        cin>>num;
        A.push_back(num);
    }
    sort(A.begin(),A.end());
    
    for(auto x : A)
    {
        cout<<x<<" ";
    }   

    cout<<"enter a key"<<endl;
    int key;
    cin>>key;
    for(int i=0;i<size;i++)
    {
        if(key==A[i])
        {
            return (A[i-1]);
        }
        else{
            cout<<"kal ana";
        }
    }
    
}