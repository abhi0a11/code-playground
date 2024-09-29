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

bool isBst(node* root, long min, long max){
    //base case
    if(root == NULL)    return true;

    if(root->data > min && root->data < max){
        bool left = isBst(root->left, min,root->data);
        bool right = isBst(root->right, root->data,max);

        return left && right;
    }
    else return false;
}

bool isValid(node* root)
{
    return isBst(root,LONG_MIN,LONG_MAX);
}
int main(){
    return 0;
}