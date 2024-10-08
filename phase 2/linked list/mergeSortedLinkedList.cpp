#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data;
    node* next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtTail(node*& head, node*& tail, int d)
{
    node* temp = new node(d);

    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void print(node*& head)
{
    node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// question - Sort 0s,1sand 2s

void insertAtTail(node*& tail, node* curr)
{
    tail->next = curr;
    tail = curr;
}

void sortLinkedList(node*& head)
{

    // method 1

    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* twoHead = new node(-1);
    node* twoTail = twoHead;

    // create sublist of 0s,1s and 2s
    node* curr = head;
    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge 3 sublist
    // 1s list is not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        // 1s list -> empty
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    // setup head;
    head = zeroHead->next;

    // delete dummy nodes
    zeroHead->next = NULL;
    oneHead->next = NULL;
    twoHead->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    /*
    // method 2
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else if (temp->data == 2)
        {
            twoCount++;
        }
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
    */
}

// ques - merge two sorted linked list

node* solve(node* first, node* second)
{

    // if only one element in first list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    node* curr1 = first;
    node* next1 = curr1->next;

    node* curr2 = second;
    node* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // add nodes in between the first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // curr1 and next1 ko aage badhana padega
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}
node* merge(node* first, node* second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    print(head);

    sortLinkedList(head);
    print(head);
    return 0;
}