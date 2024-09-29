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

void createMap(int in[],int n,map<int,int>& nodesToIndex){
    for(int i=0; i<n; i++){
        nodesToIndex[in[i]] = i;
    }
}
node* solve(int in[],int post[], int &index, int inorderStart,int inorderEnd,int n,map<int,int>& nodesToIndex){
    //base case
    if(index >= 0 || inorderStart > inorderEnd)  return NULL;

    //create a root node for element
    int element = post[index--];
    node* root = new node(element);

    //find elements index in inorder
    int position = nodesToIndex[element];

    //recursive calls[in case of postorder ans inorder we build right subtree first]
    root->right = solve(in,post,index,position+1,inorderEnd,n,nodesToIndex);
    root->left = solve(in,post,index,inorderStart,position-1,n,nodesToIndex);

    return root;
}

node* buildTree(int in[], int post[], int n){
    int postOrderIndex = n-1;

    map<int,int> nodesToIndex;
    createMap(in,n,nodesToIndex);

    node* ans = solve(in,post,postOrderIndex,0,n-1,n,nodesToIndex);
    return ans;
}

int main(){
    
    return 0;
}