// 1

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        Node* curr = root;
        while(curr->left!=NULL)
        {
            Node* temp = curr;
            while(curr!=NULL)
            {
                curr->left->next = curr->right;
                curr->right->next=curr->next==NULL ? NULL : curr->next->left;
                curr=curr->next;
            }
            curr = temp ->left;
        }
        return root;
    }
};

//2 BFS
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* front = q.front();
               
                if(n-1 == i)
                    front->next = NULL;
                 q.pop();
                if(n-1!=i)
                    front->next = q.front();
                
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                
            }
            
        }
        return root;
    }
};