#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    queue<pair<int, pair<int, int>>> q;
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            if (ch == '.')   grid[i][j] = 1;
            else if (ch == 'M') {
                q.push({ i,{j,0} });
            }
            else if (ch == 'A') {
                sx = i, sy = j;
            }
        }
    }

    vector<vector<int>> distMonster(n, vector<int>(m, 1e8));
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    char dir[4] = { 'R','L','D','U' };

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int steps = q.front().second.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            char di = dir[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && steps + 1 < distMonster[nx][ny]) {
                distMonster[nx][ny] = steps + 1;
                q.push({ nx,{ny,steps + 1} });
            }
        }
    }


    q.push({ sx,{sy,0} });
    vector<vector<char>> step(n, vector<char>(m, '.'));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[sx][sy] = 1;
    step[sx][sy] = 'X';
    bool flag = false;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int steps = q.front().second.second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            char di = dir[k];

            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                string ans = "";
                while (step[x][y] != 'X') {
                    char ch = step[x][y];
                    if (ch == 'X')  break;
                    ans += ch;

                    if (ch == 'U') x++;
                    else if (ch == 'D')  x--;
                    else if (ch == 'R')  y--;
                    else if (ch == 'L')  y++;
                }
                cout << "YES" << endl;
                cout << ans.size() << endl;
                reverse(ans.begin(), ans.end());
                cout << ans << endl;
                flag = 1;
                break;
            }

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && steps + 1 < distMonster[nx][ny] && !vis[nx][ny]) {
                step[nx][ny] = di;
                vis[nx][ny] = 1;
                q.push({ nx,{ny,steps + 1} });
            }
        }
        if (flag)    break;
    }


    if (!flag)   cout << "NO";
    return 0;
}