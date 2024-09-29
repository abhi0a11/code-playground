#include<bits/stdc++.h>
using namespace std;
#define ll long long
class segmentTree {
    vector<ll> seg;
public:
    segmentTree(int n) {
        seg.resize(4 * n);
    }

    void build(int ind, vector<ll>& arr, int l, int h) {
        if (l == h) {
            seg[ind] = arr[l];
            return;
        }

        int mid = (l + h) >> 1;
        build(2 * ind + 1, arr, l, mid);
        build(2 * ind + 2, arr, mid + 1, h);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    ll query(int ind, int low, int high, int l, int h) {
        if (high < l || h < low) return INT_MAX;
        if (l <= low && high <= h)   return seg[ind];

        int mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, h);
        ll right = query(2 * ind + 2, mid + 1, high, l, h);

        return min(left, right);
    }
    void update(int ind, int low, int high, int i, ll val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else    update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 2], seg[2 * ind + 1]);
    }
};
int main() {
    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];
    segmentTree st(n);
    st.build(0, arr, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int u, v, w; cin >> u >> v >> w;
        if (u == 1) {
            st.update(0, 0, n - 1, v - 1, w);
        }
        else {
            cout << st.query(0, 0, n - 1, v - 1, w - 1) << endl;
        }
    }
    return 0;
}