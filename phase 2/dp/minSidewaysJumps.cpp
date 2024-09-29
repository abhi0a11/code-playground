#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& obstacles, int currlane, int currpos){
    int n = obstacles.size()-1;
    if(currpos == n){
        return 0;
    }

    if(obstacles[currpos+1] != currlane){
        return solve(obstacles, currlane, currpos+1);
    }
    else{
        //sideways jump
        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i)
                ans = min(ans, 1 + solve(obstacles,i,currpos));
        }
        return ans;
    }
}
int solveMem(vector<int>& obstacles, int currlane, int currpos,vector<vector<int>>& dp){
    int n = obstacles.size()-1;
    if(currpos == n){
        return 0;
    }

    if(dp[currpos][currlane] != -1) return dp[currpos][currlane];
    
    if(obstacles[currpos+1] != currlane){
        return solveMem(obstacles, currlane, currpos+1,dp);
    }
    else{
        //sideways jump
        int ans = INT_MAX;
        for(int i=1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i)
                ans = min(ans, 1 + solveMem(obstacles,i,currpos,dp));
        }
        dp[currpos][currlane] = ans;
        return dp[currpos][currlane]; 
    }
}
int solveTab(vector<int>& obstacles){
    int n = obstacles.size();
    vector<vector<int>>dp(4, vector<int> (obstacles.size(), 1e9));

    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int currpos = n-1; currpos>=0; currpos--){
        for(int currlane = 1; currlane <=3; currlane++){
            if(obstacles[currpos+1] != currlane){
                dp[currlane][currpos] = dp[currlane][currpos+1];
            }
            else{
                //sideways jump
                int ans = 1e9;
                for(int i=1; i<=3; i++){
                    if(currlane != i && obstacles[currpos] != i)
                        ans = min(ans, 1 + dp[currlane][currpos+1]);
                }
                dp[currpos][currlane] = ans;
            }
        }
    }

    return min(dp[2][0],min(dp[1][0] +1, dp[3][0]+1));
}
int solveSO(vector<int>& obstacles){
    int n = obstacles.size();
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for(int currpos = n-1; currpos>=0; currpos--){
        for(int currlane = 1; currlane <=3; currlane++){
            if(obstacles[currpos+1] != currlane){
                curr[currlane] = next[currlane];
            }
            else{
                //sideways jump
                int ans = 1e9;
                for(int i=1; i<=3; i++){
                    if(currlane != i && obstacles[currpos] != i)
                        ans = min(ans, 1 + next[currlane]);
                }
                curr[currpos] = ans;
            }
        }
        next = curr;
    }

    return min(next[2],min(next[1] +1, next[3]+1));
}

int minSideJumps(vector<int>& obstacles){
    // return solve(obstacles,2,0);

    // vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));
    // return solveMem(obstacles,2,0,dp);

    return solveTab(obstacles);
}
int main(){
    
    return 0;
}