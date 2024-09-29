#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    int n, k;cin >> n >> k;
    ordered_set st;
    for (int i = 1; i <= n; i++) st.insert(i);

    int ind = k % n;
    while (!st.empty()) {
        int size = st.size();
        ind = (ind) % size;
        int el = *st.find_by_order(ind);
        cout << el << " ";
        st.erase(el);
        ind += k;
    }
    return 0;
}