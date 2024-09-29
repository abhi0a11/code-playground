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

class info{

public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(node* root, int& ans){
    // base case 
    if(root == NULL){
        return {INT_MIN,INT_MAX, true, 0};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currentNode;

    currentNode.size = left.size + right.size + 1;
    currentNode.maxi = max(root->data,right.maxi);
    currentNode.mini = min(root->data,left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currentNode.isBST = true;
    }
    else    currentNode.isBST = false;


    //answer update
    if(currentNode.isBST){
        ans = max(ans,currentNode.size);
    }
    return currentNode;
}

int largestBST(node* root){
    int maxSize =0;
    info temp = solve(root,maxSize);
    return maxSize;
}

int main(){
    
    return 0;
}