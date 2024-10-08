#include<bits/stdc++.h>
using namespace std;
int countLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> cnt(n + 1);

    int prev = -1;
    vector<int> lis;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        if (lis.empty() || lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            cnt[lis.size()] = cnt[lis.size() - 1];
        }
        else {
            int ind = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            if (ind < lis.size()) {
                lis[ind] = arr[i];
                cnt[lis.size()]++;
            }
        }

    }

    return cnt[lis.size()];
}
int main() {
    vector<int> arr{ 2,4,7,6,5,8 };
    cout << countLIS(arr);
    return 0;
}