#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums, int n){
    //base case
    if(n < 0)     return 0;
    if(n == 0)    return nums[0];

    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1) + 0;

    return max(incl,excl);
}

int solveTab(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl,excl);
    }

    return dp[n-1];
}
//space optimasation
int solveSpaceOptimisation(vector<int>& nums){
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl,excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    //  int n = nums.size();
    //  int ans = solve(nums,n-1);
    //  return ans;


    // return solveTab(nums);

    return solveSpaceOptimisation(nums);
}
int main(){

    return 0;
}
