#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// void solve(string& s, int i,set<string>& st){
//     if(i == s.size()){
//         st.insert(s);
//         return ;
//     }

//     for(int ind = i; ind<s.size(); ind++){
//         swap(s[i],s[ind]);
//         solve(s,i+1,st);
//         swap(s[i],s[ind]);
//     }
// }
int main(){
    string s;
    cin>>s;
    set<string> st;
    sort(s.begin(),s.end());
    // solve(s,0,st);   
    // cout<<st.size()<<endl;
    // for(auto s:st)  cout<<s<<endl;
    do{
        st.insert(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<st.size()<<endl;
    for(auto s:st)  cout<<s<<endl;
    return 0;
}