#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || !grid[i][j])
        return;
    vis[i][j] = 1;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        dfs(nx, ny, grid, vis, n, m);
    }


}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            if (ch == '.')   grid[i][j] = 1;
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                dfs(i, j, grid, vis, n, m);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}