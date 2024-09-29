#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
int main() {
    int n;cin >> n;
    ordered_set st;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        st.insert({ i,val });
    }

    for (int i = 0; i < n; i++) {
        int pos; cin >> pos;
        auto p = st.find_by_order(pos - 1);

        cout << (*p).second << " ";
        st.erase(p);
    }

    return 0;
}