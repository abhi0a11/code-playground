#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
//top down approach
int fib(int n, vector<int>& dp){
    if(n<=1)  return n;

    //step 3
    if(dp[n] != -1) return dp[n];

    //step 2
    dp[n] = fib(n-1,dp) + fib(n-2,dp);

    return dp[n];
}
*/

// bootom up approach (tabulation)

int fib(int n , vector<int>& dp){
    dp[1] = 1;
    dp[0] = 0;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
int main(){
    
    //top down approach
    // int n;
    
    // cin>>n;

    // //step 1:
    // vector<int> dp(n+1);
    // for(int i=0; i<=n;i++) // no need of this step in bottom down approach
    //      dp[i] =-1;

    // cout<< fib(n,dp) <<endl;
    
    //space optimisation

    int n;
    cin>>n;

    int prev1 = 1;
    int prev2 = 0;

    if(n==0)    return prev2;

    for(int i=2;i<=n;i++){
        int curr = prev1+prev2;

        prev2 = prev1;
        prev1 = curr;
    }
    cout<<prev1<<endl;

    return 0;
}