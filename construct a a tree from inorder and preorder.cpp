class Solution{
    public:
    int findPos(int in[] , int n ,int element)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
                return i;
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index ,int Inorderstart , int InorderEnd,int n)
    {
        if(index>=n ||  Inorderstart> InorderEnd)
            return NULL;
            
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPos(in,n,element);
        
        
        //recursive calls
        root->left = solve(in,pre,index,Inorderstart,position-1,n);
        root->right = solve(in,pre,index,position+1,InorderEnd,n);
         
        return root; 
            
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderIndex = 0;
        Node* ans = solve(in,pre,preorderIndex,0,n-1,n);
        return ans;
    }
};