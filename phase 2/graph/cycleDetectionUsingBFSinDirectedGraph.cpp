#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detectCycleInDirectedGraph(int n, vector<pair<int,int>>& edges)
{
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first-1; // is nodes start from 1 not 0
        int v = edges[i].second-1;// is nodes start from 1 not 0
        
        adj[u].push_back(v);
    }

    //find all indegrees;
    vector<int> indegree(n);

    for(int i=0; i<edges.size(); i++){
        indegree[edges[i].second]++;
    }

    //0 indegree walo ko push krdo
    queue<int> q;
    // for(int i=1; i<=n;i++){ // if nodes start from 1 not 0 do this 
                        // or subtrat 1 with all nodes like done above
    for(int i=0; i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    int cnt;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //ans store
        cnt++;

        //neighbour indegree update
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return (cnt == n);
}

int main(){
    
    return 0;
}