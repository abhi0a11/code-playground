#include<iostream>
#include<bits/stdc++.h>
 
#include <algorithm>

using namespace std;

int main(){
    int n;cin>>n;
    
    for(int i=0; i<(1<<n); i++){
        int num = i ^ (i>>1);
        for(int i=0; i<n; i++){
            cout<<((num>>i)&1);
        }cout<<endl;
    }
    
    return 0;
}