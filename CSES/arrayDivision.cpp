#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int>& arr, int k, long long tar) {
    // cout << endl;
    // cout << "tar " << tar << endl;
    int n = arr.size();
    long long sum = 0;
    int i = 0;
    while (i < n) {
        if (arr[i] > tar)    return 0;
        if (sum + arr[i] <= tar) {
            sum += arr[i++];
        }
        else {
            k--;
            // cout << sum << " " << k << endl;
            sum = 0;
            if (k == 0) return 0;
        }
    }
    return 1;
}
int main() {
    int n, k;cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    long long ans = 0;
    long long s = 0;
    long long e = accumulate(arr.begin(), arr.end(), 0LL);
    while (s <= e) {
        long long mid = s + (e - s) / 2;
        if (isValid(arr, k, mid)) {
            ans = mid;
            // cout << ans << " ";
            e = mid - 1;
        }
        else s = mid + 1;
    }
    cout << ans;
    return 0;
}