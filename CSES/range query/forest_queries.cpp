#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, q; cin >> n >> q;
    vector<vector<ll>> forest(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch; cin >> ch;
            if (ch == '*')   forest[i][j] = 1;

            if (j > 0) {
                forest[i][j] += forest[i][j - 1];
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            forest[i][j] += forest[i - 1][j];
        }
    }

    for (int i = 0; i < q; i++) {
        ll ans = 0;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        ans += forest[x2][y2];
        if (y1 > 0) {
            ll temp = 0;
            temp += (forest[x2][y1 - 1]);
            if (x1 > 0) temp -= forest[x1 - 1][y1 - 1];
            ans -= temp;
        }
        if (x1 > 0) {
            ans -= forest[x1 - 1][y2];
        }
        cout << ans << endl;
    }

    return 0;
}