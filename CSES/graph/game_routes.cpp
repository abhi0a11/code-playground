#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    vector<ll> dp(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)  q.push(i);
    }

    dp[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto nbr : adj[x]) {
            dp[nbr] += dp[x];
            dp[nbr] %= mod;
            in[nbr]--;
            if (in[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    cout << dp[n];
    return 0;

}