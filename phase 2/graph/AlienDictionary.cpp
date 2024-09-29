#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void topoSort(int node,vector<bool>& vis,stack<int> &s,vector<int> adj[]){
    vis[node] =1;
    for(auto neighbour:adj[node]){
        if(!vis[neighbour]){
            topoSort(neighbour,vis,s,adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(int v, vector<int> adj[]){

    vector<bool> vis(v);
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            topoSort(i,vis,s,adj);
        }

    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    
}

string findOrder(string dict[], int N, int k){
    vector<int> adj[k];
    for(int i=0; i<N; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());

        for(int ptr = 0; ptr < len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topologicalSort(k,adj);
    string ans="";
    for(auto it:topo){
        ans = ans + char(it + 'a');
    }
    return ans;
}
int main(){
    
    return 0;
} 

//cyclic dependency and shorted string matches longer string and comes after longer in these two cases dictionary fails 