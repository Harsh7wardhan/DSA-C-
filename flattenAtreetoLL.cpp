class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr=root;
        Node*pred= NULL;
        while(curr != NULL){
            if(curr->left != NULL){
                pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};
