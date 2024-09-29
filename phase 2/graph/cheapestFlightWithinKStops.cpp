#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cheapestFlight(int n, vector<vector<int>>& flights,int src, int dst, int k){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it: flights){
        adj[it[0]].push_back({it[1],it[2]});
    }

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k)   continue;
        for(auto nbr: adj[node]){
            int adjNode = nbr.first;
            int adjDist = nbr.second;

            if(cost + adjDist < dist[node] && stops == k){
                dist[adjNode] = cost + adjDist;
                q.push({stops+1 , {adjNode, cost + adjDist}});
            }

        }
    }

    if(dist[dst] == INT_MAX)    return -1;
    return dist[dst];

}

int main(){
    
    return 0;
}