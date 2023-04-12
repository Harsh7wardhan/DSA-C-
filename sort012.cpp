Node *sortList(Node *head)

{

    int zeroCount = 0;

    int oneCount = 0;

    int twoCount = 0;

    Node *temp = head;

    while (temp != NULL)
    {

        if (temp->data == 0)

            zeroCount++;

        else if (temp->data == 1)

            oneCount++;

        else if (temp->data == 2)

            twoCount++;

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {

        if (zeroCount != 0)
        {

            temp->data = 0;

            zeroCount--;
        }

        else if (oneCount != 0)
        {

            temp->data = 1;

            oneCount--;
        }

        else if (twoCount != 0)
        {

            temp->data = 2;

            twoCount--;
        }

        temp = temp->next;
    }

    return head;
}

// appraoch 2
void insertattail(Node *&tail, Node *&curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    Node *zeroathead = new Node(-1);
    Node *zeroattail = zeroathead;
    Node *oneathead = new Node(-1);
    Node *oneattail = oneathead;
    Node *twoathead = new Node(-1);
    Node *twoattail = twoathead;
    Node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertattail(zeroattail, curr);
        }
        else if (value == 1)
        {
            insertattail(oneattail, curr);
        }
        else if (value == 2)
        {
            insertattail(twoattail, curr);
        }
        curr = curr->next;
    }
    if (oneathead->next != NULL)
    {
        zeroattail->next = oneathead->next;
    }
    else
    {
        zeroattail->next = twoattail->next;
    }
    oneattail->next = twoathead->next;
    twoattail->next = NULL;
    head = zeroathead->next;
    delete zeroathead;
    delete oneathead;
    delete twoathead;
    return head;
}