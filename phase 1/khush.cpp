#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        vector<ll> v(n);
        for (auto& i : v) cin >> i;
        vector<ll> query(q);
        for (auto& i : query)   cin >> i;

        map<ll, ll> mp;

        for (ll i = 0; i < n; i++) {
            ll segment = ((n - i) * i + (n - i - 1));
            mp[segment]++;
        }
        for (ll i = 0; i < n - 1; i++) {
            ll range = v[i + 1] - v[i] - 1;
            ll segment = ((n - i - 1) * i + (n - i - 1));
            mp[segment] += range;
        }

        for (auto k : query) {
            cout << mp[k] << " ";
        }
        cout << endl;
    }

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// bool isPossible(ll mid, vector<ll> v){
//     priority_queue<ll> pq, pq1;
//     for(auto el:v)  pq.push(el);
//     ll del = 0;
//     while(!pq.empty()){
//         ll mini = v[mid-1+del];
//         for(int i=0; i<mid; i++){
//             ll val = pq.top();
//             pq.pop();
//             if(val-mini > 0)
//                 pq1.push(val-mini);
//             else del++;
//         }
//     }
// }

// int main(){
//     int t; cin>>t;
//     while(t--){
//         ll n,k; cin>>n>>k;
//         vector<ll> v(n);
//         for(auto &i:v)  cin>>i;

//         sort(v.begin(), v.end());
//         ll s = 1;
//         ll e = n;

//         while(s<=e){
//             ll mid = s + (e-s)/2;

//             if(isPossible(mid,v)){
//                 s = mid+1;
//             }
//             else{
//                 e = mid-1;
//             }
//         }
//         cout<<e<<endl;
//     }
//     return 0;
// }