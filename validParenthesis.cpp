//appraoch 1 using MAPS
class Solution {
public:
    bool isValid(string s) {
        string st;
        map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        st.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if(mp[st.back()] == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        return st.size() ? 0 : 1;
    }
};

//approach 2
class Solution {
public:
    bool isValid(string s) {
        stack<char> t; // stack for storing opening parentheses
        int i; // variable i to travel
        
        for(auto i:s) // travel into whole string
        {
            // if any opening parentheses, push into stack
            if(i == '(' || i =='{' || i == '[')
            {
                t.push(i);
            }
            else
            {
                // check condition for false
                if(t.empty() || (t.top() == '(' && i != ')') || (t.top() == '{' && i != '}') || (t.top() == '[' && i != ']'))
                {
                    return false;
                }
                
                t.pop(); // else pop from stack
            }
        }
        
        return t.empty(); // if stack is empty then it is valid, otherwise no
    }
};

//LOVE BABBAR
class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
     for(int i=0; i<s.length(); i++) {
         
         char ch = s[i];
         
         //if opening bracket, stack push
         //if close bracket, stacktop check and pop
         
         if(ch == '(' || ch == '{' || ch == '['){
             st.push(ch);
         }
         else
         {
             //for closing bracket
             if(!st.empty()) {
                  char top = st.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      st.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             else
             {
                 return false;
             } 
         }  
     }
    
    if(st.empty())
        return true;
    else
        return false;
        
    }
};