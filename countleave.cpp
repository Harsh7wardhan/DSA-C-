/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
void inorder(Node* root , int &cnt)
{
    if(root == NULL)
        return;
        
    
    inorder(root->left,cnt);
    
    if(root->left==NULL && root->right==NULL)
    {
        cnt++;
    }
    
    inorder(root->right,cnt);
        
        
}
int countLeaves(Node* root)
{
  // Your code here
  int cnt = 0;
  inorder(root,cnt);
  return cnt;
  
}
