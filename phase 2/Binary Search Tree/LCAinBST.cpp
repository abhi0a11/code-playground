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


// space O(N)
// node* LCAinBST(node* root, node* P,node* Q){
//     //base case
//     if(root == NULL)    return NULL;
    
//     if(root->data > P->data && root->data > Q->data){
//         return LCAinBST(root->right,P,Q);
//     }
//     if(root->data < P->data && root->data < Q->data){
//         return LCAinBST(root->left,P,Q);
//     }
    
//     return root;
// }

node* LCAinBST(node* root, node* P,node* Q){
    while(root != NULL){
        if(root->data > P->data && root->data > Q->data)
            root = root->right;
        else if(root->data < P->data && root->data < Q->data)
            root = root->left;
        else return root;
    }    
}

int main(){

    return 0;
}
// morris traversal use krke code krna h wapas
