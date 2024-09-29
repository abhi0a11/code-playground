#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];
    map<long long, long long> mp;
    long long sum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == x)    count++;
        if (mp.find(sum - x) != mp.end())  count += mp[sum - x];
        mp[sum]++;
    }
    cout << count;
    return 0;
}