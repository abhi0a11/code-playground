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

node* inorderToBst(int s, int e, vector<int>& inorderval){
    //base case
    if(s>e) return NULL;
    
    int mid = s+ (e-s)/2;

    node* root = new node(inorderval[mid]);
    root->left = inorderToBst(s, mid-1, inorderval);
    root->right = inorderToBst(mid+1,e,inorderval);

    return root;
}

node* flatten(node* root){
    vector<int> inorderval;
    inorder(root,inorderval);

    return inorderToBst(0,inorderval.size()-1, inorderval);
}

int main(){

    return 0;
}

