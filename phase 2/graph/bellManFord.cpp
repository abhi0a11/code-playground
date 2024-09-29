#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// shortest path 
// dijkastra fail when graph has negative edges
// dijkastra goes for TLE if graph has negative cycle

/*
bellman ford algorith is used to find shortest path
it helps to detect negative cycles
it is only aplicable in directed graph
*/

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S){
    vector<int> dist(V,1e9);
    dist[S] = 0;

    // V*E - TC
    for(int i=0; i<V; i++){
        for(auto it: edges){
            int u = it[0]; 
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //Nth relaxation to check negative cycle
    for(auto it: edges){
        int u = it[0]; 
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}

int main(){
    return 0;
}