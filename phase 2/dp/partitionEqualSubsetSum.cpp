#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int N, int arr[],int target){
    //base case
    if(index >= N)  return 0;
    if(target < 0)  return 0;
    if(target == 0) return 1;

    int incl = solve(index+1,N,arr,target-arr[index]);
    int excl = solve(index+1,N,arr,target);

    return (incl || excl);
}
bool solveMem(int index, int N, int arr[],int target,vector<vector<int>>& dp){
    //base case
    if(index >= N)  return 0;
    if(target < 0)  return 0;
    if(target == 0) return 1;;

    if(dp[index][target] != -1) return dp[index][target];

    bool incl = solveMem(index+1,N,arr,target-arr[index],dp);
    bool excl = solveMem(index+1,N,arr,target,dp);

    return dp[index][target] = (incl or excl);
}
bool solveTab(int N, int arr[],int t){
    vector<vector<int>> dp(N+1,vector<int>(t+1,0));
    
    for(int i=0; i<=N; i++){
        dp[i][0] = 1;
    }

    for(int index = N-1; index >= 0; index--){
        for(int target = 0; target <= t; target++){
            bool incl = 0;
            if(target - arr[index] >= 0)
                incl = dp[index+1][target-arr[index]];
            bool excl = dp[index+1][target];

            dp[index][target] = (incl | excl);
        }
    }
    return dp[0][t];
}
bool solveSO(int N, int arr[],int t){
    vector<int> curr(t+1,0);
    vector<int> next(t+1,0);
    
    curr[0] = 1;
    next[0] = 1;


    for(int index = N-1; index >= 0; index--){
        for(int target = 0; target <= t; target++){
            bool incl = 0;
            if(target - arr[index] >= 0)
                incl = next[target-arr[index]];
            bool excl = next[target];

            curr[target] = (incl || excl);
        }
        next = curr;
    }
    return next[t];
}

int equalPartition(int N, int arr[]){
    int total = 0;
    for(int i=0; i<N; i++){
        total += arr[i];
    }

    if(total & 1)   return 0;

    int target = total/2;
    // return solve(0,N,arr,target);

    // vector<vector<int>> dp(N+1,vector<int>(target+1,-1));
    // return solveMem(0,N,arr,target,dp);

    // return solveTab(N,arr,target);
    return solveSO(N,arr,target);
}


int main(){
    int arr[] = {1,5,11,5};
    cout<<equalPartition(4,arr);
    return 0;
}