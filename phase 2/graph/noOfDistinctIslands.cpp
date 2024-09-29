#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int row, int col,vector<vector<int>>& vis,vector<vector<int>>& grid,vector<pair<int,int>>& ans,int row0,int col0){
    vis[row][col] = 1;

    ans.push_back({(row-row0),(col-col0)});

    int n = grid.size();
    int m = grid[0].size();

    int delRow[] = {-1,0,1,0}; 
    int delCol[] = {0,-1,0,1}; 

    for(int i=0; i<4; i++){
        int nbrRow = row + delRow[i];
        int nbrCol = col + delCol[i];

        if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol <m && 
        !vis[nbrRow][nbrCol] && grid[nbrRow][nbrCol] == 1){
            
            dfs(nbrRow,nbrCol,vis,grid,ans, row0, col0);
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    
    set<vector<pair<int,int>>> st;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> ans;
                dfs(i,j,vis,grid,ans,i,j);
                st.insert(ans);
            }
        }
    }
}
int main(){
    //tc n x m x log(set length) + (n x m x 4)
    return 0;
}