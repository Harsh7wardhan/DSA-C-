class Solution
{
    public:
    
    pair<bool,int> fastsum(Node* root)
    {
        if(root==NULL)
        {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftans = fastsum(root->left);
        pair<bool,int> rightans = fastsum(root->right);
        
        bool left = leftans.first;
        bool right = rightans.first;
        
        bool cond = root->data == leftans.second + rightans.second ;
        
        pair<bool,int> ans;
        
        if(cond && left && right)
        {
            ans.first=true;
            ans.second=root->data+leftans.second+rightans.second;
        }
        else
        {
            ans.first = false;
        }
        
        return ans;
    }
 
    bool isSumTree(Node* root)
    {
         // Your code here
         return fastsum(root).first;
    }
};