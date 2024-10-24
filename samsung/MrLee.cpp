#include<bits/stdc++.h>
using namespace std;

int ans = 0;
void dfs(vector<int>& vis, int cnt, vector<vector<int>>& adj, int x, int n, int cost) {
    if (cnt == n - 1) {
        if (adj[x][0] != 0)  ans = min(ans, cost + adj[x][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && adj[x][i] != 0) {
            vis[x] = 1;
            dfs(vis, cnt + 1, adj, i, n, adj[x][i] + cost);
            vis[x] = 0;
        }
    }
}
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> adj(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
            }
        }

        vector<int> vis(n, 0);
        ans = INT_MAX;
        dfs(vis, 0, adj, 0, n, 0);
        cout << ans << endl;
    }
    return 0;
}