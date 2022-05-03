class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
     
        int n = s.length();
        int m = p.length();
        
        if(m>n)
            return {};
        
        vector<int> pv(26,0) , sv(26,0) , res ;
        
        for(int l=0;l<m;l++)
        {
            pv[p[l]-'a']++;
        }
        
        int i=0;
        int j=0;
        
        while(j<n)
        {
            sv[s[j]-'a']++;
            
            if(j-i+1<m)
                j++;
            else if((j-i+1)==m)
            {
                
                if(pv==sv)
                {
                    res.push_back(i);
                }
                
                sv[s[i]-'a']--;
                
                i++;
                j++;
            }
        }
        return res ; 
        
    }
};