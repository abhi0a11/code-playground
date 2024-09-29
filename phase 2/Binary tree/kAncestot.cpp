#include <iostream>
#include <bits/stdc++.h>
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

node* solve(node* root, int &k, int Node)
{
    // base case
    if (root == NULL)
        return NULL;
    if (root->data == Node)
        return root;

    node* leftAns = solve(root->left, k, Node);
    node* rightAns = solve(root->right, k, Node);

    // wapas
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k<=0){
            // ans lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(node* root, int k, int Node){
    node* ans = solve(root,k,Node);
    if(ans == NULL ) return -1;
    else    return ans->data;
}
int main()
{

    return 0;
}