#include<bits/stdc++.h>
using namespace std;




/* ***************************************************LINEAR SEARCH********************************************************************
int LinearSearch(int arr[] , int n , int key)
{
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            return i;
        }
    }
    return -1;
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
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    int key;
    cin>>key;

    cout<<LinearSearch(arr , n , key);
} */

/* 
******************************************BINARY SEARCh********************************************************************* */


/* int BinarySearch(int arr[],int n , int key)
{
    int start=0;
    int end=n;

    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
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
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    int key;
    cin>>key;

    cout<<BinarySearch(arr , n , key);
} 
 */
//*************************************************SELECTION SORTING*******************************************************************
/* int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {   
            if(arr[j]<arr[i])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
                
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

} */
//********************************SELECTION SORT 2******************************************************************
// Selection sort in C++



// Selection sort in C++



// function to swap the the position of two elements
/* void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
} */

// function to print an array
/* void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

// driver code
int main() {
  int data[] = {20, 12, 10, 15, 2};
  int size = sizeof(data) / sizeof(data[0]);
  selectionSort(data, size);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, size);
} */

//**********************************************BUBBLE SORT********************************************************************
/* int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int counter=1;
    while(counter<n)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        counter++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


} */
/* ******************************INSERTION SORT*********************************************
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

} */

//*******************max till i (array problem)************************************************************
/* int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int mx=-1999999999;  /////// We can also use INT_MIN in climits directory instead of -19999999?///////
    for(int i=0; i<n ; i++)
    {   
        mx=max(mx,arr[i]);
        cout<<mx<<endl;
    }



} */

//******************************SUM OF ALL SUB-ARRAYS*************************************************
/* int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int current=0;
    for(int i=0;i<n;i++)
    {   
        current=0;
        for(int j=i;j<n;j++)
        {
            current+=arr[j];
            cout<<current<<endl;
        }
        
    }

} */
//*****************************PROBBLEM :MAX LENGTH OF SUBARRAY******************************************************************
/* int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=2;
    int j=2;
    int curr=2;
    int pd=arr[1]-arr[0];
    while (j<n)
    {
        if(pd==arr[j]-arr[j-1])
        {
            curr++;

        }
        else{
            pd=arr[j]-arr[j-1];
            curr=2;
        }
        ans=max(ans,curr);
        j++;
        
    }
    
    cout<<ans<<endl;
}
 */
//************************************NO OF RECORD BREAKING DAYS*******************************************************************

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    arr[n]=-1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    int ans =0;
    int mx=-1;
    for(int i =0;i<n;i++)
    {
        if(arr[i]>mx && arr[i]>arr[i+1])
        {
            ans++;
        }

        mx=max(mx , arr[i]);
    }
    cout<<ans<<endl;

}

