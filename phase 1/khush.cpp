#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& arr, int k)
{
    vector<int> lis;
    vector<int> cnt(arr.size() + 1);
    int n = arr.size();
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        if (lis.empty() || arr[i] > lis.back()) {
            lis.push_back(arr[i]);
            cnt[lis.size()] = cnt[lis.size() - 1];
        }
        else {
            int ind = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            if (ind < lis.size())   lis[ind] = arr[i];
            cnt[lis.size()]++;
        }
    }

    return cnt[lis.size()];
}

int main() {
    int n, k;
    cin >> n;




    vector<int> v(n);
    for (auto& i : v)  cin >> i;
    cin >> k;
    cout << solve(v, k);
}