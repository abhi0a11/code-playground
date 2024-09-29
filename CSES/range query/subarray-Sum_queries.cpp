#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Node {
public:
    ll sum, g_sum;
    ll l_sum, r_sum;
    Node() {
        sum = g_sum = 0;
        l_sum = r_sum = 0;
    }
};
class SegTree {
public:
    int len;
    vector<Node> t;
    SegTree(int l) {
        len = l;
        t.resize(4 * len);
    }
    void merge(int v) {
        t[v].sum = t[2 * v].sum + t[2 * v + 1].sum;
        t[v].l_sum = max(t[2 * v].l_sum, t[2 * v].sum + t[2 * v + 1].l_sum);
        t[v].r_sum = max(t[2 * v + 1].r_sum, t[2 * v + 1].sum + t[2 * v].r_sum);
        t[v].g_sum = max({ t[2 * v].g_sum,t[2 * v + 1].g_sum,t[2 * v].r_sum + t[2 * v + 1].l_sum });
    }
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v].sum = t[v].g_sum = a[tl];
            t[v].l_sum = t[v].r_sum = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        merge(v);
    }
    void update(int v, int tl, int tr, int ind, int val) {
        if (tl > ind || tr < ind)return;
        if (tl == ind && ind == tr) {
            t[v].sum = t[v].g_sum = val;
            t[v].l_sum = t[v].r_sum = val;
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, ind, val);
        update(2 * v + 1, tm + 1, tr, ind, val);
        merge(v);
    }
    void build(vector<int>& a) {
        build(a, 1, 0, len - 1);
    }
    void update(int ind, int val) {
        update(1, 0, len - 1, ind, val);
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0;i < n;i++)cin >> arr[i];
    SegTree segtree(n);
    segtree.build(arr);
    for (int i = 0;i < q;i++) {
        int k, x;
        cin >> k >> x;
        segtree.update(k - 1, x);
        cout << max((ll)0, segtree.t[1].g_sum) << endl;
    }
    return 0;
}