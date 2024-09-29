#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> in(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        in[b]++;
        adj[a].push_back(b);
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)  q.push(i);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ans.push_back(x);
        for (auto nbr : adj[x]) {
            in[nbr]--;
            if (in[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    if (ans.size() == n) {

        for (auto el : ans)    cout << el << " ";
    }
    else    cout << "IMPOSSIBLE";
    return 0;
}