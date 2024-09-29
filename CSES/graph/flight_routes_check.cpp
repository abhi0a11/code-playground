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
void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& temp) {
    vis[node] = 1;
    temp.push_back(node);
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs2(nbr, adj, vis, temp);
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

    vector<vector<int>> ans;
    stack<int> st;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    while (!st.empty()) {
        int top = st.top(); st.pop();
        if (!vis[top]) {
            vector<int> temp;
            dfs2(top, revAdj, vis, temp);
            ans.push_back(temp);
        }
    }
    if (ans.size() == 1) cout << "YES";
    else {
        if (ans.size() > 1) {
            cout << "NO" << endl;
            cout << ans[1][0] << " " << ans[0][0];
        }
    }

    return 0;
}