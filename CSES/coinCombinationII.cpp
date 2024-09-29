#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int solve(vector<int>& arr, int tar, int ind, vector<vector<int>>& dp) {
    if (tar == 0)    return 1;
    if (tar < 0)   return 0;

    int n = arr.size();
    if (dp[ind][tar] != -1)  return dp[ind][tar];

    int ans = 0;
    for (int i = ind; i < n; i++) {
        ans += solve(arr, tar - arr[i], i, dp);
        ans %= mod;
    }
    return dp[ind][tar] = ans;
}



int main() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);\
        for (int i = 0; i < n; i++) cin >> arr[i];

    // vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    // cout << solve(arr, x, 0, dp);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)  dp[i][0] = 1;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int tar = 1; tar <= x; tar++) {
            int ans = 0;
            for (int i = ind; i < n; i++) {
                if (tar - arr[i] >= 0) {
                    ans += dp[i][tar - arr[i]];
                    ans %= mod;
                }
            }
            dp[ind][tar] = ans;
        }
    }
    cout << dp[0][x];
    return 0;
}
