#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long isValid(long num){
    long cnt = 0;
    while(num>0 && num%10 == 0){
        cnt++;
        num /= 10;
    }
    return cnt;
}
int main(){
    long n,m;
    cin>>n>>m;

    long ans = 0,cnt = 0;
    long e = n*m;


    while( n <= e && n%10 != 0){
        n++;
    }
    ans = max(ans,n);

    while(n <= e){
        if(cnt <= isValid(n)){
            cnt = max(isValid(n),cnt);
            ans = max(ans,n);
        }
        n+=10;
    }

    cout<<ans;
    return 0;
}