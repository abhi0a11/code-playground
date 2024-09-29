#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

ll solve(int n, int m, vector<int>& arr, int i) {
    if (i >= n)    return 1;

    ll ans = 0;
    if (arr[i] == 0) {
        for (int j = 1; j <= m; j++) {
            if (i == 0 || abs(arr[i - 1] - j) <= 1) {
                arr[i] = j;
                ans += solve(n, m, arr, i + 1);
                arr[i] = 0;
            }
        }
    }
    else {
        if (i == 0 || abs(arr[i - 1] - arr[i]) <= 1)
            ans = solve(n, m, arr, i + 1);
        else    ans = 0;
    }

    return ans % mod;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    // cout << solve(n, m, arr, 0);

    //tabulate
    vector<ll> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
        ll ans = 0;
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                if (i == 0 || abs(arr[i - 1] - j) <= 1) {
                    arr[i] = j;
                    ans += dp[i + 1];
                    arr[i] = 0;
                }
            }
        }
        else {
            if (i == 0 || abs(arr[i - 1] - arr[i]) <= 1)
                ans = dp[i + 1];
            else    ans = 0;
        }

        dp[i] = ans % mod;
    }
    cout << dp[0];
    return 0;
}