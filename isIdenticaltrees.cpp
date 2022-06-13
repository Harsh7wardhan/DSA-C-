class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL)
            return true;
            
        if(r1==NULL && r2!=NULL)
            return false;
            
        if(r1!=NULL && r2==NULL)
            return false;
            
            
        bool leftans = isIdentical(r1->left,r2->left);
        bool rightans = isIdentical(r1->right,r2->right);
            
        bool value = r1->data == r2->data ;
        
        if(leftans && rightans && value)
            return true;
        else
            return false;
            
    }
};