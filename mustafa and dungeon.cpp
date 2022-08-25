#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>energy, confi;
    energy = {{3, 2, 5}, {8, 9, 1}, {4, 7, 6}};
    confi = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    
    int n = 3; // no. of rows
    int m  = 3; // no. of columns
    
    int strength = INT_MAX;
    
    // calculate the min energy from the last row
    for(int i=0; i<m; i++)
         strength = min(strength, energy[n-1][i]);
    
    // start from the last second row
    for(int i = n-2; i>=0; i--){
        int temp_min = INT_MAX;
        for(int j = 0; j<m; j++){
            temp_min = min(temp_min, energy[i][j] - confi[i][j] + strength);
        }
        strength = temp_min;
    }
    cout<<strength;
    return 0;
}