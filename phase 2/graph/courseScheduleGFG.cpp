#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int N, int m,vector<vector<int>> prerequisites){
    vector<int> adj[N];
    vector<int> indegree(N,0);
    queue<int> q;
    
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }

    for(int i=0; i<N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt=0;  
    vector<int> topo;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        topo.push_back(front);

        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

    if(topo.size() == N)    return topo;
    else    return {};
}
int main(){
    //course schedule gfg
    return 0;
}