struct Node{
    Node* links[26];
    bool flag = false;
    int count = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool isEnd(){
        return flag;
    }
    int getCount(){
        return count;
    }
    void incr(){
        count++;
    }
};
class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void build(string& s){
        Node* node = root;
        for(auto ch:s){
            if(!node->containsKey(ch)){
                node -> put(ch,new Node());
            }
            node = node->get(ch);
            node ->incr();
        }
        node->setEnd();
    }

    string getPref(string& s, int n){
        string ans = "";
        Node* node = root;
        for(auto ch:s){
            node = node->get(ch);
            
            if(node->getCount() == n){
                ans += ch;
            }
            else break;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto word:strs) trie.build(word);
        return trie.getPref(strs[0],strs.size());
    }
};