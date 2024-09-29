#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;
    int cntEndWith=0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    
    void incrPref(){
        cntPrefix++;
    }
    void incrEnd(){
        cntEndWith++;
    }
    int getPrefCount(){
        return cntPrefix;
    }
    int getEndCount(){
        return cntEndWith;
    }
    void delEnd(){
        cntEndWith--;
    }
    void decPrefix(){
        cntPrefix--;
    }
};
class Trie{
    Node* root;
    public:

    Trie(){
       root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(auto &&i:word){
            if(!node->containsKey(i)){
                node -> put(i,new Node());
            }   
            node = node->get(i);
            node->incrPref();
        }
        node->incrEnd();
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(auto &&i:word){
            if(!node->containsKey(i))   {
                return 0;
            }
            node = node->get(i);
        }
        return node->getEndCount();
    }

    int countWordsStartingWith(string &word){
       Node* node = root;
        for(auto &&i:word){
            if(!node->containsKey(i))   {
                return 0;
            }
            node = node->get(i);
        }
        return node->getPrefCount();
    }

    void erase(string &word){
        Node* node = root;
        for(auto &&i:word){
            if(!node->containsKey(i))   {
                return ;
            }
            node = node->get(i);
            node->decPrefix();
            node->delEnd();
        }
    }
};

int main(){
    return 0;
}