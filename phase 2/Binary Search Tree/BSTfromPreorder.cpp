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

node* solve(vector<int> &preorder,long mini, long maxi,int &i){
    if(i >= preorder.size())    return NULL;
    if(preorder[i] < mini || preorder[i] > maxi)    return NULL;

    node* root = new node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder,root->data,maxi,i);

    return root;
}

node* preorderToBST(vector<int> &preorder){
    long mini = LONG_MIN;
    long maxi = LONG_MAX;
    int index =0;
    node* root = solve(preorder,mini,maxi,index);
    return root;
}

int main(){
    
    return 0;
}

