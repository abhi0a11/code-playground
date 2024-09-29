#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;cin>>q;
    while(q--){
        int k;cin>>k;

        if(k<9){
            cout<<k<<endl;
        }
        else{
            int n = (k-10)/20 + 1;
            int st = 10 + (n-1)*20;

            int val = k-st;

            if(val&1){ // odd
                val--;
                cout<<val/2<<endl;
            }
            else{
                cout<<n<<endl;
            }
        }
    }
    return 0;
}