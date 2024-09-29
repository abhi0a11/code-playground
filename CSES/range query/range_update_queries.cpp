#include<bits/stdc++.h>
using namespace std;
#define ll long long

class segmentTree {
    vector<ll> seg, unpropagatedValue;
    vector<bool> isLazy;
public:
    segmentTree(int n) {
        seg.resize(4 * n);
        isLazy.resize(4 * n);
        unpropagatedValue.resize(4 * n);
    }
    void apply(int ind, int low, int high, ll unpropagatedVal) {
        if (low != high) {
            isLazy[ind] = 1;
            unpropagatedValue[ind] += unpropagatedVal;
        }

        seg[ind] += (high - low + 1) * unpropagatedVal;
    }
    void pushDown(int ind, int low, int high) {
        if (!isLazy[ind]) return;
        isLazy[ind] = 0;

        int mid = (low + high) >> 1;
        apply(2 * ind + 1, low, mid, unpropagatedValue[ind]);
        apply(2 * ind + 2, mid + 1, high, unpropagatedValue[ind]);

        unpropagatedValue[ind] = 0;
    }
    void build(int i, vector<ll>& arr, int l, int h) {
        if (l == h) {
            seg[i] = arr[l];
            return;
        }

        int mid = (l + h) >> 1;

        build(2 * i + 1, arr, l, mid);
        build(2 * i + 2, arr, mid + 1, h);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    void update(int ind, int low, int high, int l, int h, ll val) {
        if (h < low || high < l) return;
        if (l <= low && high <= h) {
            apply(ind, low, high, val);
            return;
        }


        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, h, val);
        update(2 * ind + 2, mid + 1, high, l, h, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    ll query(int i, int low, int high, int l, int h) {
        if (low > h || high < l) return 0;
        if (l <= low && high <= h)   return seg[i];

        pushDown(i, low, high);

        int mid = (low + high) >> 1;
        ll left = query(2 * i + 1, low, mid, l, h);
        ll right = query(2 * i + 2, mid + 1, high, l, h);

        return left + right;
    }

};
int main() {
    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];
    segmentTree st(n);

    st.build(0, arr, 0, n - 1);
    for (int i = 0;i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            ll w; cin >> w;
            st.update(0, 0, n - 1, u - 1, v - 1, w);
        }
        else {
            int k; cin >> k;
            cout << st.query(0, 0, n - 1, k - 1, k - 1) << endl;
        }
    }
    return 0;
}