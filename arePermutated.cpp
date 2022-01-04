#include <bits/stdc++.h>
using namespace std ;

bool arePermutated (string A ,string B)
{
    //get lengths
    int len1 = A.length();
    int len2 = B.length();

    //check lengths are same
    if(len1!=len2)
    {
        return false;
    }

    //sort both strings
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    //compare sorted strings
    for(int i=0;i<len1;i++)
    {
        if(A[i]!=B[i])
            return false;
    }

    return true;


}







int main()
{
    string A = "test";
    string B = "ttes";
    if (arePermutated(A, B))
      printf("Yes");
    else
      printf("No");
 
    return 0;
}