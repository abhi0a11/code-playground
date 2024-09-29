#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void convertIntoSortedDLL(node* root, node* &head){
    if(root == NULL)    return;

    convertIntoSortedDLL(root->right,head);

    root->right = head;
    if(head)    head->left = root;
    head = root;

    convertIntoSortedDLL(root->left,head);
}
int main(){
    
    return 0;
}