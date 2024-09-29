#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool bfs(int node,vector<int>& color,queue<int>& q,vector<int>adj[] ){
        q.push(node);
        color[node] = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto nbr : adj[top]){
                if(color[nbr] == -1){
                    color[nbr] = !color[top];
                    q.push(nbr);
                }
                else if(color[nbr] == color[top])  return false;
            }
        }
        return true;
    }
bool isBipartite(int V, vector<int>adj[]){
    vector<int> color(V,-1);
    queue<int> q;
    
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if (bfs(i,color,q,adj) == false) return false;
        }
    }
    return true;
}
int main(){
    
    return 0;
}