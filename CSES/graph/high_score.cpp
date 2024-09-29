#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m; cin >> n >> m;
    vector<vector< pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
    }

    vector<ll> dist(n + 1, -1e17);
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[j] != -1e17) {

                for (auto [a, b] : adj[j]) {
                    if (dist[j] + b > dist[a]) {
                        dist[a] = dist[j] + b;
                    }
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        if (dist[j] != -1e17) {
            for (auto [a, b] : adj[j]) {
                if (dist[j] + b > dist[a]) {
                    queue<int> q;
                    q.push(j);
                    vector<bool> vis(n + 1, 0);
                    vis[j] = 1;
                    while (!q.empty()) {
                        int node = q.front();
                        q.pop();

                        if (node == n) {
                            cout << -1;
                            exit(0);
                        }

                        for (auto [a, b] : adj[node]) {
                            if (!vis[a]) {
                                vis[a] = 1;
                                q.push(a);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dist[n];

    return 0;
}