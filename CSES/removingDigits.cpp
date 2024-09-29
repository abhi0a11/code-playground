#include<bits/stdc++.h>
using namespace std;
int solve(int n) {
    if (n == 0)  return 0;
    if (n < 0) return 1e8;

    int temp = n;
    int ans = 0;
    int mini = INT_MAX;
    while (temp) {
        int dig = temp % 10;
        temp /= 10;
        if (dig != 0) {
            ans = 1 + solve(n - dig);
            mini = min(mini, ans);
        }
    }
    return mini;
}
int main() {
    int n; cin >> n;
    // cout << solve(n);

    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = i;
        int ans = 0;
        int mini = INT_MAX;
        while (temp) {
            int dig = temp % 10;
            temp /= 10;
            if (dig != 0 && i - dig >= 0) {
                ans = 1 + dp[i - dig];
                mini = min(mini, ans);
            }
        }
        dp[i] = mini;
    }
    cout << dp[n];
    return 0;
}