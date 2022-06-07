class Solution {
public:
    void LeftTraversal(Node *root , vector<int> &ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
           return;
        
        ans.push_back(root->data); 
        if(root->left)
        {
            LeftTraversal(root->left,ans);
        }
        else
        {
            LeftTraversal(root->right,ans);
        }
    }
    
    void LeafTraversal(Node *root , vector<int> &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            {
                ans.push_back(root->data);
                return;
            }
        LeafTraversal(root->left,ans);
        LeafTraversal(root->right,ans);
    }
    
    void RightTraversal(Node *root , vector<int> &ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
           return;
           
        if(root->right)
           RightTraversal(root->right, ans);
        else
            RightTraversal(root->left, ans);
            
        //wapas aagye
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        //left part print/store
         LeftTraversal(root->left, ans);
        
        //traverse Leaf Nodes
        
        //left subtree
         LeafTraversal(root->left, ans);
        //right subtree
         LeafTraversal(root->right, ans);
        
        //traverse right part
        RightTraversal(root->right, ans);
        
        return ans;
        
    }
};