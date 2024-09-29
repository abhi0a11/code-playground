#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n,vector<bool>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1,0,1,0}; 
    int delCol[] = {0,1,0,-1}; 
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        
        dist[row][col] = step;

        for(int i=0; i<4; i++){
            int nbrRow = row + delRow[i];
            int nbrCol = col + delCol[i];

            if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol <m && !vis[nbrRow][nbrCol]){
                q.push({{nbrRow,nbrCol},step+1});
                vis[nbrRow][nbrCol] = 1;
            }
        }
        return dist;
    }
}
int main(){
    //find the distance of the nearest 1 in the grid for each cell
    return 0;
}