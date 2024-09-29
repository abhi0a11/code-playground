#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
diameter of a tree: Longest path b/w any 2 end nodes(Leaf/ root nodes)
*/

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
// method 1

//height() has time complexity O(n) and diameter has TC O(n) so overall complexity becomes O(n^2) which is not good 

int height(node* root){
    if( root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root-> left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right); // height() has time complexity O(n) and diameter has TC O(n) so overall complexity becomes O(n^2) which is not good 

    int ans = max(op1,max(op2,op3));
    return ans;
}
*/
pair<int,int> diameterFast(node* root){
    //base case

    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root -> right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second , right.second) + 1;

    return ans;
}

int diameter(node* root){
    return (diameterFast(root).first);
}

int main(){
    
    return 0;
}