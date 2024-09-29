#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i < n + 1; i++) parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (node == parent[node])   return node;

        return parent[node] = findUltimateParent(parent[node]);
    }
    void union_by_rank(int u, int v)
    {
        int ulp_v = findUltimateParent(v);
        int ulp_u = findUltimateParent(u);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])   parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])    parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void union_by_size(int u, int v) {
        int ulp_v = findUltimateParent(v);
        int ulp_u = findUltimateParent(u);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    // DisjointSet ds(7);
    // ds.union_by_size(1, 2);
    // ds.union_by_size(2, 3);
    // ds.union_by_size(4, 5);
    // ds.union_by_size(6, 7);
    // ds.union_by_size(5, 6);
    // // if 3 and 7 are part of same component or not
    // if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    // {
    //     cout << "Same\n";
    // }
    // else
    //     cout << "Different\n";
    // ds.union_by_size(3, 7);
    // if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    // {
    //     cout << "Same\n";
    // }
    // else
    //     cout << "Different\n";
    DisjointSet ds(7);
    ds.union_by_rank(1, 2);
    ds.union_by_rank(2, 3);
    ds.union_by_rank(4, 5);
    ds.union_by_rank(6, 7);
    ds.union_by_rank(5, 6);
    // if 3 and 7 are part of same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Different\n";
    ds.union_by_rank(3, 7);
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Different\n";
    return 0;
}