class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];
        int smallest = arr[0]+k;
        int largest = arr[n-1]-k;
        
        int mi,ma;
        
        for(int i=0;i<n;i++){
            mi = min(smallest,arr[i+1]-k);
            ma = max(largest,arr[i]+k);
            if(mi<0) continue;
            ans = min(ans,ma-mi);
        }
            
        return ans;    
        
    }
};