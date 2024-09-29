#include<bits/stdc++.h>
using namespace std;
class segmentTree {
    vector<int> seg;
public:
    segmentTree(int n) {
        seg.resize(4 * n);
    }

    void build(int ind, int l, int h, vector<int>& arr) {
        if (l == h) {
            seg[ind] = arr[l];
            return;
        }

        int mid = (l + h) >> 1;
        build(2 * ind + 1, l, mid, arr);
        build(2 * ind + 2, mid + 1, h, arr);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int query(int ind, int low, int high, int val) {
        if (low == high) return low;

        int mid = (low + high) >> 1;
        if (seg[2 * ind + 1] >= val)
            return query(2 * ind + 1, low, mid, val);
        else
            return query(2 * ind + 2, mid + 1, high, val);

    }
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else    update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = max(seg[2 * ind + 2], seg[2 * ind + 1]);
    }
    bool isValid(int val) {
        return seg[0] >= val;
    }
};
int main() {
    int n, q;cin >> n >> q;
    vector<int> hotel(n);
    for (int i = 0; i < n; i++)  cin >> hotel[i];

    segmentTree st(n);
    st.build(0, 0, n - 1, hotel);
    for (int i = 0; i < q; i++) {
        int room; cin >> room;
        if (!st.isValid(room))   cout << 0 << " ";
        else {
            int ind = st.query(0, 0, n - 1, room);
            hotel[ind] -= room;
            st.update(0, 0, n - 1, ind, hotel[ind]);
            cout << ind + 1 << " ";
        }
    }

    return 0;
}