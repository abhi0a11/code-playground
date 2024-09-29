#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        arr[i] = {a,i};
    }
    sort(arr.begin(), arr.end());
    long ans = 1;
    int prev = arr[0].second;
    for(int i=1; i<n; i++){
        int curr = arr[i].second;
        if(prev > curr){
            ans++;
        }
        prev = curr;
    }
    cout<<ans;
    return 0;
}