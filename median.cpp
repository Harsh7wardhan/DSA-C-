#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1={1,2,3,4};
    vector<int> nums2={5,6,7,8};
    vector<int> result(nums1);
    result.insert(result.end(),nums2.begin(),nums2.end());
    
    sort(result.begin(),result.end());
    int median;
    int size=result.size();
    if(size%2==0)
    {
        int m1=(size/2);
        int m2=(size/2)-1;
        
        double n1=result[m1];
        double n2=result[m2];
        
        double median2=(n1+n2)/2;
        cout<<median2<<endl;
        cout<<"median is : "<<median2;
        
    }
    else
    {
        int mid=size/2;
        median=result[mid];
        cout<<"median is : "<<median;
    }
    
    
}
