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

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    int data;
    cout<<"Enter the data for root"<<endl;
    cin>>data;

    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<< "Enter left node for: "<< temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout<< "Enter right node for "<< temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inOrder(node *root,int &cnt){
    if(root == NULL){
        return ;
    }
    
    inOrder(root->left,cnt);

    //leaf node
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }

    inOrder(root->right,cnt);
}
int noOfLeafNode(node* root){
    int cnt = 0;

    inOrder(root,cnt);
    return cnt;
}

int main(){
    
    return 0;
}