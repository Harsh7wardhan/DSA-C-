class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    
};


////////////////////////////////// APPROACH 2 /////////////////////////////
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        else{
            int leftH = height(root->left);
            int rightH = height(root->right);
            int diff = abs(rightH - leftH);
            return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);   
        } 
    }
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }else{
            return 1 + max(height(root->left), height(root->right));
        }
    }
};