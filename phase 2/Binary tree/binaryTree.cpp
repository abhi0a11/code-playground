#include <iostream>
#include <bits/stdc++.h>

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

node *buildTree(node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting data in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
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
        }set
        else
        {
            cout << temp->data << " ";
            if (temp->left)q.push(temp->left);
            if (temp->right)q.push(temp->right);
        }
    }
}


int main()
{

    node *root = NULL;

    // creating a tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Printing level order traversal" << endl;
    levelOrderTRaversersal(root);

    return 0;
}

// reverse level order traversal 