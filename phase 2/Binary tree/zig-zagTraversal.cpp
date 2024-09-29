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

vector<int> zigZagTraversal(node* root){
    queue<node*> q;
    vector<int> result;
    
    if(root == NULL)    return result;

    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        for(int i=0; i<size; i++){
            node* frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode->data;

            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);

        }

        // direction change
        leftToRight = !leftToRight;

        //store ans
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}
int main()
{

    return 0;
}

