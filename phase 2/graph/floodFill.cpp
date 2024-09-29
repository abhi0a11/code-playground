#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs( int row, int col,vector<vector<int>>& ans,vector<vector<int>>& image, int newColor,int iniColor){
    ans[row][col] = newColor;
    //traverse neighbour
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    int n = image.size();
    int m = image[0].size();

    for(int i=0; i<4;i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol>=0 && nCol<m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != newColor){
            dfs(nRow,nCol,ans,image,newColor,iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int startRow, int startCol, int newColor)
{
    int iniColor = image[startRow][startCol];
    vector<vector<int>> ans = image;

    dfs(startRow,startCol,ans,image,newColor,iniColor);

    return ans;
}
int main(){
    
    return 0;
}