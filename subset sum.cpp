class Solution{   
public:
   bool isSubsetSum(vector<int>arr, int sum){
       // code here 
       int n=arr.size();
       int t[n+1][sum+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<sum+1;j++){
               if(j==0){
                   t[i][j]=true;
               }
               else if(i==0){
                   t[i][j]=false;
               }
               else if(j>=arr[i-1]){
                   t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                   
               }
               else{
                   t[i][j]=t[i-1][j];
               }
           }
       }
       return t[n][sum];
   }
};