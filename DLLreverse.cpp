//doubly linked list reverse
Node* reverseDLL(Node * head)
{
   Node* curr=head;
   Node* pre=NULL;
   Node* forward=NULL;
   while(curr!=NULL){
       forward=curr->next;
       curr->prev=curr->next;
       curr->next=pre;
       pre=curr;
       curr=forward;
   }
   return pre;
}