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
        int a, b; cin >> a >> b;
        ds.union_by_size(a, b);
    }

    vector<int> cities = ds.getCities();
    cout << cities.size() - 1 << endl;
    for (int i = 1; i < cities.size(); i++) {
        cout << cities[i - 1] << " " << cities[i] << endl;
    }
    return 0;
}