#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int node,vector<int>& color,bool graph[101][101],int N, int col){
    for(int k=0; k<N; k++){
        if(k != node && graph[k][node] == 1 && color[k] != col){
            return true;
        }
    }
    return false;
}
bool solve(int node,vector<int>& color,bool graph[101][101], int m, int N){
    if(node == N){
        return true;
    }

    for(int i=1; i<=m; i++){
        if(isSafe(node,color,graph,N,i)){
            color[node] = i;
            if(solve(node+1,color,graph,m,N))  return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int N){
    vector<int> color(N,0);
    return solve(0,color,graph,m,N);
}
int main(){
    
    return 0;
}