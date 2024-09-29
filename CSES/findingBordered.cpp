#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;cin >> s;
    int n = s.size();
    vector<int> lps(n, 0);
    int length = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n) {
        if (s[i] == s[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length > 0) {
                length = lps[length - 1];
            }
            else    i++;
        }
    }

    int j = lps[n - 1];
    vector<int> ans;
    while (j > 0) {
        ans.push_back(j);
        j = lps[j - 1];
    }
    sort(ans.begin(), ans.end());
    for (auto it : lps)    cout << it << " ";
    return 0;
}