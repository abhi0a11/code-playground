#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
int solve(vector<int>& weight, vector<int>& value, int index, int capacity)
{
    //base case
    //if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index == 0){
        if(weight[0] <= capacity)  return value[0];
        else    return 0;
    }
    int include = 0;
    
    if(weight[index] <= capacity){
        include =value[index] + solve(weight, value, index-1, capacity-weight[index]);
    }

    int exclude = 0 + solve(weight,value,index-1,capacity);
    int ans = max(include,exclude);

    return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight,value,n-1,maxWeight);
}
*/

/*
int solve(vector<int>& weight, vector<int>& value, int index, int capacity,vector<vector<int>>& dp)
{
    //base case
    //if only 1 item to steal, then just compare its weight with the knapsack capacity
    if(index == 0){
        if(weight[0] <= capacity)  return value[0];
        else    return 0;
    }

    if(dp[index][capacity] != -1)   return dp[index][capacity];

    int include = 0;
    if(weight[index] <= capacity){
        include =value[index] + solve(weight, value, index-1, capacity-weight[index],dp);
    }

    int exclude = 0 + solve(weight,value,index-1,capacity,dp);
    dp[index][capacity] = max(include,exclude);

    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1, -1));
    return solve(weight,value,n-1,maxWeight,dp);
}
*/

/*
int solveTab(vector<int>& weight, vector<int>& value, int n, int capacity)
{
    //step1
    vector<vector<int>>dp(n,vector<int>(capacity+1, 0));

    //step 2: analyse base case
    for(int w = weight[0]; w<=capacity; w++){
        if(weight[0] <= capacity)  dp[0][w] = value[0];
        else    dp[0][w] = 0;
    }

    // step 3: remaining recursive calls

    for(int index = 1; index<n; index++){
        for(int w = 0; w<=capacity;w++){

            int include = 0;

            if(weight[index] <= w){
                include =value[index] + dp[index-1][w-weight[index]];
            }

            int exclude = 0 + dp[index-1][w];
            dp[index][w] = max(include,exclude);
        }
    }

    return dp[n-1][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solveTab(weight,value,n-1,maxWeight);
}
*/
/*
// space optimised with two array
int solveSO(vector<int>& weight, vector<int>& value, int n, int capacity)
{
    //step1
    vector<int> prev(capacity+1,0);
    vector<int> curr(capacity+1,0);

    //step 2: analyse base case
    for(int w = weight[0]; w<=capacity; w++){
        if(weight[0] <= capacity)  prev[w] = value[0];
        else    prev[w] = 0;
    }

    // step 3: remaining recursive calls

    for(int index = 1; index<n; index++){
        for(int w = 0; w<=capacity;w++){

            int include = 0;

            if(weight[index] <= w){
                include =value[index] + prev[w-weight[index]];
            }

            int exclude = 0 + prev[w];
            curr[w] = max(include,exclude);
        }
        prev = curr;
    }

    return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solveSO(weight,value,n-1,maxWeight);
}
*/


// space optimised with single array
int solveSO(vector<int>& weight, vector<int>& value, int n, int capacity)
{
    //step1
    vector<int> curr(capacity+1,0);

    //step 2: analyse base case
    for(int w = weight[0]; w<=capacity; w++){
        if(weight[0] <= capacity)  curr[w] = value[0];
        else    curr[w] = 0;
    }

    // step 3: remaining recursive calls

    for(int index = 1; index<n; index++){
        //reverse the direction of loop
        for(int w = capacity; w>=0; w--){

            int include = 0;

            if(weight[index] <= w){
                include =value[index] + curr[w-weight[index]];
            }

            int exclude = 0 + curr[w];
            curr[w] = max(include,exclude);
        }
        
    }

    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solveSO(weight,value,n-1,maxWeight);
}
int main()
{

    return 0;
}

/* more problems on same pattern -
equal subset sum partition
minimum subset sum difference
count of subset sum 
target sum 
subset sum 
*/