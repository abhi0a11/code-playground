#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long solve(long long n, vector<long long>& dp) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];

    long long ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += solve(n - i, dp);
        ans = ans % mod;
    }

    return dp[n] = ans % mod;
}

long long solveTab(long long tar) {
    vector<long long> dp(tar + 1, 0);
    dp[0] = 1;

    for (long long n = 1; n <= tar; n++) {
        long long ans = 0;
        for (int i = 1; i <= 6; i++) {
            if (n - i >= 0) {
                ans += dp[n - i];
                ans = ans % mod;
            }
        }

        dp[n] = ans % mod;
    }
    return dp[tar];
}
int main() {
    long long n;cin >> n;
    // vector<long long> dp(n + 1, -1);
    // cout << solve(n, dp);
    cout << solveTab(n);
    return 0;
}