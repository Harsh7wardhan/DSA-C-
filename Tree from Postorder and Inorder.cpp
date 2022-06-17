int findPos(int in[] , int n ,int element)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
                return i;
        }
        return -1;
    }
     Node* solve(int in[],int post[],int &index ,int Inorderstart , int InorderEnd,int n)
    {
        if(index>=n ||  Inorderstart> InorderEnd)
            return NULL;
            
        int element = post[index--];
        Node* root = new Node(element);
        int position = findPos(in,n,element);
        
        
        //recursive calls
        
        root->right = solve(in,post,index,position+1,InorderEnd,n);
        root->left = solve(in,post,index,Inorderstart,position-1,n);
        
         
        return root; 
            
    }
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postorderIndex = n-1;
        Node* ans = solve(in,post,postorderIndex,0,n-1,n);
        return ans;
}