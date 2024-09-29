#include<bits/stdc++.h>
using namespace std;
int getRounds(vector<pair<int,int>>& arr,int s, int e){
    long ans = 1;
    int prev = arr[s].second;
    for(int i=s+1; i<=e; i++){
        int curr = arr[i].second;
        if(prev > curr){
            ans++;
        }
        prev = curr;
    }
    return ans;
}
int main(){
    int n,m; cin>>n>>m;
    vector<pair<int,int>> arr(n);
    vector<int> mp(n);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        arr[i] = {a,i};
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        int ind = arr[i].second;
        mp[ind] = i;
    }
    long ans = getRounds(arr,0,n-1);

    for(int i=0; i<m; i++){
        int ind1, ind2; cin>>ind1>>ind2;
        int i1 = mp[ind1-1];
        int i2 = mp[ind2-1];
        ans -= getRounds(arr,i1,i2);

        int x = arr[i1].second;
        int y = arr[i2].second;
        swap(x,y);
        arr[i1].second = x;
        arr[i2].second = y;
        swap(mp[ind1-1], mp[ind2-1]);

        ans += getRounds(arr,i1,i2); 
        cout<<ans<<endl;
    }
    return 0;
}