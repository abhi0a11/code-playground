#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *links[26];
    bool flag = false;
    int count = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
    void incr(){
        count++;
    }
    int cnt(){
        return count;
    }
};

class trie{
    Node* root;
public:
    trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]);
            node->incr();
        }
        node->setEnd();
    }

    int getPrefCount(string word){
        int c = 0;
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            node = node->get(word[i]);
            c += node->cnt();
        }
        return c;
    }
};

    vector<int> sumPrefixScores(vector<string>& words) {
        trie t;
        
        int n = words.size();
        vector<int> ans;
        int k=0;
        
        for(auto &&s:words){
            t.insert(s);
        }
        for(auto &&s:words){
            ans.push_back(t.getPrefCount(s));
        }
        return ans;
    }

int main(){
    vector<string> words ={"abc","ab","bc","b"};
    vector<int> ans = sumPrefixScores(words);

    for(auto i:ans) cout<<i<<" ";cout<<endl;
    return 0;
}