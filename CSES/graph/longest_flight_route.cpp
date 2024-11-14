#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        indegree[v - 1]++;
    }

    queue<int> q;

    for (int i = 1; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0 && nbr != 0) {
                q.push(nbr);
            }
        }

    }

    vector<int> cnt(n, 0);
    vector<int> parent(n, -1);
    q.push(0);
    cnt[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nbr : adj[node]) {
            indegree[nbr]--;

            cnt[nbr] = 1 + cnt[node];
            parent[nbr] = node;

            if (!indegree[nbr]) {
                q.push(nbr);
            }
        }
    }


    if (parent[n - 1] == -1)
        cout << "IMPOSSIBLE";
    else {
        cout << cnt[n - 1] << endl;
        vector<int> ans;
        int node = n - 1;
        ans.push_back(n - 1);
        while (parent[node] != -1) {
            ans.push_back(parent[node]);
            node = parent[node];
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] + 1 << " ";
        }
    }
    return 0;
}