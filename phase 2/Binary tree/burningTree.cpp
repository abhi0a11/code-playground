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

node* createParentMapping(node* root,int target,map<node*,node*>& nodeToParent){
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front->data == target)   res = front;
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

void burnTree(node* root, map<node*,node*>& nodeToParent,int &ans){
    map<node*,bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root] = true;


    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            bool flag=0;
            //process neightbpouring nodes
            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag =1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if(front->right && !visited[front->right]){
                flag =1;
                q.push(front->right);
                visited[front->right];
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag =1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
            if(flag == 1)   ans++;
        }
    }

}
int minTimme(node* root,int target){
    // algo
    // step 1: create nodeToparent mapping
    // step 2 : find target node
    // step 3: burn the tree in min time

    int ans =0;
    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root,target,nodeToParent);

    burnTree(targetNode,nodeToParent,ans);

    return ans;
}
int main(){
    
    return 0;
}