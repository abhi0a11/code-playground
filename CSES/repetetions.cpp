#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans = INT_MIN;
    int i=0;
    int n = s.size();
    while(i<n){
        char ch = s[i];
        int j = i;
        int len = 0;
        while(j<n && s[j] == ch){
            len++;
            j++;
        }
        ans = max(ans,len);
        i=j;
    }   
    cout<<ans;
    return 0;
}