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

    vector<ll> dist(n + 1);
    vector<int> parent(n + 1, -1);
    int x;
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (int j = 1; j <= n; j++) {

            for (auto [a, b] : adj[j]) {
                if (dist[j] + b < dist[a]) {
                    dist[a] = dist[j] + b;
                    parent[a] = j;
                    x = a;
                }
            }
        }
    }
    if (x == -1)   cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            x = parent[x]; // backtract n times so that if x is nbr node of negative cycle then it becomes member of negative cycle
        }
        vector<int> ans;
        int v = x;
        while (true) {
            ans.push_back(v);
            if (v == x && ans.size() > 1) {
                break;
            }
            v = parent[v];
        }
        for (int i = ans.size() - 1; i >= 0; i--)  cout << ans[i] << " ";
    }


    return 0;
}