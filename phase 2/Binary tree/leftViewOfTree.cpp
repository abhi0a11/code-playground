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
        this->left= NULL;
        this->right= NULL;
    }
};
void solve(node* root, vector<int>&ans, int level){
    //base case
    if(root == NULL)    return;

    if(level == ans.size())    ans.push_back(root->data);

    //left tree
    solve(root->left,ans,level+1);
    //right tree
    solve(root->right,ans,level+1);
}

vector<int> leftView(node* root){
    vector<int> ans ;
    int level =0;

    solve(root,ans,level);
    return ans;
}
int main(){
    
    return 0;
}

// make recursive tree