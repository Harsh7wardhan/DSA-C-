// The idea is to find candidate substring and evaluate it to see if it matches the required criteria (all characters in substring have frequency >= k). Update the answer if the criteria matches and candidate substring is longest.

// Note: Candidate substring is a potential substring that might match required criteria and lead to answer.

// Identifying candidate substring
// Candidate substring: s[l..r) where l=starting point of sliding window, r=end point of sliding window (not inclusive)

// To find candidate substring, we make use of frequency count of characters in string s. Distinguishing point for candidate substring is when frequency of last character of sliding window (s[r]) is < k, then s[r] cannot be part of candidate string. Hence, s[l..r) becomes a candidate substring.

// Evaluating candidate substring
// To evaluate candidate substring, trim the unnecessary portions of substring from left and right end that do not match the required criteria i.e. remove the characters from substring from left / right whose frequency < k. Update temporary frequency array that stores character frequency count of substring s[l..r).

// For the remaining substring, check if all the characters have frequency >= k. If so, then we have a substring matching required criteria. Update final answer with length of substring if it is larger than current answer.


// Sliding Window
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestSubstring(string s, int k) {
        int l = 0, r = 0, ans = 0; // l=staring point of sliding window, r=ending point of sliding window, ans=required answer
        int freq[26] = {0}; // stores frequency of characters in string s
        int temp[26] = {0}; // stores frequency of characters in sub string s[l..r) 
        
        for(int i=0; i<s.size(); i++)
            freq[s[i]-'a']++;
        
        while(l<=r && r<=s.size())
        {
		    // below is the condition to identify candidate substring
			// if frequency of given character is less than k, then we have substring s[l..r) as a candidate substring
            if(r==s.size() || freq[s[r]-'a']<k)
            {
                int templ = l, tempr = r-1;
                
				// evaluate the candidate substring to see if it can be a potential answer
                while(templ<=tempr)
                {
                    bool change = false;
					
					// trimming candidate substring from left on the basis of character frequency in temporary count array (temp)
                    while(templ<=tempr && temp[s[templ]-'a']<k)
                    {
                            temp[s[templ]-'a']--; // decrement count of char s[templ] from temp
                            templ++;  
                            change = true;
                    }
                    
					// trimming candidate substring from right on the basis of character frequency in temporary count array (temp)
                    while(templ<tempr && temp[s[tempr]-'a']<k)
                    {
                            temp[s[tempr]-'a']--; // decrement count of char s[tempr] from temp
                            tempr--;
                    }

					// below is O(26) operation (constant time)
					// use below loop to find if candidate substring s[templ..tempr] has characters with frequency >= k
                    int i=0;
                    for(i=0; i<26; i++)
                    {
                        if(temp[i]<k && temp[i]>0)
                            break;
                    }
                 
				    // if above loop runs till 26, it means that we have a substring s[templ..tempr] meeting question criteria (all characters in substring have frequency >= k)
                    if(i==26)
                    {
					    // check if answer can be updated with length of substring s[templ..tempr]
						// and break out of the loop as we don't need to check any further due to the fact that we want only max length, hence, no need to find smaller substrings satisfying the criteria
                        if(tempr-templ+1>=ans)
                        {
                            ans = tempr-templ+1;
                            break;
                        }
                    }

					// if no trimming has occurred from left then update templ to continue checking the candidate substring
                    if(!change)
                    {
                        temp[s[templ]-'a']--;
                        templ++;
                    }
                }         
                
				// update starting pointer (l) for new candidate substring
                l = r; 
				
				// reset temp
                for(int i=0; i<26; i++) temp[i] = 0;
            }
            else // make s[r] a part of candidate substring as frequency of character s[r] in s is >= k
            {
                temp[s[r]-'a']++;
            }

			// keep updating end of window with r
            r++;
        }
        
        return ans;
    }
};