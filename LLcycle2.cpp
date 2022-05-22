//APPROACH 1  BOTH TIME AND SPACE O(N)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     unordered_map<ListNode*,bool> mp;
        while(head)
        {
            if(mp.count(head))
             return head;
            else
            {
              mp[head]=true;
              head=head->next;
            }
        }
        return NULL;
    }
};

//APPROACH 2 
//Time coplexity O(n) and space complexity O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode* slow=head;
    ListNode* fast=head;   
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
          if(slow==fast)
           break;   
        }
           if(fast==NULL || fast->next==NULL) return NULL;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow; //starting node of the LOOP  VERY  impppppp************
    }
};