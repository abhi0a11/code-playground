#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(), v.end());
    vector<int> start , end;
    for(auto [a,b]:v){
        start.push_back(b);
        end.push_back(a);
    }
    int i=1, j=0, ans = 1;
    while(i<n && j<n){
        if(start[i] >= end[j]){
            ans++;
            j = i;
        }
        i++;
    }
    cout<<ans;
    return 0;
}