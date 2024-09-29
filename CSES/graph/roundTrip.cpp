#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& parent, int p, int& cycleStart, int& cycleEnd) {
    vis[node] = 1;
    parent[node] = p;

    for (auto nbr : adj[node]) {
        if (nbr == p)    continue;

        if (!vis[nbr]) {
            if (dfs(nbr, adj, vis, parent, node, cycleStart, cycleEnd)) return 1;
        }
        else {
            cycleStart = node;
            cycleEnd = nbr;
            return 1;
        }
    }
    return 0;
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1);
    bool flag = false;
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cyclestart = -1, cycleEnd = -1;
            bool isCyclic = dfs(i, adj, vis, parent, -1, cyclestart, cycleEnd);
            if (isCyclic) {

                ans.push_back(cyclestart);
                int temp = cyclestart;
                while (temp != cycleEnd) {
                    ans.push_back(parent[temp]);
                    temp = parent[temp];
                }
                ans.push_back(cyclestart);
                flag = 1;
                break;
            }
        }
    }
    if (flag) {
        cout << ans.size() << endl;
        for (auto el : ans)    cout << el << " ";
    }
    else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}