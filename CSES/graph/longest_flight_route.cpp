#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<int> adj[n + 1];
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 2;i <= n;i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto&& nbr : adj[node]) {
            indegree[nbr]--;
            if (!indegree[nbr] && nbr != 1) {
                q.push(nbr);
            }
        }
    }
    q.push(1);
    vector<int> cnt(n + 1, 0);
    cnt[1] = 1;
    vector<int> parent(n + 1, -1);
    parent[1] = 1;
    int e = n, chk = false;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto&& nbr : adj[node]) {
            indegree[nbr]--;
            if (nbr == n && cnt[nbr] < 1 + cnt[node]) {
                chk = true;
                cnt[nbr] = 1 + cnt[node];
                parent[nbr] = node;
            }
            else if (nbr != n) {
                cnt[nbr] = 1 + cnt[node];
                parent[nbr] = node;
            }
            if (!indegree[nbr]) {
                q.push(nbr);
            }
        }
    }
    if (!chk) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    ans.push_back(e);
    while (e != 1) {
        e = parent[e];
        ans.push_back(e);
    }
    reverse(ans.begin(), ans.end());
    cout << cnt[n] << endl;
    for (auto&& val : ans) {
        cout << val << " ";
    }
    return 0;
}