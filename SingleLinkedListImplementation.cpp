#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

    //constructor
    Node(int data)
    {
        this -> data= data;
        this -> next = NULL;
    }

    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory freed"<<value<<endl;
    }
};


void insertAtHead(Node* &head , int d)
{
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail , int d)
{
    Node* temp = new Node(d);
    tail->next=temp;
    tail=tail->next; //tail=temp also works

}

void deleteNode(int position , Node* &head,Node* &tail)
{
    //deleteing the first node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting the middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;

        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        if(curr->next == NULL) {
			tail = prev;
		}
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }   
}

void insertAtposition(Node* &tail,Node* &head ,int position , int d)
{
    //insert at start
    if(position==1)//we do this because we are starting from first pos and to insert at first pos itself req this code
    {
        insertAtHead(head,d);
        return;
    }
    
    Node *temp = head;
    int cnt = 1;

    while(cnt < position-1)
    {
        temp=temp->next;
        cnt++;
    }

    //inserting at last position
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

}

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    //create a new node
    Node* node1 =new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;


    //head pointed to node1
    Node* head= node1;
    Node*tail=node1;
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtposition(tail,head,4,22);
    print(head);

    deleteNode(4,head,tail);
    print(head);
    cout<<"HEAD POINTER : "<<head->data<<endl;
    cout<<"TAIL POINTER : "<<tail->data<<endl;

    return 0;
}