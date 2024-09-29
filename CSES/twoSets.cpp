#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    vector<int> set1, set2;

    long long sum = (n * (n + 1)) / 2;

    if (sum % 2 == 0) {
        sum = sum >> 1;
        cout << "YES" << endl;
        for (int i = n; i > 0; i--) {
            if (i <= sum) {
                set1.push_back(i);
                sum -= i;
            }
            else {
                set2.push_back(i);
            }
        }

        cout << set1.size() << endl;
        for (auto it : set1)   cout << it << " ";cout << endl;
        cout << set2.size() << endl;
        for (auto it : set2)   cout << it << " ";cout << endl;
    }
    else {
        cout << "NO";
    }
    return 0;
}