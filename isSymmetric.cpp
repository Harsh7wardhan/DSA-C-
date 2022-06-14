/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* r , TreeNode* l)
    {
        if(r==NULL && l==NULL)
        {
            return true;
        }
        
        if(r==NULL || l==NULL || r->val!=l->val )
        {
            return false;
        }
        
        return helper(r->left,l->right) && helper(r->right,l->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        return helper(root->left,root->right); 
    }
};