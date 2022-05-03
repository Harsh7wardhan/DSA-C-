class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
     int i=0,j=0;
    double sum=0;
    int n=nums.size();
    double maxi=INT_MIN;
    double result;
    while(j<n){
        if((j-i+1)<k) {
            sum=sum+nums[j];
            j++;
        }
        else if((j-i+1)==k){
            sum=sum+nums[j];
            result =sum/k;
           
            if(result>maxi){
                maxi=result;
            }
           sum=sum-nums[i];
            i++;
            j++;
        }
    }
    
  
    return maxi;
}
};