// *******************APPROACH 1**********************
// class Solution {
// public:
//     int arrangeCoins(int n) {
        
//        int row=1;
//         while(n>=row)
//         {
//             n=n-row;
//             row++;
//             if(row==n)
//                 return row;
//         }
//         return row-1;
        
            
//     }
// };

//
        int i=0;
        int j=n;
        
        while(i<=j)
        {
            long long mid=(i+j)/2;
            
            if((mid*(mid+1))/2==n)
            {
                return mid;
            }
            else if((mid*(mid+1))/2>n)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        
        return j;***************************APPROACH-2******************************