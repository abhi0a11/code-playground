#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string num) {
    int val = 0;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '1') val += pow(2, num.size() - i - 1);
    }
    return val;
}
void solve(int n, string temp) {
    if (n == 0) {
        cout << binaryToDecimal(temp) << " " << temp << endl;
        return;
    }

    solve(n - 1, temp + '0');
    solve(n - 1, temp + '1');
}
int main() {
    int n; cin >> n;
    solve(n, "");
    return 0;
}