#include<bits/stdc++.h>
using namespace std;
bool isPossible(int k, int val, vector<int>& stalls) {
    int cows = 1;
    int n = stalls.size();
    int prev = 0;
    for (int i = 1; i < n; i++) {
        if (stalls[i] - stalls[prev] >= val) {
            cows++;
            prev = i;
        }
        if (cows >= k)    return 1;
    }

    return 0;
}
int main() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    int s = 0, e = arr.back();

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(k, mid, arr)) {
            s = mid + 1;
        }
        else e = mid - 1;
    }
    cout << e << endl;
    return 0;
}