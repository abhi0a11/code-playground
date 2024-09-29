#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertNodeAtTail(node *&head, node *&tail, int d)
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

/*
// iterative method
node *reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
*/

// recurrsive method 1
/*
void reversByRecurrsion(node *&head, node *curr, node *prev)
{

    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    node *forward = curr->next;
    reversByRecurrsion(head, forward, curr);
    curr->next = prev;
}

node *reverseLL(node *head)
{
    node *curr = head;
    node *prev = NULL;
    reversByRecurrsion(head, curr, prev);
    return head;
}
*/

// method 2 recursive

// it will return head of reverse list
node *reverse1(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *chotaHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

int getLength(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

int findMiddle(node *head)
{
    // empty or 1 node
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }

    // if 2 nodes
    if (head->next->next == NULL)
    {
        return (head->next->data);
    }

    node *fast = head->next;
    node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data;

    /*
    int len = getLength(head);

    int middle = (len/2) +1;

    node* middlePointer = head;

    int cnt =0;
    while(cnt != middle-1){
        middlePointer = middlePointer-> next;
        cnt++;
    }
    return (middlePointer->data);
    */
}

node *reverseInKgoups(node *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // step1: rerse k nodes
    node *forward = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step2: recursion dekhlega aage ka
    if (forward != NULL)
    {
        head->next = reverseInKgoups(forward, k);
    }

    // step3: return head of reversed list
    return prev;
}

void print(node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isCircular(node *head)
{
    if (head == NULL)
    {
        return true;
    }
    node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }
    return false;
}
int main()
{
    node *node1 = new node(3);

    node *head = node1;
    node *tail = NULL;

    insertNodeAtTail(head, tail, 5);
    insertNodeAtTail(head, tail, 7);
    insertNodeAtTail(head, tail, 9);
    insertNodeAtTail(head, tail, 11);
    insertNodeAtTail(head, tail, 13);
    insertNodeAtTail(head, tail, 55);
    insertNodeAtTail(head, tail, 74);
    insertNodeAtTail(head, tail, 19);
    insertNodeAtTail(head, tail, 61);
    insertNodeAtTail(head, tail, 18);

    // node *reverseHead = reverse(head);
    // print(reverseHead);

    // node *reverseHead = reverseLL(head);
    // print(reverseHead);

    // print(reverse1(head));

    // print(head);
    // cout << findMiddle(head);

    // print(head);
    // print(reverseInKgoups(head,3));

    print(head);

    if (isCircular(tail))
    {
        cout << "Linked list is Circular in nature" << endl;
    }
    else
        cout << "linked list is not cirrcular in nature" << endl;

    return 0;
}