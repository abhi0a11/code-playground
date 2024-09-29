#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int countStrings(int minL, int maxL, int cx, int cy, int len) {
    if (len > maxL)    return 0;

    int ans = 0;
    if (len >= minL && len <= maxL) {
        ans++;
    }
    ans += countStrings(minL, maxL, cx, cy, len + cx);
    ans += countStrings(minL, maxL, cx, cy, len + cy);
    ans %= mod;

    return ans % mod;
}
int lis(vector<int>& v, int i, int prev) {
    if (i >= v.size())   return 0;

    int len = 0 + lis(v, i + 1, prev);
    if (prev == -1 || v[prev] < v[i]) {
        len = max(1 + lis(v, i + 1, i), len);
    }

    return len;
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)  cin >> v[i];

    cout << n - lis(v, 0, -1);

    // int minL, maxL, cx, cy;
    // cin >> minL >> maxL >> cx >> cy;

    // cout << countStrings(minL, maxL, cx, cy, 0);

    return 0;
}