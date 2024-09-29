#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

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

// insertion
void insertNodeAtHead(node *&head, node *&tail, int d)
{

    node *temp = new node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertAtTail(node *&head, node *&tail, int d)
{
    node *temp = new node(d);

    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node *&head, node *&tail, int position, int d)
{
    // insertion at start
    if (position == 1)
    {
        insertNodeAtHead(head, tail, d);
        return;
    }

    node *curr = head;

    int cnt = 1;
    while (cnt < position - 1)
    {
        curr = curr->next;
        cnt++;
    }

    // insertion at tail
    if (curr->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    node *temp = new node(d);
    temp->next = curr->next;
    curr->next = temp;
}

// deletion

void deleteNode(int position, node *&head, node *&tail)
{
    // delete first or start node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // deleteing any middle node or last node
    else
    {
        node *previous = NULL;
        node *curr = head;

        int cnt = 1;
        while (cnt < position)
        {
            previous = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = previous;
        }
        previous->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertNodeAtHead(head, tail, 5);
    insertNodeAtHead(head, tail, 7);
    insertNodeAtHead(head, tail, 17);

    insertAtTail(head, tail, 24);
    insertAtTail(head, tail, 35);
    insertAtTail(head, tail, 36);

    
    insertAtPosition(head, tail, 5, 34);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;
    
    cout<<"linked list before deletion"<<endl;
    print(head);

    deleteNode(1, head,tail);

    cout<<"linked list after deletion"<<endl;

    print(head);

    return 0;
}