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

int height(node* node){
    if(node == NULL)    return 0;

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left,right) + 1;
    return ans;
}


int main(){
    
    return 0;
}