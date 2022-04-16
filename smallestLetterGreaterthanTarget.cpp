class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
     
        long long int s = 0;
        long long int e = letters.size()-1;
        char ans;
        while(s<=e)
        {
            long long int mid = s +(e-s)/2;
            if(target-'a'<letters[mid]-'a')
            {
                ans=letters[mid];
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return letters[s] > target ? letters[s] : letters[0];
        
    }
};
