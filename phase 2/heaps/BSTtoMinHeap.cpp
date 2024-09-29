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

//if BST is already CBT and with condition that value at left of min heap will be greater than value at right

void inorder(node* tree, vector<int>& in){
    if(tree == NULL)    return;

    inorder(tree->left,in);
    in.push_back(tree->data);
    inorder(tree->right,in);
}
void preorder(node* tree, vector<int> in,int index){
    if(tree == NULL)    return;

    tree->data = in[index++];
    preorder(tree->left,in,index);
    preorder(tree->right,in,index);
}
void BSTtoHeap(node* tree){
    
    vector<int> in;
    inorder(tree,in);
    int index =0;
    preorder(tree,in, index);
}
int main(){
    
    return 0;
}