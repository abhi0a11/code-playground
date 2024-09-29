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
void inorder(node* root, vector<int>& inorderval){
    if(root = NULL) return ;

    inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    inorder(root->right,inorderval);

}

node* flatten(node* root){
    vector<int> inorderval;
    inorder(root,inorderval);
    int n = inorderval.size();
    node* newRoot = new node(inorderval[0]);

    node* curr = newRoot;

    for(int i=1; i<n; i++){
        node* temp = new node(inorderval[i]);

        curr->right = temp;
        curr->left == NULL;
        curr = temp;
    }
    
    curr->left = curr->right = NULL;
    return newRoot;

}
int main(){

    return 0;
}

