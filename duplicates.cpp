////////////////BRUTE FORCE////////////////////
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[6]={1,1,2,3,4,5};
//     for(int i=0;i<6;i++)
//     {
//         for(int j=i+1;j<6;j++)
//         {
//             if(arr[i]==arr[j])
//             {
//                cout<< arr[i];
//             }
//         }
//     }
// }

// *****************METHOD -2 *********************************
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(int arr[]) 
{
    int ans = 0;
    
    //XOR ing all array elements
    for(int i = 0; i<6; i++ ) {
    	ans = ans^arr[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<6;i++ ) {
    	ans = ans^i;
    }
    return ans;
}

int main()
{
    int arr[6]={1,3,3,2,4,5};
    cout<<findDuplicate(arr);
}