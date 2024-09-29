#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(string s, vector<vector<int>>& vis,int i, int row, int col){
    if(i == s.size())  return (row == 6 && col == 0);
    if(row<0 || row>=7 || col<0 || col>=7 || vis[row][col] || (row == 6 && col == 0)){
        return 0;
    }
    vis[row][col]= 1;

    int ans = 0;
    int dr[] = {0,0,1,-1};
    int dc[] = {1,-1,0,0};
    if(s[i] == '?'){
        for(int k=0; k<4; k++){
            ans += solve(s,vis,i+1,row+dr[k], col+dc[k]);
        }
    }
    else if(s[i] == 'U'){
        ans += solve(s,vis,i+1,row+-1, col);
    }
    else if(s[i] == 'R'){
        ans += solve(s,vis,i+1,row, col+1);
    }
    else if(s[i] == 'L'){
        ans += solve(s,vis,i+1,row, col-1);
    }
    else if(s[i] == 'D'){
        ans += solve(s,vis,i+1,row+1, col);
    }
    vis[row][col] = 0;
    return ans;
}
int main(){
    string s;
    cin>>s;
    vector<vector<int>> vis(7,vector<int>(7,0));
    cout<<solve(s,vis,0,0,0);
    return 0;
}