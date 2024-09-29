#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];
    long long count = 0;
    int i = 0, j = 0;
    map<long long, long long> mp;

    while (j < n) {
        mp[arr[j]]++;

        while (mp.size() > k) {
            mp[arr[i]]--;
            if (mp[arr[i]] == 0) {
                mp.erase(arr[i]);
            }
            i++;
        }
        count += j - i + 1;
        j++;
    }

    cout << count;
    return 0;
}