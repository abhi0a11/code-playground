#include<iostream>
#include<bits/stdc++.h>
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

};


class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

node* mergeKLists(vector<node*>& listArray) {
    priority_queue<node*, vector<node*>, compare > minHeap;

    int k = listArray.size();
    //step1
    if (k == 0)    return NULL;

    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    node* head = NULL;
    node* tail = NULL;

    while (minHeap.size() > 0) {
        node* top = minHeap.top();
        minHeap.pop();

        if (top->next != NULL) {
            minHeap.push(top->next);
        }
        if (head == NULL) {
            head = top;
            tail = top;
        }
        else {
            tail->next = top;
            tail = top;
        }
    }


    return head;
}
int main() {

    return 0;
}