#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    map<long long, long long> mp;
    long long sum = 0, count = 0;
    mp[0]++;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        long long rem = sum % n;
        if (rem < 0)    rem += n;
        if (mp.find(rem) != mp.end())  count += mp[rem];
        mp[rem]++;
    }
    cout << count;
    return 0;
}