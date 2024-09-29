#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        arr[i] = { val,i };
    }

    sort(arr.begin(), arr.end());

    int i = 0;
    while (i < n) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            long long sum = arr[i].first + arr[j].first + arr[k].first;
            if (sum == x) {
                cout << arr[i].second + 1 << " " << arr[j].second + 1 << " " << arr[k].second + 1;
                return 0;
            }
            else if (sum > x) {
                k--;
            }
            else    j++;
        }
        i++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}