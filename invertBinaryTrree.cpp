class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        swap(root->left,root->right);
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        
        
        return root;
    }
};