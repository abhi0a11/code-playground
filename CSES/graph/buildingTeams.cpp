#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int team, vector<vector<int>>& adj, vector<int>& group, bool& flag) {
    if (group[i] == -1)  group[i] = team;

    for (auto nbr : adj[i]) {
        if (group[nbr] == -1) {
            group[i] == 1 ? group[nbr] = 2 : group[nbr] = 1;
            dfs(nbr, 1, adj, group, flag);
        }
        else if (group[nbr] != -1 && group[i] == group[nbr]) {
            flag = true;
            return;
        }

    }
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> group(n + 1, -1);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (group[i] == -1) {
            dfs(i, 1, adj, group, flag);
        }
    }

    if (flag)    cout << "IMPOSSIBLE";
    else {
        for (int i = 1; i <= n; i++) cout << group[i] << " ";
    }
    return 0;
}