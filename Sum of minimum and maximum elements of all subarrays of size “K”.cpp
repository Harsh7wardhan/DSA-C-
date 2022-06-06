long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    // Write your code here.
    long long ans=0;
    deque<int> maxi(k);
    deque<int> mini(k);
    for(int i=0;i<k;i++){
        //addition logic
        while(!maxi.empty() && nums[maxi.back()]<=nums[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && nums[mini.back()]>=nums[i]){
            mini.pop_back();
        }
        
        mini.push_back(i);
        maxi.push_back(i);
    }
    ans+=nums[maxi.front()]+nums[mini.front()];
    //for rest of the elements
    for(int i=k;i<n;i++){
        //next window
        //removal from sliding window
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }
        while(!maxi.empty() && nums[maxi.back()]<=nums[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && nums[mini.back()]>=nums[i]){
            mini.pop_back();
        }
        
        mini.push_back(i);
        maxi.push_back(i);
     ans+=nums[maxi.front()]+nums[mini.front()];
    }
    return ans;
}