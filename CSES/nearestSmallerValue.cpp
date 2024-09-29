#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    stack<int> st;
    st.push(0);
    for (int i = 0; i < n; i++) {
        while (st.top() != 0 && arr[st.top() - 1] >= arr[i]) {
            st.pop();
        }

        cout << st.top() << " ";
        st.push(i + 1);
    }

    return 0;
}