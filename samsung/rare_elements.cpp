#include<bits/stdc++.h>
using namespace std;
void bfs(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dist, int n) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{i,j} });
    dist[i][j] = 0;

    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };

    while (!q.empty()) {
        int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[x][y] == 1 && 1 + dist[x][y] < dist[nx][ny]) {
                dist[nx][ny] = 1 + dist[x][y];
                q.push({ dist[nx][ny],{nx,ny} });
            }
        }
    }

}
int main() {
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int, int>> rare(q);
        for (int i = 0; i < q;i++) {
            int x, y; cin >> x >> y;
            rare[i] = { x - 1,y - 1 };
        }

        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    vector<vector<int>> dist(n, vector<int>(n + 1, 1e9));
                    bfs(i, j, arr, dist, n);

                    bool chk = 1;
                    int maxi = INT_MIN;
                    for (int k = 0; k < q; k++) {
                        if (dist[rare[k].first][rare[k].second] == 1e9) {
                            chk = 0;
                            break;
                        }
                        else {
                            maxi = max(maxi, dist[rare[k].first][rare[k].second]);
                        }
                    }

                    if (!chk) {
                        ans = -1;
                    }
                    ans = min(ans, maxi);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}