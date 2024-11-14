#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int key = 0;
    int val = 0;

    TreeNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode* iterativeDelete(TreeNode*& root, int k) {
    // Current pointer to iterate
    TreeNode* stat = root;

    // One previous pointer from current
    TreeNode* prev = NULL;

    /*
        Iterating in binary search tree to check if the key with k
        key is actually present there or not
    */
    while (stat != NULL && stat->key != k) {
        prev = stat;
        if (k < stat->key)
            stat = stat->left;
        else
            stat = stat->right;
    }

    if (stat == NULL) {
        cout << "k not found in BST" << endl;
        return root;
    }

    // Check if the node to be deleted has either 0 or 1 child
    if (stat->left == NULL || stat->right == NULL) {

        // newtreenode with store the node to be deleted
        TreeNode* newtreenode;

        // check whether the node to be deleted has either 0 or 1 child
        if (stat->left == NULL)
            newtreenode = stat->right;
        else
            newtreenode = stat->left;

        /*
            check whether the node to be deleted is the root then simply return newtreenode
        */
        if (prev == NULL)
            return newtreenode;
        /*
            check the node to be deleted  is whether the previous nodes left or right and
            replace it with the newtreenode
        */
        if (stat == prev->left)
            prev->left = newtreenode;
        else
            prev->right = newtreenode;

        // simply delete the node
        delete stat;
    }

    // here node which has to be deleted has 2 child nodes
    else {
        TreeNode* prev = NULL;
        TreeNode* temp;

        // finding the inorder successor in case of node with 2 child nodes
        temp = stat->right;
        while (temp->left != NULL)
        {
            prev = temp;
            temp = temp->left;
        }

        /*
            before replacing the k check if the parent node of the inorder successor
            is the current node or not if it is not then make the left child of the parent
            equal to the inorder successor of the right child else if inorder successor was
            itself  the current then make the right child of the node to be deleted equal
            To the right child of inorder successor
        */
        prev != NULL ? prev->left = temp->right : stat->right = temp->right;

        stat->key = temp->key;
        delete temp;
    }
    return root;
}


int main() {

    return 0;
}