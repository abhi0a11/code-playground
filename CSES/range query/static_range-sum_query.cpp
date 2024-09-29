#include<bits/stdc++.h>
using namespace std;
#define ll long long
class segmentTree {
    vector<ll> seg;
public:
    segmentTree(int n) {
        seg.resize(4 * n);
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

    ll query(int i, int low, int high, int l, int h) {
        if (low > h || high < l) return 0;
        if (l <= low && high <= h)   return seg[i];

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
        int u, v; cin >> u >> v;
        cout << st.query(0, 0, n - 1, u - 1, v - 1) << endl;
    }
    return 0;
}