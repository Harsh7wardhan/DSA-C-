void insertAtBottom(stack<int> &stack , int element)
{
    //base case
    if(stack.empty())
    {
        stack.push(element);
        return;
    }
    int num = stack.top();
    stack.pop();
    
    insertAtBottom(stack,element);
    stack.push(num);
  
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty())
        return ;
    
    
    int top = stack.top();
    stack.pop();
    
    reverseStack(stack);
    
    insertAtBottom(stack,top);

   return;
}