#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>& arr, ll tar, vector<ll>& dp) {
    if (tar == 0)    return 0;
    if (tar < 0)   return 1e9;

    if (dp[tar] != -1)   return dp[tar];
    long long ans = 0;
    long long mini = 1e9;
    for (int i = 0; i <= (int)arr.size(); i++) {
        ans = solve(arr, tar - arr[i], dp);
        if (ans != 1e9) {
            mini = min(1 + ans, mini);
        }
    }
    return dp[tar] = mini;
}

int main() {
    ll n, tar;cin >> n >> tar;
    vector<int> arr(n);
    for (int i = 0;i < n;i++)    cin >> arr[i];

    // vector<ll> dp(tar + 1, -1);
    // ll ans = solve(arr, tar, dp);
    // if (ans == 1e9)  cout << -1;
    // else cout << ans;


    vector<ll> dp(tar + 1, 1e9);
    dp[0] = 0;
    for (int j = 1; j <= tar; j++) {
        long long ans = 0;
        long long mini = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            if (j - arr[i] >= 0) {
                ans = dp[j - arr[i]];
                if (ans != 1e9) {
                    mini = min(1 + ans, mini);
                }
            }
            dp[j] = mini;
        }
    }

    ll ans = dp[tar];
    if (ans == 1e9)  cout << -1;
    else cout << ans;
    return 0;
}