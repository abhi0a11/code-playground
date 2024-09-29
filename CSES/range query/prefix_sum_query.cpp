#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
    ll prefSum = 0;
    ll maxPref = 0;
};
class segmentTree {
    vector<Node> seg;
public:
    segmentTree(int n) {
        seg.resize(4 * n);
    }


    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind].prefSum = arr[low];
            seg[ind].maxPref = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind].prefSum = seg[2 * ind + 1].prefSum + seg[2 * ind + 2].prefSum;
        seg[ind].maxPref = max(seg[2 * ind + 1].maxPref, seg[2 * ind + 1].prefSum + seg[2 * ind + 2].maxPref);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind].prefSum = val;
            seg[ind].maxPref = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        }
        else    update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind].prefSum = seg[2 * ind + 1].prefSum + seg[2 * ind + 2].prefSum;
        seg[ind].maxPref = max(seg[2 * ind + 1].maxPref, seg[2 * ind + 1].prefSum + seg[2 * ind + 2].maxPref);
    }
    Node query(int ind, int low, int high, int l, int h) {
        if (h < low || high < l) return Node();
        if (l <= low && high <= h)   return seg[ind];

        int mid = (low + high) >> 1;
        Node left = query(2 * ind + 1, low, mid, l, h);
        Node right = query(2 * ind + 2, mid + 1, high, l, h);

        Node ans;
        ans.prefSum = left.prefSum + right.prefSum;
        ans.maxPref = max(left.maxPref, left.prefSum + right.maxPref);

        return ans;
    }

};
int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    segmentTree st(n);
    st.build(0, 0, n - 1, arr);

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int a, b; cin >> a >> b;
            st.update(0, 0, n - 1, a - 1, b);
        }
        else {
            int a, b; cin >> a >> b;
            cout << max(0LL, st.query(0, 0, n - 1, a - 1, b - 1).maxPref) << endl;
        }
    }

    return 0;
}