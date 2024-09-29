#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<bool>& vis, stack<int>& s, unordered_map<int, list<int>>& adj) {
    vis[node] = 1;
    for (auto neighbour : adj[node]) {
        if (!vis[neighbour]) {
            topoSort(neighbour, vis, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    //create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0;i < edges.size();i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    int n = adj.size();
    //call dfs topological sort util function for all components
    vector<bool> vis(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            topoSort(i, vis, s, adj);
        }

    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    if (ans.size() == n) {
        return ans;
    }
    else return {};
}
int main() {

    return 0;
}