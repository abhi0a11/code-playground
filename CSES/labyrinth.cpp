#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '.'));

    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sx = i, sy = j;
            }
            if (grid[i][j] == 'B') {
                ex = i, ey = j;
            }
        }
    }
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, { -1,-1 }));
    vector<vector<char>> action(n, vector<char>(m, '.'));

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    q.push({ sx,sy });
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (vis[x][y]) continue;
        vis[x][y] = 1;

        if (x == ex && y == ey) {
            cout << "YES" << endl;
            string path = "";
            int i = x, j = y;
            while (i > 0 && j > 0) {
                if (action[i][j] != '.')  path = action[i][j] + path;

                int X = par[i][j].first;
                int Y = par[i][j].second;
                i = X, j = Y;
            }
            cout << path.size() << endl << path;

            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         cout << "(" << par[i][j].first << ", " << par[i][j].second << ") ";
            //     }cout << endl;
            // }
            return 0;
        }

        if (x + 1 < n && grid[x + 1][y] != '#' && !vis[x + 1][y]) {
            q.push({ x + 1,y });
            if (action[x + 1][y] == '.') {
                par[x + 1][y] = { x,y };
                action[x + 1][y] = 'D';
            }
        }
        if (x > 0 && grid[x - 1][y] != '#' && !vis[x - 1][y]) {
            q.push({ x - 1,y });
            if (action[x - 1][y] == '.') {
                par[x - 1][y] = { x,y };
                action[x - 1][y] = 'U';
            }
        }
        if (y > 0 && grid[x][y - 1] != '#' && !vis[x][y - 1]) {
            q.push({ x ,y - 1 });
            if (action[x][y - 1] == '.') {
                par[x][y - 1] = { x,y };
                action[x][y - 1] = 'L';
            }
        }
        if (y + 1 < m && grid[x][y + 1] != '#' && !vis[x][y + 1]) {
            q.push({ x ,y + 1 });
            if (action[x][y + 1] == '.') {
                par[x][y + 1] = { x,y };
                action[x][y + 1] = 'R';
            }
        }

    }
    cout << "NO";
    return 0;
}