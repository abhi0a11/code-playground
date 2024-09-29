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

bool twoSumInNST(node* root, int target){
    vector<int> inorderval;
    inorder(root,inorderval);

    int i=0,j=inorderval.size()-1;

    while(i<j){
        int sum = inorderval[i] + inorderval[j];
        if(sum == target)   return true;
        else if(sum < target)    i++;
        else   j--;
    }
    return false;
}

int main(){

    return 0;
}

