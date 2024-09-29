#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dijkastra(vector<vector<pair<ll, ll>>>& adj, vector<ll>& dist, ll n) {
    set<pair<ll, ll>> st;
    st.insert({ 0LL,n });
    dist[n] = 0;
    while (!st.empty()) {
        ll node = (*st.begin()).second;
        ll price = (*st.begin()).first;
        st.erase(st.begin());

        for (auto nbr : adj[node]) {
            if (price + nbr.second < dist[nbr.first]) {
                if (dist[nbr.first] != 1e17)
                    st.erase({ dist[nbr.first],nbr.first });
                dist[nbr.first] = price + nbr.second;
                st.insert({ dist[nbr.first],nbr.first });
            }
        }
    }
}

int main() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<vector<pair<ll, ll>>> adjRev(n + 1);
    vector<tuple<ll, ll, ll>> edge;
    for (ll i = 0; i < m; i++) {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        edge.push_back({ a,b,c });
        adj[a].push_back({ b,c });
        adjRev[b].push_back({ a,c });
    }

    vector<ll> distRev(n + 1, 1e17);
    dijkastra(adjRev, distRev, n);

    vector<ll> dist(n + 1, 1e17);
    dijkastra(adj, dist, 1);

    ll ans = LONG_MAX;
    for (auto [a, b, c] : edge) {
        if (ans > (dist[a] + c / 2 + distRev[b])) {
            ans = (dist[a] + c / 2 + distRev[b]);
        }
    }

    cout << ans;
    return 0;

}