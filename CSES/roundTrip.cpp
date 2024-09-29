#include<bits/stdc++.h>
using namespace std;
bool isCyclic(int node, vector<int>& vis, vector<int>& parent, vector<vector<int>>& adj, pair<int, int>& cycleNode) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto nbr : adj[x]) {
            if (vis[nbr] && parent[x] != nbr) {
                // parent[nbr] = x;
                cycleNode = { nbr,x };
                return 1;
            }
            else if (!vis[nbr]) {
                vis[nbr] = 1;
                q.push(nbr);
                parent[nbr] = x;
            }
        }
    }
    return 0;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1), parent(n + 1, -1);

    vector<int> v1, v2;
    for (int node = 1; node <= n; node++) {
        if (!vis[node]) {
            pair<int, int> cycleNode = { -1,-1 };
            bool cycle = isCyclic(node, vis, parent, adj, cycleNode);

            if (cycle == 1) {
                int start = cycleNode.first;
                int finish = cycleNode.second;

                for (int i = 1; i <= n; i++)cout << parent[i] << " ";
            }
        }
    }


    // int path1 = v1.size();
    // int path2 = v2.size();

    // reverse(v1.begin(), v1.end());

    // if (path1 + path2 == 0) {
    //     cout << "IMPOSSIBLE";
    // }
    // else {
    //     cout << path1 + path2 << endl;
    //     for (int i = 0; i < path1; i++) {
    //         cout << v1[i] << " ";
    //     }
    //     for (int i = 0; i < path2; i++) {
    //         cout << v2[i] << " ";
    //     }
    // }
    return 0;
}