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

// #include<bits/stdc++.h>
// using namespace std;
// class SegTree {
// public:
//     long long len;
//     vector<bool> isLazy;
//     vector<long long> t, unpropUpd;
//     SegTree(long long l) {
//         len = l;
//         t.resize(4 * len);
//         isLazy.resize(4 * len);
//         unpropUpd.resize(4 * len);
//     }
//     void apply(long long v, long long tl, long long tr, long long val) {
//         if (tl != tr) {
//             isLazy[v] = true;
//             unpropUpd[v] += val;
//         }
//         t[v] += (tr - tl + 1) * val;
//     }
//     void pushdown(long long v, long long tl, long long tr) {
//         if (!isLazy[v])return;
//         isLazy[v] = false;
//         long long tm = (tl + tr) / 2;
//         apply(2 * v, tl, tm, unpropUpd[v]);
//         apply(2 * v + 1, tm + 1, tr, unpropUpd[v]);
//         unpropUpd[v] = 0;
//     }
//     void build(vector<long long>& a, long long v, long long tl, long long tr) {
//         if (tl == tr) {
//             t[v] = a[tl];
//             return;
//         }
//         long long tm = (tl + tr) / 2;
//         build(a, 2 * v, tl, tm);
//         build(a, 2 * v + 1, tm + 1, tr);
//         t[v] = t[2 * v] + t[2 * v + 1];
//     }
//     long long query(long long v, long long tl, long long tr, long long l, long long r) {
//         if (tl > r || tr < l)return 0;
//         if (tl >= l && tr <= r)return t[v];
//         pushdown(v, tl, tr);
//         long long tm = (tl + tr) / 2;
//         long long leftAns = query(2 * v, tl, tm, l, r);
//         long long rightAns = query(2 * v + 1, tm + 1, tr, l, r);
//         return leftAns + rightAns;
//     }
//     void update(long long v, long long tl, long long tr, long long l, long long r, long long val) {
//         if (tl >= l && tr <= r) {
//             apply(v, tl, tr, val);
//             return;
//         }
//         if (tl > r || tr < l)return;
//         long long tm = (tl + tr) / 2;
//         update(2 * v, tl, tm, l, r, val);
//         update(2 * v + 1, tm + 1, tr, l, r, val);
//         t[v] = t[2 * v] + t[2 * v + 1];
//     }
//     void build(vector<long long>& a) {
//         build(a, 1, 0, len - 1);
//     }

//     long long query(long long l, long long r) {
//         return query(1, 0, len - 1, l, r);
//     }

//     void update(long long l, long long r, long long val) {
//         update(1, 0, len - 1, l, r, val);
//     }
// };
// int main() {
//     long long n, q;
//     cin >> n >> q;
//     vector<long long> arr(n);
//     for (long long i = 0;i < n;i++)cin >> arr[i];
//     SegTree segtree(n);
//     segtree.build(arr);
//     for (long long i = 0;i < q;i++) {
//         long long t;
//         cin >> t;
//         if (t == 1) {
//             long long a, b, u;
//             cin >> a >> b >> u;
//             segtree.update(a - 1, b - 1, u);
//         }
//         else {
//             long long k;
//             cin >> k;
//             cout << segtree.query(k - 1, k - 1) << endl;
//         }
//     }
//     return 0;
// }