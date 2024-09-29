#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int,int>,int>> q; // row,col, timme
    vector<vector<int>> vis(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }

    int currTime = 0;
    int delRow[] = {-1,0,1,0}; 
    int delCol[] = {0,1,0,-1}; 

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;

        currTime = max(currTime,time);
        q.pop();

        for(int i=0; i<4; i++){
            int nbrRow = row + delRow[i];
            int nbrCol = col + delCol[i];
            if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol <m && vis[nbrRow][nbrCol] != 1 && grid[nbrRow][nbrCol] == 1){
                q.push({{nbrRow,nbrCol},time+1});
                vis[nbrRow][nbrCol] = 1;
            }
        }
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(grid[i][j] == 1 && vis[i][j] == 0){
                return -1;
            }
        }
    }
    return currTime;
}
int main(){
    
    return 0;
}