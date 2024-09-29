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

bool searchInBST(node* root, int key){
    node* temp = root;
    while(temp){
        if(root->data == key)   return true;

        if(root->data > key) temp = temp->left;
        if(root->data < key) temp = temp->right;

    }
    return false;

}

node* minValue(node* root){
    node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* maxValue(node* root){
    node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    return 0;
}

/*
HW

inorder predecessor
inorder successor
*/