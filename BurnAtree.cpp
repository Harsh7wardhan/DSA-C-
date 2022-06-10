Node* mappingNodeToParent(Node* root, int target, map<Node*, Node*> &nodeToParent)
    {
        Node* targetNode = NULL;    //targetNode find karne ke liye
        queue<Node*> q; 
        q.push(root);
        nodeToParent[root] = NULL;  //root ka parent toh null hota hai 
        
        while(!q.empty())
        {
            Node* frontNode = q.front();
            q.pop();
            
            if(frontNode->left)
            {
                nodeToParent[frontNode->left] = frontNode;  //storing node->parent mapping
                q.push(frontNode->left);                    //pushing for next processing in the queue
            }   
            
            if(frontNode->right)
            {
                nodeToParent[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
            
            if(frontNode->data == target)
                targetNode = frontNode;     //finding ki kya curr front node is targetNode?
        }
        
        return targetNode;
    }
    
    int burnTree(map<Node*, Node*> nodeToParent, Node* targetNode)
    {
        map<Node*, bool> visited;   //to check ki kya current node visited hai ya nahi? 
                                    //Agar nahi toh fir uski processing hogi queue mein daal ke
        queue<Node*> q;
        
        q.push(targetNode);         //targetNode se queue ki shuruaat hogi & visit hogya hai vo toh TRUE
        visited[targetNode] = true;
        
        int totTime = 0;            //to store the time
        
        while(!q.empty())
        {
            bool flag = 0;          //agar flag true ho jaata hai mtlb ki kuch burn hua hai toh incrementing time
            int size = q.size();    //size isliye nikaal raha hu kyuki humein current Node ke children
                                    //and parent sabko burn karna hai (agar exist karte hai toh)
           
           /*for loop mein isliye kaam kar raha hu KYUKI
           hum dekhenge poore queue mein ki kya uska kuch bhi left/right/parent
           hai ya nahi, agar hai toh visited mein daalo, queue mein daalo aur 
           flag ko true mark karke time ko badhaao*/
            for(int i = 0; i < size; i++)
            {
                Node* front = q.front();
                q.pop();    
                
                if(front->left != NULL && visited[front->left] == 0)
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                
                if(front->right != NULL && visited[front->right] == 0)
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                
                if(nodeToParent[front] != NULL && visited[nodeToParent[front]] == 0)
                {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            
            }
            
            if(flag == 1)
                totTime++;
        }
        
        return totTime;
    }
    
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = mappingNodeToParent(root, target, nodeToParent);
        
        int totalTime = burnTree(nodeToParent, targetNode);
        return totalTime;
    }