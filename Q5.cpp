#include<bits/stdc++.h>
using namespace std;
int main()
{   

    int arr[] = { 30 , 20 , -1 ,10 , -2, -3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    vector<int> vect2;
    vector<int> vect3;

    for (int x : vect)
        cout << x << " ";
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            vect2.push_back(arr[i]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            vect2.push_back(arr[i]);
        }
    }
    
    for (int x : vect2)
        cout << x << " ";
    cout<<endl;
    

}

