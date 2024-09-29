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

void insertAtTail(node *&endingNode, int d)
{
    node *temp = new node(d);
    endingNode->next = temp;
    endingNode = endingNode->next;
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
            cout << "present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

node *floydDetectLoop(node *head)
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

node *getStartingNode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    node *intersection = floydDetectLoop(head);
    node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}
void removeLoop(node *head)
{
    if (head == NULL)
    {
        return;
    }

    node *startingNode = getStartingNode(head);
    node *slow = startingNode;

    while (slow->next != startingNode)
    {
        slow = slow->next;
    }
    slow->next = NULL;
    cout << "Loop is removed" << endl;
    return;
}
int main()
{
    node *node1 = new node(5);

    node *head = node1;
    node *tail = node1;

    insertAtTail(tail, 10);
    insertAtTail(tail, 19);
    insertAtTail(tail, 15);
    tail->next = head->next->next;

    // if (detectLoop(head))
    // {
    //     cout << "Cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "no cycle" << endl;
    // }
    // print(head);

    if (floydDetectLoop(head) != NULL)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    node *loop = getStartingNode(head);

    cout << "starting at " << loop->data << endl;

    removeLoop(head);

    print(head);
    return 0;
}