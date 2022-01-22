
// *****************************************************************CLOCKWISE*******************************************************************
// #include<bits/stdc++.h>
// using namespace std;


// //intuition for 90 degree clockwise rotation
// //1->transpose 2->reverse
// void rotate(int matrix[][4],int n , int m)
// {   
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             swap(matrix[i][j],matrix[j][i]);
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         reverse(matrix[i],matrix[i]+n);
//     }

// }

// int main()
// {
//     int matrix[][4] = { { 1, 2, 3, 4 },
//                       { 5, 6, 7, 8 },
//                       { 9, 10, 11, 12 },
//                       { 13, 14, 15, 16 } };
//     int n=4;
//     int m=4;

//     rotate(matrix,n,m);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<matrix[i][j]<<" ";
//         }
//         cout << '\n';
//     }
// }


// ********************************************************ANTI-CLOCKWISE*********************************************************************************************
// #include<bits/stdc++.h>
// using namespace std;


// //intuition for 90 degree anti-clockwise rotation
// //1->transpose 2->reverse
// void rotate(int matrix[][4],int n , int m)
// {   
    
    
//      //reverse
//     for(int i=0;i<n;i++)
//     {
//         reverse(matrix[i],matrix[i]+n);
//     }  
    
//     //transpose
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             swap(matrix[i][j],matrix[j][i]);
//         }
//     }

   

// }

// int main()
// {
//     int matrix[][4] = { { 1, 2, 3, 4 },
//                       { 5, 6, 7, 8 },
//                       { 9, 10, 11, 12 },
//                       { 13, 14, 15, 16 } };
//     int n=4;
//     int m=4;

//     rotate(matrix,n,m);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout<<matrix[i][j]<<" ";
//         }
//         cout << '\n';
//     }
// }