#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    vector<int> lis;

    for (int i = 0; i < n; i++) {
        if (lis.empty() || arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        }
        else {
            int ind = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

            if (ind < n) {
                lis[ind] = arr[i];
            }
        }
    }
    cout << lis.size();
    return 0;
}