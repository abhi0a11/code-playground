#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, m; cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({ v,w });
    }
    vector<ll> dist(n + 1, LONG_MAX);
    set<pair<ll, ll>> st;
    st.insert({ 0,1 });
    dist[1] = 0;
    while (!st.empty()) {
        auto p = st.begin();
        ll d = (*p).first;
        ll city = (*p).second;
        st.erase(p);

        for (auto nbr : adj[city]) {
            if (d + nbr.second < dist[nbr.first]) {
                if (dist[nbr.first] != LONG_MAX) st.erase({ dist[nbr.first] ,nbr.first });
                dist[nbr.first] = d + nbr.second;
                st.insert({ dist[nbr.first] ,nbr.first });
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    return 0;
}