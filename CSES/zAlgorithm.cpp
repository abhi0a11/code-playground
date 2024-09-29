#include<bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i;
            r = i + z[i];
            z[i]++;
        }

    }
    return z;
}
int main() {
    string s = "abcabca";

    vector<int> ans = z_function(s);
    for (auto it : ans)    cout << it << " ";
    return 0;
}