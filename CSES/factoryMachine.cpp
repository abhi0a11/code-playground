#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<long long>& arr, long long time, int k) {
    int n = arr.size();
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (time / arr[i]);
        if (sum >= k)    return 1;
    }

    return 0;
}
int main() {
    long long n, k; cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    long long s = 0;
    long long e = 1e18;
    long long ans = 0;

    while (s <= e) {
        long long mid = (e + s) / 2;
        if (isValid(arr, mid, k)) {
            ans = mid;
            e = mid - 1;
        }
        else    s = mid + 1;
    }
    cout << ans;
    return 0;
}