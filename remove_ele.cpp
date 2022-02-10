// #include <iostream>
// #include <vector>
// using namespace std;
// int removeElement(vector<int>& nums, int val) {
//         int n=nums.size();
//         int count;
//         int k;
//         vector<int>::iterator it;
//         it = nums.begin();
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==val)
//             {
//                 count++;
//                 nums.erase(it+i);    
//             }    
//         }
//         k=nums.size();
        
        
//         return k;
        
//     }
 
// int main()
// {
//     vector<int> nums{ 1, 2, 1, 4, 5 };
    
//     cout<<"k : "<<removeElement(nums,1)<<endl;
//     for(auto x:nums)
//         {
//             cout<<x<<" ";
//         }
// }

// *******approach-2*****************
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//     int lastnonvalue=0;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]!=val){
//             nums[lastnonvalue]=nums[i];
//             lastnonvalue++;
//         }
// }
// return lastnonvalue;
// }
// };