//iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* forward=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;

        if(head=NULL || head->next==NULL)
        {
            return head;
        }

        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;

            //move ahead
            prev=curr;
            curr=forward;

        }

        return prev;

    }
};
//recursive approach
class Solution {
public:
void reverse(ListNode* &head,ListNode* curr,ListNode* prev)
{
    //base case
    if(curr==NULL)
    {
        head=prev;
        return;
    }
    
    ListNode *forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
    
}
ListNode* reverseList(ListNode* head) {

        ListNode* curr=head;
        ListNode* prev=NULL;
        reverse(head,curr,prev);
        return head;
        
        
    }
};