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

int countNodes(node* root){
    //base case
    if(root == NULL)    return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(node* root, int index, int cnt){
    if(root == NULL)    return true;
    
    if(index >= cnt)    return false;
    else{
        bool left = isCBT(root->left, 2*index+1,cnt);
        bool right = isCBT(root->right, 2*index+2,cnt);
        return left && right;
    }

}

bool isMaxOrder(node* root){

    //leaf node
    if(root == NULL || (!root->left && !root->right)){
        return true;
    }
    //left child
    else if(!root->right){
        if(root->data > root->left->data){
            return true;
        }
        else    return false;
    }
    // two child
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

       return (left && right && root->data > root->left->data && root->data > root->right->data);
    }

}

bool isHeap(node* tree){
    int count = countNodes(tree);
    int index =0;
    if(isCBT(tree,index,count) && isMaxOrder(tree)){
        return true;
    }
    else    return false; 
}
int main(){
    
    return 0;
}