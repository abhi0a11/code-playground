#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
#define ll long long
struct Node {
    ll dist = LONG_MAX;
    int cntMin = 0;
    int minFlight = INT_MAX;
    int maxFlight = INT_MIN;
    unordered_map<int, int> mp;
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<int> ind(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        ind[b]++;
    }

    vector<Node> v(n + 1);
    v[1].dist = 0;
    v[1].cntMin = 0;
    v[1].minFlight = 0;
    v[1].maxFlight = 0;
    set<pair<ll, int>> st;
    st.insert({ 0,1 });

    while (!st.empty()) {
        ll w = (*st.begin()).first;
        int x = (*st.begin()).second;
        st.erase(st.begin());

        for (auto nbr : adj[x]) {
            if (w + nbr.second == v[nbr.first].dist) {
                st.erase({ v[nbr.first].dist, nbr.first });
                v[nbr.first].minFlight = min(v[nbr.first].minFlight, v[x].minFlight + 1);
                v[nbr.first].maxFlight = max(v[nbr.first].maxFlight, v[x].maxFlight + 1);
                v[nbr.first].cntMin += v[x].cntMin;
                v[nbr.first].cntMin %= mod;
                st.insert({ v[nbr.first].dist, nbr.first });
            }
            else if (w + nbr.second < v[nbr.first].dist) {
                if (v[nbr.first].dist != LONG_MAX) {
                    st.erase({ v[nbr.first].dist, nbr.first });
                }

                v[nbr.first].dist = w + nbr.second;
                v[nbr.first].cntMin = v[x].cntMin == 0 ? 1 : v[x].cntMin;
                v[nbr.first].minFlight = v[x].minFlight + 1;
                v[nbr.first].maxFlight = v[x].maxFlight + 1;
                st.insert({ v[nbr.first].dist, nbr.first });
            }
        }
    }
    cout << v[n].dist << " " << v[n].cntMin << " " << v[n].minFlight << " " << v[n].maxFlight;
    return 0;
}