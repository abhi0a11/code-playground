#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    vector<int> c(26);
    for(auto ch:s){
        c[ch-'A']++;
    }
    int cnt = 0;
    for(int i=0; i<26; i++){
        if(c[i]>0 && c[i]%2 == 1){
            cnt++;
        }
    }
    if(cnt>1){
        cout<<"NO SOLUTION";
        return 0;
    }

    string ans = "";
    string od="";

    for(int i=0; i<26; i++){
        if(c[i]>0 && c[i]%2 == 0){
            int freq = c[i]/2;
            while(freq--)   ans += 'A'+i;
        }
        else if(c[i]>0 && c[i]%2 == 1){
            while(c[i]--){
                od+='A'+i;
            }
        }
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    cout<<ans+od+rev;

    return 0;
}