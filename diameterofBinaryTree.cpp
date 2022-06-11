
//////////////////////////////////////////// APPROACH - 1 O(N^2) /////////////////////////////////////////////////////////////////
class Solution {
  private:
  int height(Node* root)
  {
      if(root==NULL)
        return 0;
    
    
    int left = height(root->left);
    int right = height(root->right);
    
    int ans = max(left,right) + 1;
    
    return ans;
  }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        if(root==NULL)
            return 0;
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;
        
        int x = max(op1 , max(op2,op3));
        
        return x;
    }
};

/////////////////////////////////////////////// APPROACH 2 FASTER O(N) ////////////////////////////////////////////////////////
class Solution {
  
  private:
  pair<int,int> getFastDiameter(Node* root)
  {
    if(root==NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = getFastDiameter(root->left);
    pair<int,int> right = getFastDiameter(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second +1 ;
    
    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second , right.second) +1 ;
    
    return ans;
    
  }

  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        getFastDiameter(root);
    }
};

