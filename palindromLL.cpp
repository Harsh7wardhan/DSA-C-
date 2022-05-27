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
class Solution {
private:
    bool isPal(vector<int> arr)
    {
        int s = 0;
        int e = arr.size()-1;
        
        while(s<=e)
        {
            if(arr[s]!=arr[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        
        return isPal(arr);
    }
};  








//method 2 (optimized)
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool compareList(ListNode* head1, ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* h=head;
        ListNode* mid = findMid(h);
        ListNode* h2=reverseList(mid);
        return compareList(head,h2);
    }
};