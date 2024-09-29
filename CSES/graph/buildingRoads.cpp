#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node)    return node;
        return parent[node] = findPar(parent[node]);
    }

    void union_by_size(int u, int v) {
        int paru = findPar(u);
        int parv = findPar(v);

        if (paru == parv)    return;
        if (size[paru] < size[parv]) {
            size[parv] += size[paru];
            parent[paru] = parv;
        }
        else {
            size[paru] += size[parv];
            parent[parv] = paru;
        }
    }
    vector<int> getCities() {
        vector<int> ultPar;
        for (int i = 1; i < parent.size(); i++) {
            if (i == findPar(i)) {
                ultPar.push_back(i);
            }
        }
        return ultPar;
    }
};

int main() {
    int n, m; cin >> n >> m;
    DisjointSet ds(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ds.union_by_size(u, v);
    }
    vector<int> ans = ds.getCities();
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i - 1] << " " << ans[i] << endl;
    }
    return 0;
}