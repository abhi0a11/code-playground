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

node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans -> next;
    return ans;
}

node *mergeSort(node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // break linked list into two halves, after finding mid
    node *mid = findMid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    node *result = merge(left, right);

    return result;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertAtTail(head,tail,2);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,6);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,3);

    mergeSort(head);
    print(head);
    return 0;
}