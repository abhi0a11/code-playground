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

//give a try

vector<int> inorderMorrisTraversal(node* root){
    vector<int> ans;
        node* curr = root;
        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            
            else{
                node* prev = curr->left;
                while(prev->right && prev ->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
}

int main(){
    
    return 0;
}