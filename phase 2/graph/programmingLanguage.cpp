#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }
    void union_by_rank(int u, int v)
    {
        int ulp_v = findUltimateParent(v);
        int ulp_u = findUltimateParent(u);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void union_by_size(int u, int v)
    {
        int ulp_v = findUltimateParent(v);
        int ulp_u = findUltimateParent(u);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void printPar(){
        for(int i=0; i<parent.size(); i++){
            cout<<parent[i]<<" ";
        }
    }
};
int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adjPragramerToLang(n);
    vector<vector<int>> adjLangToProgramer(n);
    for(int i=0; i<n; i++){
        int size;
        cin>>size;
        for(int j=0; j<size; j++){
            int el;
            cin>>el;
            adjPragramerToLang[i].push_back(el);
            adjLangToProgramer[el].push_back(i);
        }
    }

    DisjointSet ds(n);
    for(int i=0; i<n; i++){
        for(auto it:adjPragramerToLang[i]){
            for(auto j:adjLangToProgramer[it])
                ds.union_by_size(i,j);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(ds.findUltimateParent(i) == i){
            ans++;
        }
    }
    // cout<<endl;
    // ds.printPar();
    // cout<<endl;
    cout<<ans-1;
    return 0;
}