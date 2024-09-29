#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>& s,char ch){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if(ch == '+' )
            s.push(b+a);
        else if(ch == '-')
            s.push(b-a);
        else if(ch == '*')
            s.push(b*a);
        else if(ch == '/')
            s.push(b/a);
    }
    int evaluatePostfix(string S)
    {
        stack<int> s;
        
        for(int i=0; i<S.size(); i++){
            if(S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/'){
                solve(s,S[i]);
            }
            else{
                s.push(S[i] - '0');
            }
        }
        
        return s.top();
    }

int main(){
    
    return 0;
}