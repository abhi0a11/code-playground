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

node* insertIntoBST(node* root, int d){
    //base case

    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        //right part me insert krna hai
        root->right = insertIntoBST(root->right,d);
    }
    else{
        //left part me insert krna hai
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}
void levelOrderTRaversersal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // to separate each level
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // purana level complete traverse ho chuka h
            cout << endl;
            if (!q.empty())
            { // queue still has child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)q.push(temp->left);
            if (temp->right)q.push(temp->right);
        }
    }
}

void inOrder(node *root){
    if(root == NULL){
        return ;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right); 
}

void preOrder(node* root){
    if( root == NULL){
        return;
    }
    
    cout<< root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root){
    if( root == NULL){
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<" ";
}
int main(){
    
    node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTRaversersal(root);
    

    cout << "Printing inOrder traversal: ";
    inOrder(root);
    cout<<endl;
    cout << "Printing preOrder traversal: ";
    preOrder(root);
    cout<<endl;
    cout << "Printing postorder traversal: ";
    postOrder(root);
    return 0;
}