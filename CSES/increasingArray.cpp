#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long ans=0;
    int prev = -1;
    for(int i=0; i<n; i++){
        if(prev == -1){
            cin>>prev;
        }
        else{
            int val ;
            cin>>val;
            if(prev>val){
                ans += prev-val;
            }
            else{
                prev = val;
            }
        }
    }   
    cout<<ans;
    return 0;
}