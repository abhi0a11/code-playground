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

//predecessor -> left subtree ka maximum
//successor -> right subtree ka minimum

pair<int,int> predecessorSuccessor(node* root,int key){

    int pred = -1;
    int succ = -1;

    //key find
    node* temp = root;
    while(temp!= NULL || temp->data == key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        if(temp->data < key){
            pred = temp->data;
            temp = temp->right;
        }
    }

    //pred
    node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    //succ
    node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int,int> p = make_pair(pred,succ);
    return p;
}

int main(){

    return 0;
}
// morris traversal use krke code krna h wapas
