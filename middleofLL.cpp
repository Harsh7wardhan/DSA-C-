/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Approach 1

class Solution {
public:
    
    int getLength(ListNode* head)
    {
        int len = 0 ;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode* middleNode(ListNode* head) {
        
        int len=getLength(head);
        int ans=len/2;
        
        ListNode* temp=head;
        int cnt=0;
        while(cnt<ans)
        {
            temp=temp->next;
            cnt++;
        }
        
        return temp;
    }
};

//Approach-2 fast and slow nodes

class Solution {
public:
    
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;
            
            slow=slow->next;
        }
        
        return slow;
    }
};