#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int N, vector<pair<int,int>>& prerequisites){
    vector<int> adj[N];
    vector<int> indegree(N,0);
    queue<int> q;
    
    for(auto it: prerequisites){
        adj[it.first].push_back(it.second);
        indegree[it.second]++;
    }

    for(int i=0; i<N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt=0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;

        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

    return cnt==N;
}
int main(){
    //question - prerequisite Tasks gfg
    return 0;
}