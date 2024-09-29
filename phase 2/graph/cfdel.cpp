#include<bits/stdc++.h>
using namespace std;
int solve(int n, vector<int>& p, vector<int>& vis, int i){
    if(i >= n){
        return 1e5;
    }

    int notpick = solve(n,p,vis,i+1);
    
    vis[i] = 1;
    vis[p[i]-1] = 1;
    int pick = 2 + solve(n,p,vis,p[i]);
    vis[i] = 0;
    vis[p[i]-1] = 0;

    return min(pick,notpick);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> p(n);
        for(int i=0; i<n; i++){
            cin>>p[i];
        }
        vector<int> vis(n,0);
        cout<<solve(n,p,vis,0)<<endl;
    }   
    return 0;
}