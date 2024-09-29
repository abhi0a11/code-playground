#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // cinstructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << val << endl;
    }
};

void insertNode(node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // non empty list
        // assuming that the element is present in the list

        node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(node *tail)
{
    node *temp = tail;

    if (tail == NULL)
    {
        cout << "the list is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(node *&tail, int element)
{
    // empty list
    if (tail == NULL)
    {
        cout << "the list is empty, check again" << endl;
        return;
    }
    else
    {
        // non-empty list

        // assuming the element is present in the list
        node *prev = tail;
        node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // if only 1 node in linked list
        if (prev == curr)
        {
            tail = NULL;
        }

        //>=2 node linked list
        if (tail == curr)
        {
            tail = curr->next;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool detectLoop(node *head)
{
    if (head == NULL)
        return false;
    node *temp = head;

    map<node *, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

node* floydDetectLoop(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;
        if (slow == fast)
        {
            
            return slow;
        }
    }
    return NULL;
}
int main()
{
    node *tail = NULL;

    // empty list me insert krrhe hai
    insertNode(tail, 5, 3);
    // print(tail);

    insertNode(tail, 3, 5);
    // print(tail);

    insertNode(tail, 5, 7);
    // print(tail);

    insertNode(tail, 7, 9);
    // print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    // deleteNode(tail, 5);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    // deleteNode(tail,9);
    // print(tail);

    // if (detectLoop(tail))
    // {
    //     cout << "Cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "no cycle" << endl;
    // }

        if (floydDetectLoop(tail) != NULL)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }
    return 0;
}