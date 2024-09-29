#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
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

        if (size[uu] < size[uv]) {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
    int getSize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        return max(size[u], size[v]);
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;cin >> u >> v;
        edges.push_back({ u,v });
    }
    DisjointSet ds(n);
    int totalComponent = n, maxSizeComponent = 0;
    for (int i = 0; i < m; i++) {
        int u = ds.findPar(edges[i][0]);
        int v = ds.findPar(edges[i][1]);

        if (u != v) {
            ds.union_by_size(u, v);
            totalComponent--;
            maxSizeComponent = max(maxSizeComponent, ds.getSize(u, v));
        }
        cout << totalComponent << " " << maxSizeComponent << endl;
    }


    return 0;
}