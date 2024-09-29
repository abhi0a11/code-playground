// #include<bits/stdc++.h>
// using namespace std;
// class segmentTree {
//     vector<int> seg;
// public:
//     segmentTree(int n) {
//         seg.resize(4 * n);
//     }
//     void build(int i, vector<int>& arr, int l, int h) {
//         if (l == h) {
//             seg[i] = arr[l];
//             return;
//         }

//         int mid = (l + h) >> 1;

//         build(2 * i + 1, arr, l, mid);
//         build(2 * i + 2, arr, mid + 1, h);

//         seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
//     }

//     int query(int i, int low, int high, int l, int h) {
//         if (low > h || high < l) return 0;
//         if (l <= low && high <= h)   return seg[i];

//         int mid = (low + high) >> 1;
//         int left = query(2 * i + 1, low, mid, l, h);
//         int right = query(2 * i + 2, mid + 1, high, l, h);

//         return left + right;
//     }
// };
// int main() {
//     int n, q; cin >> n >> q;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)  cin >> arr[i];
//     segmentTree st(n);
//     st.build(0, arr, 0, n - 1);

//     for (int i = 0;i < q; i++) {
//         int u, v; cin >> u >> v;
//         cout << st.query(0, 0, n - 1, u - 1, v - 1) << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    int mini = INT_MAX;
    int minIndex = -1;
    vector<int> minInd(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (mini >= arr[i]) {
            mini = arr[i];
            minIndex = i;
            minInd[i] = i;
        }
        else {
            minInd[i] = minInd[i - 1];
        }
    }

    int subt = 0;
    int ans = 0;
    int j = minIndex;

    while (j >= 0) {
        if (arr[j] - subt == 0) {
            ans += 1;
        }
        else {
            arr[j] -= subt;
            subt += arr[j];
            ans++;
        }
        if (j == 0)  break;
        j = minInd[j - 1];
    }
    cout << ans;
    return 0;
}