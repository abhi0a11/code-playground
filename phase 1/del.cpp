#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)  cin >> a[i];
    for (int i = 0; i < m; i++)  cin >> b[i];

    ll k; cin >> k;

    map<ll, ll> gcdA, gcdB;

    for (int i = 0; i < n; i++) {
        gcdA[gcd(k, a[i])]++;
    }
    for (int i = 0; i < m; i++) {
        gcdB[gcd(k, b[i])]++;
    }

    ll ans = 0;
    for (auto [ka, va] : gcdA) {
        for (auto [kb, vb] : gcdB) {
            if ((ka * kb) % k == 0) {
                ans += (va * vb);
            }
        }
    }
    cout << ans;
    return 0;
}