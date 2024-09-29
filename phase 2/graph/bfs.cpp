#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{

public:
    unordered_map<int,list<int>> edges;

    void addEdge(int u, int v,bool direction){
        
        edges[u].push_back(v);

        if(direction == 0)  edges[v].push_back(u);

    }

    void print(){
        for(auto i:edges){
            cout << i.first << "-> ";
            for(auto j:i.second){
                cout << j <<", ";
            }cout<<endl;
        }
    }
};

//for undirected graph
void prepareAdjList(unordered_map<int,set<int>>& adjList, vector<pair<int,int>>& edges){
    for(int i=0; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int>& ans, int node){

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontnode
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList,edges);

    //traverse all components of a graph
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
int main(){
    graph g;

    int n,m;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.print();
    return 0;
}