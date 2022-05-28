///////////////////////////////////////////////////////////LOVE BABBAR APPROACH///////////////////////////////////////////////////////////////////////////////////
node* getMiddle(node* head)
{
    node* slow = head;
    node* fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    return slow;
    
}

node* merge(node* left , node* right)
{
    if(left==nullptr)
        return right;

    if(right==nullptr)
        return left;
    
    node* ans = new node(-1);
    node* temp = ans;
    
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    
    while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
    }
    
    while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
    }
    
    ans=ans->next;
    return ans;
    
}


node* mergeSort(node *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* mid=getMiddle(head);
    
    //divide list into two parts
    node* left = head;
    node* right = mid->next;
    mid->next=NULL;
    
    //recursive call to sort both halves
    left=mergeSort(left);
    right=mergeSort(right);
    
    //merging two halves to get result
    node* result = merge(left,right);
    
    return result;
    
}

////////////////////////////////////////////////////APPRAOCH SAME BUT WORKED IN LEETCODE/////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
            
    }
    
    //MergeSort Function O(n*logn)
    ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
};