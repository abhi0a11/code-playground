#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) return node;

        return parent[node] = findPar(parent[node]);
    }
    void union_by_size(int u, int v) {
        int uu = findPar(u);
        int uv = findPar(v);

        if (uu == uv)    return;

        if (size[uu] <= size[uv]) {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;cin >> u >> v >> w;
        edges.push_back({ w,u,v });
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(n);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int u = ds.findPar(edges[i][1]);
        int v = ds.findPar(edges[i][2]);

        if (u != v) {
            sum += edges[i][0];
            ds.union_by_size(u, v);
        }
    }
    cout << sum;
    return 0;
}