#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, 1e15));

    for (int i = 0; i < m; i++) {
        ll w; int u, v;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)  dist[i][j] = 0;
                else {
                    ll temp = dist[i][k] + dist[k][j];
                    dist[i][j] = min(dist[i][j], temp);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (dist[a][b] >= 1e15)  cout << -1;
        else    cout << dist[a][b];
        cout << endl;
    }
    return 0;
}