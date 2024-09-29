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

void flatten(node* root){
    node* curr = root;
    while(curr != NULL){
        if(curr->left){
            node* pred = curr->left;
            while(pred->right)  pred = pred->right;

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->left;
    }
}
int main(){
    
    return 0;
}