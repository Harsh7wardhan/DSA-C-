char* reverse(char *S, int len)
{
    //code here
    stack<char> s;
    
    for(auto ch : S)
    {
        s.push(ch);
    }
    
    string ans="";
    
    while(!s.empty())
    {
        char x = s.top();
        ans.push_back(x);
        s.pop();
    }
    
    return ans;
}