#include<bits/stdc++.h>
using namespace std;

void updateMatrix(int x, vector<vector<int>>& arr) {
    int cnt = 5;

    while (x > 0 && cnt > 0) {
        for (int i = 0; i < 5; i++) {
            if (arr[x][i] == 2)  arr[x][i] = 0;
        }
        x--;
        cnt--;
    }

}
int dfs(int row, int col, vector<vector<int>>& arr, int bomb) {
    if (row <= 0)   return 0;

    int ans = 0;
    for (int k = -1; k <= 1; k++) {
        int c = col + k;
        if (row > 0 && c >= 0 && c < 5 && arr[row - 1][c] != 2) {
            ans = max(ans, arr[row - 1][c] + dfs(row - 1, c, arr, bomb));
        }
    }

    if (ans == 0 && bomb > 0) {
        updateMatrix(row - 1, arr);
        ans = dfs(row, col, arr, bomb - 1);
    }

    return ans;
}
int main() {
    int t; cin >> t;
    int tc = 0;
    while (t--) {
        int n;cin >> n;
        vector<vector<int>> arr(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> arr[i][j];
            }
        }
        tc++;
        cout << "#" << tc << " " << dfs(n, 2, arr, 1) << endl;;
    }
    return 0;
}