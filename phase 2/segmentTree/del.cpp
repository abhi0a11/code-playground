#include<bits/stdc++.h>
using namespace std;
class segmentTree {
    vector<int> seg;
public:
    segmentTree(int n) {
        seg.resize(4 * n);
    }

    void build(vector<int> arr, int i, int j, int ind) {
        if (i == j) {
            seg[ind] = arr[i];
            return;
        }

        int mid = (i + j) / 2;

        build(arr, i, mid, 2 * ind + 1);
        build(arr, mid + 1, j, 2 * ind + 2);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(vector<int>& arr, int i, int j, int ind, int val, int index) {
        if (i == j) {
            seg[ind] = val;
            return;
        }

        int mid = (i + j) >> 1;
        if (index <= mid)    update(arr, i, mid, 2 * ind + 1, val, index);
        else    update(arr, mid + 1, j, 2 * ind + 2, val, index);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int query(vector<int>& arr, int i, int j, int l, int r, int ind) {
        if (r < i || j < l)  return 0;
        if (l <= i && j <= r) return seg[ind];
        int mid = (i + j) / 2;
        int left = query(arr, i, mid, l, r, 2 * ind + 1);
        int right = query(arr, mid + 1, j, l, r, 2 * ind + 2);

        return left + right;
    }
};
int main() {
    vector<int> arr{ 1,2,3,4,5,6 };
    int n = 6;

    segmentTree st(6);
    st.build(arr, 0, n - 1, 0);

    cout << st.query(arr, 0, n - 1, 1, 4, 0) << endl;;
    st.update(arr, 0, n - 1, 0, 6, 3);
    cout << st.query(arr, 0, n - 1, 1, 4, 0) << endl;;
    cout << st.query(arr, 0, n - 1, 0, 5, 0) << endl;

    return 0;
}