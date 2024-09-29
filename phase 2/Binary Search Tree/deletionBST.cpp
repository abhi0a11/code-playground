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
node* deleteFromBst(node* root,int val){
    if(root == NULL)    return root;

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child

        if(root->left && root->right){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBst(root->right, mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBst(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right,val);
        return root;
    }
}
int main(){
    return 0;
}