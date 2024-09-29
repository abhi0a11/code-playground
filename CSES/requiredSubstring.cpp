#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int main() {
    int n;cin >> n;
    string s;cin >> s;
    int m = s.size();

    long long ans = n - m + 1;
    for (int i = 0; i < n - m; i++) {
        ans = (ans * 26) % mod;
    }
    cout << ans;
    return 0;
}