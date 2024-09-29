#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m;i++) {
        int a, b;ll c; cin >> a >> b >> c;
        adj[a].push_back({ b,c });
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(k, 1e17));
    priority_queue < pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        ll d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node][k - 1] < d) continue;

        for (auto [nbrNode, nbrDist] : adj[node]) {
            if (nbrDist + d < dist[nbrNode][k - 1]) {
                dist[nbrNode][k - 1] = nbrDist + d;
                pq.push({ dist[nbrNode][k - 1],nbrNode });
                sort(dist[nbrNode].begin(), dist[nbrNode].end());
            }
        }

    }

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
    return 0;
}