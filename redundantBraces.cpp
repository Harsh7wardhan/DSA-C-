#include<stack>

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st ;
    
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        
        //opening brace or operator
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            st.push(ch);
        }
        // closing brace or letters
        else
        {
            if(ch==')')
            {
                bool flag = true;
                while(st.top()!='(')
                {
                    char top = st.top();
                     if(top == '+' ||top == '-' || top == '*' || top == '/') 
                     {
                           flag = false;
                     }
                    st.pop();
                }
                if(flag==true)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}
    