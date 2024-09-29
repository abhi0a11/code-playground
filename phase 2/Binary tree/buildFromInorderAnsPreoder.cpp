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
node* solve(int in[],int pre[], int &index, int inorderStart,int inorderEnd,int n,map<int,int>& nodesToIndex){
    //base case
    if(index >= n || inorderStart > inorderEnd)  return NULL;

    //create a root node for element
    int element = pre[index++];
    node* root = new node(element);

    //find elements index in inorder
    int position = nodesToIndex[element];

    //recursive calls
    root->left = solve(in,pre,index,inorderStart,position-1,n,nodesToIndex);
    root->right = solve(in,pre,index,position+1,inorderEnd,n,nodesToIndex);

    return root;
}

node* buildTree(int in[], int pre[], int n){
    int preOrderIndex = 0;
    map<int,int> nodesToIndex;
    createMap(in,n,nodesToIndex);
    node* ans = solve(in,pre,preOrderIndex,0,n-1,n,nodesToIndex);
    return ans;
}

int main(){
    
    return 0;
}