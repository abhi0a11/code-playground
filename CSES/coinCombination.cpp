#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int main() {
    int n, tar; cin >> n >> tar;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    // cout << solve(arr, tar, n);
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= tar; j++) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (j - arr[i] >= 0) {
                ans += dp[j - arr[i]];
            }
        }

        dp[j] += ans % mod;
    }
    cout << dp[tar];
    return 0;
}

