#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col,vector<vector<bool>>& vis,vector<vector<char>>& grid){
    queue<pair<int,int>> q;
    q.push({row,col});
    vis[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        pair<int,int> top = q.front();
        int i = top.first;
        int j = top.second;

        q.pop();

        //traverse all the neighbours 
        for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
            for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                int nbrRow = i + deltaRow;
                int nbrCol = j + deltaCol;

                if(nbrRow >=0 && nbrRow < n && nbrCol >= 0 && nbrCol < m 
                    && grid[nbrRow][nbrCol] == '1' && vis[nbrRow][nbrCol] == 0){
                    vis[nbrRow][nbrCol] = 1;
                    q.push({nbrRow,nbrCol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int cnt=0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}

int main(){
    
    return 0;
}