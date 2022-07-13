class Solution{
  public:
    void solve(Node *root,int k , vector<int> &path ,int &count)
    {
        int sum =0;
        if(root==NULL)
        {
            return ;
        }
        
        path.push_back(root->data);
        
        solve(root->left,k,path,count);
        solve(root->right,k,path,count);
        
       
        
        for(int i=path.size()-1;i>=0;i--)
        {
            sum+=path[i];
            if(sum==k)
                count++;
        }
        
        path.pop_back();
        
    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> path;
        int count=0;
        
        solve(root,k,path,count);
        
        return count;
    }
};