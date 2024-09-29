#include<bits/stdc++.h>
using namespace std;
#define ll long long

// long long solve(string s, string t, int i, int j) {

//     if (i < 0)  return j + 1;
//     if (j < 0)  return i + 1;

//     if (s[i] == t[j]) {
//         return solve(s, t, i - 1, j - 1);
//     }
//     else {
//         return 1 + min({ solve(s, t,i - 1,j),solve(s, t, i,j - 1), solve(s, t,i - 1,j - 1) });
//     }
// }
int main() {
    string s, t; cin >> s >> t;
    int n = s.size(); int m = t.size();

    // cout << solve(s, t, n - 1, m - 1);
    //tabulate


    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j < m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1],  dp[i - 1][j - 1] });
            }
        }
    }
    cout << dp[n][m];
    return 0;
}