#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsvis, vector<int>& parent, int p, int& cycleStart, int& cycleEnd) {
    vis[node] = 1;
    dfsvis[node] = 1;
    parent[node] = p;

    for (auto&& nbr : adj[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr, adj, vis, dfsvis, parent, node, cycleStart, cycleEnd)) return 1;
        }
        else if (dfsvis[nbr]) {
            cycleStart = nbr;
            cycleEnd = node;
            return 1;
        }
    }
    dfsvis[node] = 0;
    return 0;
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> vis(n + 1, 0);
    vector<int> dfsvis(n + 1, 0);
    vector<int> parent(n + 1, -1);


    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cyclestart, cycleEnd;
            bool isCyclic = dfs(i, adj, vis, dfsvis, parent, -1, cyclestart, cycleEnd);

            if (isCyclic) {
                vector<int> ans;

                ans.push_back(cyclestart);

                while (cyclestart != cycleEnd) {
                    ans.push_back(cycleEnd);
                    cycleEnd = parent[cycleEnd];
                }
                ans.push_back(cyclestart);
                cout << ans.size() << endl;
                for (int i = ans.size() - 1; i >= 0; i--)    cout << ans[i] << " ";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";


    return 0;
}