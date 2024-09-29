#include<bits/stdc++.h>
using namespace std;
// bool f(vector<int>& coins, int i, int sum) {
//     if (sum == 0)    return 1;
//     if (sum < 0)  return 0;
//     if (i == 0)    return sum == coins[0];

//     bool pick = f(coins, i - 1, sum - coins[i]);
//     bool notpick = f(coins, i - 1, sum);

//     return pick | notpick;
// }
int main() {
    int n; cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)  cin >> coins[i];
    set<int> st;
    int sum = accumulate(coins.begin(), coins.end(), 0);


    // cout << f(coins, n - 1, sum);


    //TABULATE

    vector <vector<int>> dp(n, vector<int>(sum + 1, 0));

    dp[0][coins[0]] = 1;
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {

            bool pick = j - coins[i] >= 0 ? dp[i - 1][j - coins[i]] : 0;
            bool notpick = dp[i - 1][j];

            dp[i][j] = pick | notpick;
        }
    }


    int cnt = 0;
    for (int j = 1; j <= sum; j++) {
        if (dp[n - 1][j])   cnt++;
    }
    cout << cnt << endl;
    for (int j = 1; j <= sum; j++) {
        if (dp[n - 1][j])   cout << j << " ";
    }

    return 0;
}