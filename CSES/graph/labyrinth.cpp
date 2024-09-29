#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    ll sx = 0, sy = 0;
    ll ex = 0, ey = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char ch; cin >> ch;
            if (ch == '.')   grid[i][j] = 1;
            else if (ch == 'A') {
                sx = i;
                sy = j;
                grid[i][j] = 1;
            }
            else if (ch == 'B') {
                ex = i;
                ey = j;
                grid[i][j] = 1;
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    char dir[4] = { 'R','L','D','U' };
    bool flag = false;
    vector<vector<char>> steps(n, vector<char>(m, '.'));
    queue<pair<ll, ll>> q;
    vis[sx][sy] = 1;
    q.push({ sx,sy });
    steps[sx][sy] = 'X';
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == ex && y == ey) {
            flag = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({ nx,ny });
                steps[nx][ny] = dir[k];
            }
        }

    }
    if (!flag) cout << "NO";
    else {
        cout << "YES" << endl;
        stack<char> ans;
        while (steps[ex][ey] != 'X') {
            char ch = steps[ex][ey];
            if (ch == 'X')   break;
            ans.push(ch);
            if (ch == 'U') {
                ex++;
            }
            else if (ch == 'D') {
                ex--;
            }
            else if (ch == 'L') {
                ey++;
            }
            else if (ch == 'R') {
                ey--;
            }
        }
        cout << ans.size() << endl;
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
    }
    return 0;
}

