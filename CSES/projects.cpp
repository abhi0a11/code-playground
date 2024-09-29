#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct project {
    ll start, end, money;
};
// bool cmp(project a, project b) {
//     return a.end < b.end;
// }
ll searchProject(vector<project>& arr, ll i) {
    ll l = 0;
    ll h = i - 1;

    while (l <= h) {
        ll mid = (h + l) / 2;

        if (arr[mid].end < arr[i].start) {
            if (arr[mid + 1].end < arr[i].start) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            h = mid - 1;
        }
    }
    return -1;
}
int main() {
    ll n;cin >> n;
    vector<project> arr;

    for (ll i = 0; i < n; i++) {
        project p;
        cin >> p.start >> p.end >> p.money;
        arr.push_back(p);
    }

    auto cmp = [&](auto& a, auto& b) {
        return a.end < b.end;
        };

    sort(arr.begin(), arr.end(), cmp);

    vector<ll> dp(n);
    dp[0] = arr[0].money;

    for (ll i = 1; i < n; i++) {
        ll temp = arr[i].money;
        ll nextProject = searchProject(arr, i);

        if (nextProject != -1) {
            temp += dp[nextProject];
        }

        dp[i] = max(temp, dp[i - 1]);
    }

    cout << dp[n - 1];
    return 0;
}