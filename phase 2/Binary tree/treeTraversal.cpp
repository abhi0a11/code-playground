#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<" Enter the data" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if( data == -1){
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inOrder(node *root){
    if(root == NULL){
        return ;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right); 
}

void preOrder(node* root){
    if( root == NULL){
        return;
    }
    
    cout<< root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if( root == NULL){
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<" ";
}
int main(){
    node* root = NULL;

    root = buildTree(root);
    cout << "Printing inOrder traversal: ";
    inOrder(root);
    cout<<endl;
    cout << "Printing preOrder traversal: ";
    preOrder(root);
    cout<<endl;
    cout << "Printing postorder traversal: ";
    postOrder(root);
    return 0;
}