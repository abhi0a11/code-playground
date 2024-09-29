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
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main(){
    node* root = NULL;

    buildFromLevelOrder(root);

    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTRaversersal(root);
    return 0;
}