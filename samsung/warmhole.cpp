#include <bits/stdc++.h>

using namespace std;
int d(int x, int y, int a, int b) {
    return (abs(a - x) + abs(b - y));
}
void solve(int x, int y, int a, int b, vector<vector<int>>& arr, vector<int>& vis, int& ans, int cost) {
    ans = min(ans, d(x, y, a, b) + cost);

    for (int i = 0; i < (int)arr.size(); i++) {
        if (!vis[i]) {
            vis[i] = 1;

            int val = d(x, y, arr[i][0], arr[i][1]) + arr[i][4];
            solve(arr[i][2], arr[i][3], a, b, arr, vis, ans, cost + val);

            val = d(x, y, arr[i][2], arr[i][3]) + arr[i][4];
            solve(arr[i][0], arr[i][1], a, b, arr, vis, ans, cost + val);

            vis[i] = 0;
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int a, b, c, d, e;cin >> a >> b >> c >> d >> e;
            arr[i] = { a,b,c,d,e };
        }
        vector<int> vis(n, 0);
        int ans = INT_MAX;
        solve(sx, sy, dx, dy, arr, vis, ans, 0);
        cout << ans << endl;
    }
    return 0;
}
