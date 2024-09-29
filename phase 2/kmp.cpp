#include<bits/stdc++.h>
using namespace std;
// vector<int> getLps(string& pat) {
//     int n = pat.size();
//     vector<int> LPS(n);
//     LPS[0] = 0;
//     int length = 0;
//     int i = 1;
//     while (i < n) {
//         if (pat[i] == pat[length]) {
//             length++;
//             LPS[i] = length;
//             i++;
//         }
//         else if (length > 0) {
//             length = LPS[length - 1];
//         }
//         else {
//             i++;
//         }
//     }
//     return LPS;
// }

vector<int> getLps(string& pat) {
    int n = pat.size();
    vector<int> LPS(n);

    for (int i = 1; i < n; i++) {
        int j = LPS[i - 1];
        while (j > 0 && pat[i] != pat[j]) {
            j = LPS[j - 1];
        }
        if (pat[i] == pat[j])    j++;
        LPS[i] = j;
    }
    return LPS;
}


int main() {
    string text, pat;
    cin >> text >> pat;
    int n = text.size(), m = pat.size();
    vector<int> LPS = getLps(pat);

    int i = 0, j = 0;
    int count = 0;
    while (i < n) {
        if (text[i] == pat[j]) {
            i++;j++;
        }
        else {
            if (j > 0) {
                j = LPS[j - 1];
            }
            else {
                i++;
            }
        }
        if (j == m) {
            cout << i - j;
            break;
            j = LPS[j - 1];
        }
    }

    return 0;
}