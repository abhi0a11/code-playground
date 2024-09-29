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
int solve(node* root, int k,int& i){
    if(root == NULL)    return -1;

    int left = solve(root->left,k,i);
    
    //left
    if(left != -1){
        return left;
    }

    //node
    i++;
    if(i==k){
        return root->data;
    }

    //right
    return solve(root->right,k,i);

}
int kthSmallest(node* root, int k){
    int i=0;
    int ans = solve(root,k,i);
    return ans;
}
int main(){

    return 0;
}
// morris traversal use krke code krna h wapas
