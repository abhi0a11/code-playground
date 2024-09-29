#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    ordered_set st;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st.insert({ arr[i] , i });
    }

    for (int i = 0; i < q; i++) {
        char ch; cin >> ch;
        if (ch == '!') {
            int a, b;
            cin >> a >> b;
            a--;
            st.erase({ arr[a],a });
            arr[a] = b;
            st.insert({ arr[a],a });
        }
        else {
            int a, b; cin >> a >> b;
            cout << st.order_of_key({ b,n }) - st.order_of_key({ a - 1,n }) << endl;
        }
    }
    return 0;
}