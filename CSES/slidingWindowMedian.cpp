#include<bits/stdc++.h>
using namespace std;
#define ll long long

void addEl(ll el, multiset<ll>& low, multiset<ll>& up, int k) {
    ll median = *low.rbegin();

    if (el > median) {
        up.insert(el);
        if (up.size() > k / 2) {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else {
        low.insert(el);
        if (low.size() > (k + 1) / 2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

int main() {

    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    multiset<ll> low, up;

    low.insert(arr[0]);
    for (int i = 1; i < k; i++) {
        addEl(arr[i], low, up, k);
    }
    cout << *low.rbegin();


    return 0;
}