void atBottom(stack<int>& myStack , int x)
{
    //base case
    if(myStack.empty())
    {
        myStack.push(x);
        return ;
    }
    
    int rem = myStack.top();
    myStack.pop();
    
    atBottom(myStack,x);
    myStack.push(rem);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    atBottom(myStack,x);
    return myStack;
}
