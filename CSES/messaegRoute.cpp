#include<bits/stdc++.h>
using namespace std;
// void dfs(int i, int dest, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, vector<int> path) {
//     if (i == dest) {
//         path.push_back(i + 1);
//         if (ans.size() == 0 || ans.size() > path.size()) {
//             ans = path;
//         }
//         return;
//     }
//     if (vis[i])  return;

//     vis[i] = 1;
//     path.push_back(i + 1);
//     for (auto nbr : adj[i]) {
//         if (!vis[nbr]) {
//             dfs(nbr, dest, adj, vis, ans, path);
//         }
//     }
//     vis[i] = 0;
// }
int main() {
    int n, m; cin >> n >> m;

    /*
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        vector<int> ans, vis(n);
        dfs(0, n - 1, adj, vis, ans, {});

        if (ans.empty()) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    */

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n + 1), dist(n + 1, INT_MAX);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int nbr : adj[node]) {
            if (dist[nbr] == INT_MAX) {
                dist[nbr] = dist[node] + 1;
                par[nbr] = node;
                q.push(nbr);
            }
        }
    }

    if (dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE";
    }
    else {
        vector<int> path;
        path.push_back(n);
        while (path.back() != 1) {
            path.push_back(par[path.back()]);
        }
        int sx = path.size();
        cout << sx << endl;
        for (int i = sx - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }
    return 0;
}