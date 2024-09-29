#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++)  cin >> time[i];
    sort(time.begin(), time.end());

    int i = 0;
    long long sum = 0;
    long long last = time[n - 1];
    while (i < n - 1) {
        sum += time[i];
        i++;
    }

    if (sum <= last) {
        cout << 2 * last;
    }
    else {
        cout << sum + last;
    }
    return 0;
}