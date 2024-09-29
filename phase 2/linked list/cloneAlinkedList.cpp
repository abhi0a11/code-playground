#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *random;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }
};

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

node *copyList(node *head)
{
    node *cloneHead = NULL;
    node *cloneTail = NULL;

    node *temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, (temp->data));
        temp = temp->next;
    }

    // step2 create a map
    unordered_map<node *, node *> oldToNewNode;

    node *originalNode = head;
    node *cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneHead->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL)
    {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneHead = cloneHead->next;
    }
    return cloneHead;
}
int main()
{

    return 0;
}