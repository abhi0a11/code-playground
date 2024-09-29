#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> path(n + 1, -1);

    set<pair<int, int>> st;
    st.insert({ 0,1 });
    while (!st.empty()) {
        auto d = (*st.begin()).first;
        auto node = (*st.begin()).second;
        st.erase(st.begin());

        for (auto nbr : adj[node]) {
            if (d + 1 < dist[nbr]) {
                if (dist[nbr] != INT_MAX)    st.erase({ dist[nbr],nbr });
                dist[nbr] = d + 1;
                st.insert({ dist[nbr],nbr });
                path[nbr] = node;
            }
        }

    }
    if (dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE";

    }
    else {

        vector<int> ans;
        int v = n;
        while (v != 1) {
            ans.push_back(v);
            v = path[v];
        }
        ans.push_back(1);
        int k = ans.size();
        cout << k << endl;
        for (int i = k - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}