#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>>& board,vector<vector<int>>&ans,int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
/*
// isSafe TC O(n)
bool isSafe(int row,int col,vector<vector<int>>& board,int n){
    int x =row;
    int y = col;

    //check for same row
    while(y>=0){
        if(board[x][y] == 1)    return false;

        y--;
    }
    
    //checck diagonal
    x = row,y= col;
    while(x>= 0 && y>=0){
        if(board[x][y] == 1)    return false;

        y--;
        x--;
    }

    x = row,y= col;
    while(x<n && y>=0){
        if(board[x][y] == 1)    return false;

        y--;
        x++;
    }

    return true;
}
void solve(int col, vector<vector<int> >&ans, vector<vector<int>>& board, int n){
    //base case
    if(col == n){
        addSolution(board,ans,n);
        return;
    }

    //solve 1 case and rest recurssion will take care

    for(int row = 0; row<n; row++){
        if(isSafe(row,col,board,n)){
            // if placing queen is safe
            board[row][col] = 1;
            solve(col+1,ans,board,n);
            //backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int> > board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ans,board,n);

    return ans;
}
*/
// opttimised approach isSafe TC O(1)
bool isSafe(int row,int col,int n,
    unordered_map<int,int> rowCheck,
    unordered_map<int,int>rightDownDiagCheck,
    unordered_map<int,int>upperRightDiagCheck){
    int x =row;
    int y = col;

    //check for same row
    if(rowCheck[x] == 1)    return false; 
    
    //check diagonal
    x = row,y= col;
     if(rightDownDiagCheck[x+y] == 1)    return false; 

    x = row,y= col;
     if(upperRightDiagCheck[(n-1) + (y-x)] == 1)    return false; 
    

    return true;
}
void solve(int col, vector<vector<int> >&ans, vector<vector<int>>& board,
    int n,unordered_map<int,int> rowCheck,
    unordered_map<int,int>rightDownDiagCheck,
    unordered_map<int,int>upperRightDiagCheck){

    //base case
    if(col == n){
        addSolution(board,ans,n);
        return;
    }

    //solve 1 case and rest recurssion will take care

    for(int row = 0; row<n; row++){
        if(isSafe(row,col,n,rowCheck,rightDownDiagCheck,upperRightDiagCheck)){
            // if placing queen is safe
            board[row][col] = 1;
            rowCheck[row] = 1;
            rightDownDiagCheck[row+col] = 1;
            upperRightDiagCheck[(n-1) + (col-row)] = 1;
            solve(col+1,ans,board,n,rowCheck,rightDownDiagCheck,upperRightDiagCheck);
            //backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n){
    vector<vector<int> > board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    unordered_map<int,int> rowCheck; // <row,(1/0)>
    unordered_map<int,int> rightDownDiagCheck;//<col+row,(1/0)>
    unordered_map<int,int> upperRightDiagCheck;//<(n-1) + (col-row),(1/0)>
    solve(0,ans,board,n,rowCheck,rightDownDiagCheck,upperRightDiagCheck);

    return ans;
}
int main(){
    
    return 0;
}

//overall TC N!
// SC O(n*n);