#include<bits/stdc++.h>
using namespace std;
#define ll int

ll solve(vector<int>& price, vector<int>& pages, int i, int x) {
    if (x == 0)    return 0;
    if (x < 0) return -1e7;
    if (i < 0) {
        return 0;
    }

    ll notpick = solve(price, pages, i - 1, x);
    ll pick = pages[i] + solve(price, pages, i - 1, x - price[i]);

    return max(notpick, pick);
}

int main() {
    int n, x; cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)  cin >> price[i];
    for (int i = 0; i < n; i++)  cin >> pages[i];

    // cout << solve(price, pages, n - 1, x);

    //tabulate
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));
    for (int i = price[0];i <= x; i++)   dp[0][i] = pages[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            ll notpick = dp[i - 1][j];
            ll pick = j - price[i] >= 0 ? pages[i] + dp[i - 1][j - price[i]] : 0;

            dp[i][j] = max(notpick, pick);
        }
    }

    cout << dp[n - 1][x];
    return 0;
}