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

pair<bool,int> isSumTreeFast(node* root){
    //base case

    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    //leaf node
    if( root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
    
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == (leftSum + rightSum);

    pair<bool,int> ans ;
    if(isLeftSumTree && isRightSumTree && condn){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else    ans.first = false;

return ans;
}

bool isSumTree(node* root){
    return isSumTreeFast(root).first;
}
int main(){
    
    return 0;
}