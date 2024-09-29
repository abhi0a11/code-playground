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

/*
approach #1 

time complexity O(m+n)
space complexity O(m+n)


void inorder(node* root, vector<int>& inorderval){
    if(root = NULL) return ;

    inorder(root->left,inorderval);
    inorderval.push_back(root->data);
    inorder(root->right,inorderval);
}
void mergeArray(vector<int>& bst1, vector<int>& bst2,vector<int>&bst3){
    int n = bst1.size();
    int m = bst2.size();
    int i =0,j=0;
    while(i<n && j<m){
        if(bst1[i] >= bst2[j]){
            bst3.push_back(bst2[j]);
            j++;
        }
        else {
            bst3.push_back(bst1[i]);
            i++;
        }
    }
    while(i<n){
        bst3.push_back(bst1[i]);
        i++;
    }
    while(j<m){
        bst3.push_back(bst2[j]);
        j++;
    }
}
node* inorderToBst(int s, int e, vector<int>& inorderval){
    //base case
    if(s>e) return NULL;
    
    int mid = s+ (e-s)/2;

    node* root = new node(inorderval[mid]);
    root->left = inorderToBst(s, mid-1, inorderval);
    root->right = inorderToBst(mid+1,e,inorderval);

    return root;
node* mergeBST(node* root1, node* root2){
    vector<int> bst1,bst2,bst3;
    // step 1: store inorder
    inorder(root1,bst1);
    inorder(root2,bst2);

    //step2: merge in sorted way;
    mergeArray(bst1,bst2,bst3);

    //step3: inoredrtobst()

    return inorderToBst(0,bst3.size()-1,bst3);
}
}
*/

/*
approach #2 
time complexity O(m+n)
space complexity O(h1+h2)
*/

void convertIntoSortedDLL(node* root, node* &head){
    if(head == NULL)    return;

    convertIntoSortedDLL(root->right,head);

    root->right = head;
    if(head)    head->left = root;
    
    head = root;
    
    convertIntoSortedDLL(root->left,head);
    
}

node* mergeLL(node* head1,node* head2){
    node* head = NULL;
    node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
}
int countNodes(node* head){
    int count =0;
    node* temp = head;
    while(temp){
        count++;
        temp = temp->right;
    }
    return count;
}
node* sortedLLtoBST(node* &head, int n){
    //base case
    if(n <= 0 || head == NULL)  return NULL;

    node* left = sortedLLtoBST(head,n/2);

    node* root = head;
    root->left = head;

    head = head->right;

    root->right = sortedLLtoBST(head,n-n/2-1);
    return root;

}
node* mergeBST(node* root1, node* root2){
    // step1: convert bst to sorted doubly linked list in-place
    node* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    node* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;

    // step2: merge two sorted DLL into one
    node* head = mergeLL(head1,head2);

    // step3: sorted LL to BST

    return sortedLLtoBST(head,countNodes(head));
}



int main(){
    /*
    algo #1
    step1: inorder of bst1 ans bst2
    step2: merge sorted inorder arrays
    step3: inorderToBST()
    */
    /*
    algo #2
    step1: convert bst to DLL
    step2: merge two sorted DLL into one
    step3: sorted LL to BST
    */


    return 0;
}

