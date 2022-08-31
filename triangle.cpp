//recursion
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle){
        int m = triangle.size();
        int n = triangle[0].size();
        if(i==m-1) return triangle[m-1][j];
        int down = triangle[i][j] + helper(i+1,j,triangle);
        int diag = triangle[i][j] + helper(i+1,j+1,triangle);
        
        return min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        
        return helper(0,0,triangle);
    }
};