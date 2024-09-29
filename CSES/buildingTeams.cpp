#include<bits/stdc++.h>
using namespace std;
void updateTeam(int node, int teamNumber, bool& possible, vector<vector<int>>& adj, vector<int>& team) {
    if (team[node] == -1) {
        team[node] = teamNumber;
    }

    for (auto nbr : adj[node]) {
        if (team[nbr] != -1 && team[nbr] == team[node]) {
            possible = 0;
            return;
        }
        else if (team[nbr] == -1) {
            team[node] == 1 ? team[nbr] = 2 : team[nbr] = 1;

            updateTeam(nbr, team[nbr] == 1 ? 2 : 1, possible, adj, team);
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

    vector<int> team(n + 1, -1);
    bool isPossible = 1;

    for (int i = 1; i <= n; i++) {
        if (team[i] == -1) {
            updateTeam(i, 1, isPossible, adj, team);
        }
    }
    if (!isPossible) cout << "IMPOSSIBLE";
    else {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
    }
    return 0;
}