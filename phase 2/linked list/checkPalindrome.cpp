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
bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
// bool isPalindrome(node *head)
// {
//     // method 1

//     vector<int> arr;

//     node *temp = head;

//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     return checkPalindrome(arr);
// }

// method 2 optimised

// node *getMid(node *head)
// {
//     node *slow = head;
//     node *fast = head->next;

//     while (fast != NULL && fast->next != NULL)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }
node *getMid(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    
    return slow; 
}
node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // step 1 -> find middle
    node *middle = getMid(head);

    // step2 -> reverse list after middle
    node *temp = middle->next;
    middle->next = reverse(temp);

    // step3 -> compare both halves
    node *head1 = head;
    node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step4 ->repeat step 2
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main()
{
    node* head = NULL;
    node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);

node* mid = getMid(head);
    print(mid);
    return 0;
}