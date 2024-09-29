#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(long long nStairs,int i){
    //base case 
    if(i == nStairs)  return 1;
    if(i> nStairs)  return 0;

    return (solve(nStairs,i+1) + solve(nStairs,i+2));
}
 
int countDistinctWays(long long nStairs){
    return solve(nStairs,0);
}
int main(){
    
    return 0;
}