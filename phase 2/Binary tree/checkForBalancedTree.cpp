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
/*
int height(node* root){
    if(root == NULL)    return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

bool isBalanced(node* root){
    //base case
    if(root == NULL)    return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if( left && right && diff)  return true;
    else    return false;
}
 */

pair<bool,int> isBalancedFast(node* root){
    //base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = isBalancedFast(root->left);
    pair<bool,int> right = isBalancedFast(root->right);


    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    
    //height
    ans.second = max(left.second,right.second) + 1;

    if( leftAns && rightAns && diff)  ans.first = 1;
    else    ans.first = false;

    return ans;
}

bool isBalanced(node* root){
    return isBalancedFast(root).first;
}


int main(){
    cout<<ss();
    return 0;
}

