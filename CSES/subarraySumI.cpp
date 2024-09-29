#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)  cin >> arr[i];

    int i = 0, j = 0;
    long long sum = 0;
    long long count = 0;
    while (j < n) {
        sum += arr[j];
        while (i <= j && sum > x) {
            sum -= arr[i++];
        }
        if (sum == x) {
            count++;
        }
        j++;
    }
    cout << count;
    return 0;
}