#include<bits/stdc++.h>
using namespace std;
 
int pivotIndex(vector<int>& nums) {
        int prefix_sum  =0;
        for(int i= 0; i < nums.size(); i++){
            prefix_sum += nums[i];
        }
        int left_sum =0; 
        int right_sum = prefix_sum ;
        for(int i= 0; i < nums.size(); i++){
            right_sum = right_sum - nums[i];
            if(left_sum == right_sum)
                return i;
            
            left_sum += nums[i];
        }
        return -1;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(5);
    nums.push_back(6);

    for (int i = 0; i < nums.size(); i++)  
  {  
    cout << nums[i] << " ";   
  }  
    cout<<endl;

    cout<<pivotIndex(nums);
    
}