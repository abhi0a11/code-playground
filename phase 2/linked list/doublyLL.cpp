#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

// printing a lik=nked list
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// printing length of a linked list
int getLength(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(node *&head, node *&tail, int d)
{
    // if empty list
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(node *&head, node *&tail, int d)
{
    // emply list
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(node *&head, node *&tail, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        // if empty list
        if (head == NULL)
        {
            node *temp = new node(d);
            head = temp;
        }
        else
        {
            node *temp = new node(d);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < position)
    {
        temp = temp->next;
        cnt++;
    }

    // inseert at tail
    if (temp->next == NULL)
    {
        if (tail == NULL)
        {
            node *temp = new node(d);
            tail = temp;
            head = temp;
        }
        else
        {
            node *temp = new node(d);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            return;
        }
    }
    node *curr = new node(d);

    curr->next = temp->next;
    temp->next->prev = curr;
    curr->prev = temp;
    temp->next = curr;
}

void deleteNode(node *&head, node *&tail, int position)
{
    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }

    else
    {
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position )
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            curr->prev = NULL;
            prev->next = NULL;
            delete curr;
            return;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        prev->next->prev = prev;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    // cout << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 3);
    print(head);

    insertAtHead(head, tail, 15);
    print(head);

    insertAtHead(head, tail, 88);
    print(head);

    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 4, 23);
    print(head);

    insertAtPosition(head, tail, 1, 223);
    print(head);

    insertAtPosition(head, tail, 8, 123);
    print(head);

    deleteNode(head, tail, 8);
    print(head);

    return 0;
}