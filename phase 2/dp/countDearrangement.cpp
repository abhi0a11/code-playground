#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define mod 100000007
/*
long long int solve(int n){
    if(n==1)    return 0;
    if(n==2)    return 1;

    int ans = ((((n-1)%mod)*((countDearangements(n-2)%mod) + (countDearangements(n-1)%mod)%mod))%mod);

    return ans;
}
*/
/*
long long int solveMem(int n, vector<long long int>& dp){
    if(n==1)    return 0;
    if(n==2)    return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = ( ((n-1)%mod)*((solveMem(n-2,dp)%mod) + (solveMem(n-1,dp)%mod))%mod);

    return dp[n];
}

*/
/*
long long int solveTab(int n){
    vector<long long int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<n; i++){
        long long int first = dp[i-1]%mod;
        long long int second = dp[i-2]%mod;
        long long int sum = (first + second)%mod;

        long long int ans = ((i-1)*sum)%mod;
        dp[i] = ans;

    }
    return dp[n];
}
*/
long long int solvespaceOptimise(int n){
    
    long long int prev2 = 0;
    long long int prev1 = 1;

    for(int i=3; i<n; i++){
        long long int first = prev1%mod;
        long long int second = prev2%mod;
        long long int sum = (first + second)%mod;

        long long int ans = ((i-1)*sum)%mod;
        
        prev2 = prev1;
        prev1 = ans;

    }
    return prev1;
}

long long int countDearangements(int n){

    // return solve(n);

    // vector<long long int> dp(n+1,-1);
    // return solveMem(n,dp);

    // return solveTab(n);

    return solvespaceOptimise(n);
}

int main(){
    
    return 0;
}