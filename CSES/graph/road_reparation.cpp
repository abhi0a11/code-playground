#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    long long sum = 0;
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(n + 1, 0);
    pq.push({ 0,{1,-1} }); // wt , node, parent

    while (!pq.empty()) {
        long long wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if (!vis[node])  sum += wt;

        vis[node] = 1;

        for (auto nbr : adj[node]) {
            if (!vis[nbr.first]) {
                pq.push({ nbr.second,{nbr.first, node} });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << sum;
    return 0;
}