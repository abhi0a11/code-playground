#include<bits/stdc++.h>
using namespace std;
void solve(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == '#') {
        return;
    }

    vis[i][j] = 1;

    int dr[] = { 0,0,1,-1 };
    int dc[] = { 1,-1,0,0 };

    for (int k = 0; k < 4; k++) {
        solve(i + dr[k], j + dc[k], grid, vis, n, m);
    }
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '.'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                ans++;
                solve(i, j, grid, vis, n, m);
            }
        }
    }
    cout << ans;
    return 0;
}