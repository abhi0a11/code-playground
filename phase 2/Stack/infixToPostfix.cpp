#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void stackPush(stack<pair<char,int>>& s, string& ans,char ch){
        switch(ch){
            case '(':
                s.push({'(',0});
            break;
            case ')':
                while(!s.empty() && s.top().first != '('){
                    ans.push_back(s.top().first);
                    s.pop();
                }
                s.pop();
            break;
            case '+':
                while(!s.empty() && s.top().first != '(' && s.top().second >= 1){
                    ans.push_back(s.top().first);
                    s.pop();
                }
                s.push({'+',1});
            break;
            case '-':
                while(!s.empty() && s.top().first != '(' && s.top().second >= 1){
                    ans.push_back(s.top().first);
                    s.pop();
                }
                s.push({'-',1});
            break;
            case '*':
                while(!s.empty() && s.top().first != '(' && s.top().second >= 2){
                    ans.push_back(s.top().first);
                    s.pop();
                }
                s.push({'*',2});
            break;
                
            case '/':
                while(!s.empty() && s.top().first != '(' && s.top().second >= 2){
                    ans.push_back(s.top().first);
                    s.pop();
                }
                s.push({'/',2});
            break;
                
            case '^':
                while(!s.empty() && s.top().first != '(' && s.top().second >= 3){
                    ans.push_back(s.top().first);
                    s.pop();
                }
                s.push({'^',3});
            break;
        }
    }
    
    string infixToPostfix(string s) {
        string ans;
        stack<pair<char,int> > st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '+' || s[i] == '/' || s[i] == '-'|| s[i] == '*' || s[i] == '^' ||
                s[i] == '(' || s[i] == ')'){
                stackPush(st,ans,s[i]);
            }
            
            else{
                ans.push_back(s[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        return ans;
    }

int main(){
    
    return 0;
}