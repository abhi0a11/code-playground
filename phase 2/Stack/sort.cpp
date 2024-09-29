#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>&s,int num){
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }

    int val = s.top();
    s.pop();

    sortedInsert(s, num);
    s.push(val);

}


void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    sortStack(s);

    sortedInsert(s,num);
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(10);
    s.push(9);
    s.push(4);
    s.push(8);
    s.push(-2);
    s.push(-7);

    print(s);
    sortStack(s);
    print(s);
    return 0;
}