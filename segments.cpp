class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int result=0;
        while(ss>>s)
        {
            result+=1;
        }
        return result;
    }
};