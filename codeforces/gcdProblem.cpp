#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        if (n % 2 == 0) {
            cout << n - 3 << " " << 2 << " " << 1 << endl;
        }
        else {
            int num = (n - 1) / 2;
            if (num % 2 == 0) {
                cout << num - 1 << " " << num + 1 << " " << 1 << endl;
            }
            else {
                cout << num - 2 << " " << num + 2 << " " << 1 << endl;
            }
        }
    }

    return 0;
}