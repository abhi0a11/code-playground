#include<bits/stdc++.h>
using namespace std;
// vector<int> getPrime(int m) {
//     int cnt = 0;
//     vector<int> ans;

//     for (int i = 2; i <= 1e4; i++) {
//         bool chk = 1;
//         for (int j = 2; j * j <= i; j++) {
//             if (i % j == 0) {
//                 chk = 0;
//                 break;
//             }
//         }
//         if (chk) {
//             cnt++;
//             if (cnt <= m) {
//                 ans.push_back(i);
//             }
//             else {
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }
vector<int> sieveAlgorithm(int n, int m) {
    int cnt = 0;
    vector<bool> isPrime(n + 1, 1);
    vector<int> ans;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            cnt++;
            if (cnt <= m) {
                ans.push_back(i);
            }
            else break;

            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return ans;
}
int solve(int n, int m, vector<int>& prime) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,n });

    while (!pq.empty()) {
        int count = pq.top().first;
        int num = pq.top().second;
        pq.pop();

        if (num == 0) {
            return count;
        }
        for (auto val : prime) {
            if (val <= num) {
                pq.push({ count + 1,num - val });
            }
            else break;
        }
    }
    return -1;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> prime = sieveAlgorithm(n, m);
    cout << solve(n, m, prime);
    return 0;
}