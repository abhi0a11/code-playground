#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, adj, vis, st);
        }
    }

    st.push(node);
}
void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans, int kingdom) {
    vis[node] = 1;
    ans[node] = kingdom;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs2(nbr, adj, vis, ans, kingdom);
        }
    }

}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> revAdj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    for (int i = 1; i <= n; i++) vis[i] = 0;

    vector<int> ans(n + 1, 0);
    int kingdom = 1;
    while (!st.empty()) {
        int top = st.top(); st.pop();
        if (!vis[top]) {
            dfs2(top, revAdj, vis, ans, kingdom);

            kingdom++;
        }
    }

    cout << kingdom - 1 << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";

    return 0;
}