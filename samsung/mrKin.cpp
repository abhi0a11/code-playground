#include <bits/stdc++.h>

using namespace std;
int ans = INT_MAX;

void dfs(vector<int>& vis, vector<pair<int, int>>& arr, int n, int x, int cost, int cnt) {
    if (cnt == n) {
        int temp = abs(arr[x].first - arr[n + 1].first) + abs(arr[x].second - arr[n + 1].second);
        ans = min(ans, cost + temp);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            int temp = abs(arr[x].first - arr[i].first) + abs(arr[x].second - arr[i].second);
            dfs(vis, arr, n, i, cost + temp, cnt + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    int t = 10;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> arr(n + 2);
        cin >> arr[0].first;
        cin >> arr[0].second;

        cin >> arr[n + 1].first;
        cin >> arr[n + 1].second;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first;
            cin >> arr[i].second;
        }

        vector<int> vis(n + 2, 0);
        ans = INT_MAX;
        dfs(vis, arr, n, 0, 0, 0);
        cout << "# " << 10 - t << " " << ans << endl;
    }
    return 0;
}
