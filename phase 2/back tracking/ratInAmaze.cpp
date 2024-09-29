#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited,vector<vector<int>> &arr,int n){
    if((newx >=0 && newx < n) && (newy >=0 && newy <n) && visited[newx][newy] != 1 && arr[newx][newy] == 1){
        return true;

    }
    else    return false;
}
void solve(int x, int y,vector<vector<int>>& arr,vector<string> ans,
                vector<vector<bool>> &visited,string path,int n){
        
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    //4 movement
    //D L R U

    visited[x][y] = 1;
    //down
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,ans,visited,path + 'D',n);
    }
    //left
    if(isSafe(x,y-1,visited,arr,n)){
        solve(x+1,y,arr,ans,visited,path + 'L',n);
    }
    //right
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x+1,y,arr,ans,visited,path + 'R',n);
    }
    //up
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x+1,y,arr,ans,visited,path + 'U',n);
    }
    visited[x][y] = 0;

}

vector<string> searchMaze(vector<vector<int>> &maze, int n){
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool> (n,0));

    string path="";
    if(maze[0][0] == 0) return ans;
    solve(0,0,maze,ans,visited,path,n);
}

int main(){
    
    return 0;
}