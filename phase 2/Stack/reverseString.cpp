#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main()
{

    string str = "abhishek";
    stack<char> s;

    // for (int i = 0; i< str.size(); i++){
    for (auto i: str){
        s.push(i);
    }

    string ans ="";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    cout<<ans<<endl;
        return 0;
}