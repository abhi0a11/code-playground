#include<bits/stdc++.h>
using namespace std;
long solve(long K){
    long totalWays = ( K * K * (K * K - 1)) / 2;

    // Number of ways two knights can attack each other
    long attackingWays = 4 * (K - 1) * (K - 2);

    // Number of ways two knights can be placed without
    // attacking each other
    long ans = totalWays - attackingWays;

    // Return the result for the current chessboard size K
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(long i=1; i<=n; i++){
        cout<<solve(i)<<endl;
    }
    return 0;
}