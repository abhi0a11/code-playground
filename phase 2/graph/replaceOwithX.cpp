#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<bool>> &vis,vector<vector<char>>& mat){
    vis[row][col] = 1;

    int n = mat.size();
    int m = mat[0].size();

    //check for right bottom up and left
    int delRow[] = {-1,0,1,0}; 
    int delCol[] = {0,1,0,-1}; 

    for(int i=0; i<4; i++){
        int nbrRow = row + delRow[i];
        int nbrCol = col + delCol[i];

        if(nbrRow>=0 && nbrRow<n && nbrCol>=0 && nbrCol <m && !vis[nbrRow][nbrCol] && mat[nbrRow][nbrCol] == 'O'){
            dfs(nbrRow,nbrCol,vis,mat);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector<vector<bool>> vis(n,vector<bool>(m,false)); 

    //traverse first row and last row
    for(int col =0; col<m; col++){
        //first row
        if(!vis[0][col] && mat[0][col] == 'O'){
            dfs(0,col,vis,mat);
        }

        //last row
        if(!vis[n-1][col] && mat[n-1][col] == 'O'){
            dfs(n-1,col,vis,mat);
        }
    }

    //traverse first col and last col
    for(int row =0; row<n; row++){
        //first row
        if(!vis[row][0] && mat[row][0] == 'O'){
            dfs(row,0,vis,mat);
        }

        //last row
        if(!vis[row][m-1] && mat[row][m-1] == 'O'){
            dfs(row,m-1,vis,mat);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] == 0 && mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}
int main(){
    //replace all the 'O's' with 'X' provided no set of 'O' is connected with boundary
    return 0;
}