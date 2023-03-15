#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;    
    }
};

Node*  insertintoBST(Node* root,int d)
{
    //base case
    if(root==NULL)
    {
        root=new Node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = insertintoBST(root->right,d);
    }
    else{
        root->left = insertintoBST(root->left,d);
    }

    return root;

}


void takeInput(Node* root)
{
    int data;
    cin>>data;

    if(data!=-1)
    {
        root = insertintoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

Node* minimum(Node* root){
    Node* temp = root ;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node* maximum(Node* root){
    Node* temp = root ;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

Node* deletefromBST(Node* root,int val){
    if(root==NULL)
        return root;
    if(root->data==val)
    {
        // 0 child
        if(root->left==NULL && root->right==NULL)
        {
            delte root;
            return NULL;
        }
        //1 child

        //left
        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right
        if(root->left==NULL && root->right!=NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 children
        if(root->left!=NULL && root->right!=NULL)
        {
            int mini = minimum(root->right)->data;
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data > val)
    {
        root->left = deletefromBST(root->left,val);
        return root;
    }
    else 
    {
        root->right = deletefromBST(root->right,val);
        return root;
    }
}


int main()
{
    Node* root = NULL;
    cout<<"Enter Data"<<endl;
    takeInput(root);

    cout<<"printing the bst"<<endl;
    levelOrderTraversal(root);
}