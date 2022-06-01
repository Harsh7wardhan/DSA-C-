class Solution
{

private:
    void popMid(stack<int>&s, int count ,int sizeOfStack)
    {
        //base case
        if(count==sizeOfStack/2)
        {
            s.pop();
            return ;
        }

        int rem = s.top();
        s.pop();

        popMid(s,count+1,sizeOfStack);
        s.push(rem);


    }
public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
            int count = 0;

            popMid(s,count,sizeOfStack);
    }
};

////////////////////////////METHOD 2//////////////////////////////////////
class Solution
{
    private:
    
    void popMid(stack<int> &s , int count , int sizeOfStack)
    {
        //base case
        if(count==sizeOfStack/2)
        {
            s.pop();
            return ;
        }
        
        int rem = s.top();
        s.pop();
        
        //recursive call
        popMid(s,count+1,sizeOfStack);
        
        s.push(rem);
    }
    
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int count = 0;
        
        popMid(s,count,sizeOfStack);
    }
};