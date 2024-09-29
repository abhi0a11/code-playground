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

// ques add numbers of two lnked list
void add(node *head1, node *head2)
{
    int num1 = 0;
    int num2 = 0;
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != NULL)
    {
        num1 = num1 * 10 + temp1->data;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        num2 = num2 * 10 + temp2->data;
        temp2 = temp2->next;
    }
    num1 = num1 + num2;
    cout << endl << num1 << endl;
}
// ques add numbers of two lnked list and return new linked list representing addition of two linked list;
void reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
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

    head = prev;
}
node *addList(node *&head1, node *&head2)
{

    // step1 reverse linked list
    reverse(head1);
    reverse(head2);

    node *temp1 = head1;
    node *temp2 = head2;

    // step2 add linked list
    node *addListHead = NULL;
    node *addListTail = NULL;

    node *temp = addListHead;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (temp1 != NULL)
        {
            val1 = temp1->data;
        }
        int val2 = 0;
        if (temp2 != NULL)
        {
            val2 = temp2->data;
        }
        int sum = val1 + val2 + carry;
        int digit = sum % 10;

        insertAtTail(addListHead, addListTail, digit);
        carry = sum / 10;

        if (temp1 != NULL)
            temp1 = temp1->next;

        if (temp2 != NULL)
            temp2 = temp2->next;
    }

    // repeat step 1
    reverse(head1);
    reverse(head2);

    reverse(addListHead);

    return addListHead;
}
int main()
{

    node *head1 = NULL;
    node *tail1 = NULL;

    node *head2 = NULL;
    node *tail2 = NULL;

    
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 5);

    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 5);

    print(head1);
    print(head2);
    node *tempHead = addList(head1, head2);
    print(tempHead);

    return 0;
}