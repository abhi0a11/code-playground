#include<bits/stdc++.h>
using namespace std;

#define ll long long
int mod = 1e9 + 7;
// ll dfs(vector<vector<char>> grid, int n, int i, int j) {
//     if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '*')  return 0;
//     if (i == 0 && j == 0)  return 1;

//     ll up = dfs(grid, n, i - 1, j);
//     ll left = dfs(grid, n, i, j - 1);

//     return (up + left) % mod;
// }
int main() {
    int n;cin >> n;
    vector<vector<char>> grid;
    for (int i = 0; i < n; i++) {
        vector<char> row(n);
        for (int j = 0; j < n; j++) {
            cin >> row[j];
        }
        grid.push_back(row);
    }
    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }
    // cout << dfs(grid, n, n - 1, n - 1);

    // tabulate 

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == '*')   break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == '*')   break;
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {

            if (grid[i][j] != '*') {
                ll up = dp[i - 1][j];
                ll left = dp[i][j - 1];

                dp[i][j] = (up + left) % mod;
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}