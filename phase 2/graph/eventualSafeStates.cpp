#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[],vector<int>& vis,vector<int>& dfsvis,vector<int>& isSafeNode){
    vis[node] = 1;
    dfsvis[node] = 1;

    for(auto nbr: adj[node]){
        if(!vis[nbr]){
           if(dfsCheck(nbr,adj,vis,dfsvis,isSafeNode)){
                isSafeNode[nbr] =0;
                return true;
           }
        }
        else if(dfsvis[nbr]){
                isSafeNode[nbr] =0;
                return true;
           }
    }

    isSafeNode[node] = 1;
    dfsvis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    vector<int> dfsvis(V,0);
    vector<int> isSafeNode(V,0);

    for(int i=0; i<V; i++){
        if(!vis[i]){
            dfsCheck(i,adj, vis, dfsvis,isSafeNode);
        }
    }
    vector<int> ans;
    for(int i=0; i<V; i++){
        if(isSafeNode[i] == 1){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    
    return 0;
}