#include<bits/stdc++.h>
using namespace std;
// void getMaxPalindrome(string s){ // n2 complexity

//     int ind = 0;
//     int maxLen = 0;
//     for (int i = 0; i < n; i++) {
//         int k = 0;
//         while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
//             k++;
//         }
//         k--;
//         if (maxLen < ((i + k) - (i - k) + 1)) {
//             ind = i - k;
//             maxLen = (i + k) - (i - k) + 1; // j-i+1
//         }
//     }

//     for (double i = 0.5; i < n; i++) {
//         double k = 0.5;
//         while (i - k >= 0 && i + k < n && s[int(i - k)] == s[int(i + k)]) {
//             k++;
//         }
//         k--;
//         if (maxLen < ((i + k) - (i - k) + 1)) {
//             ind = i - k;
//             maxLen = ((i + k) - (i - k) + 1);
//         }
//     }

//     for (int i = ind; i < ind + maxLen; i++) cout << s[i];
// }


///

string transform(string s) {
    string temp = "#";
    for (int i = 0; i < s.size(); i++) {
        temp += s[i];
        temp += '#';
    }
    return temp;
}
int main() {
    string s; cin >> s;

    // manacher's algorithm O(n)

    string t = transform(s);
    int n = t.size();

    int l = 0;
    int r = 0;

    int centre;
    int maxLen = 0;

    vector<int> p(n, 0);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int k;
        if (i > r) {
            k = 0;
        }
        else {
            int j = l + (r - i);
            if (j - p[j] > l) {
                p[i] = p[j];
                continue;
            }
            else {
                k = r - i;
            }
        }
        while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) {
            k++;
        }
        k--;
        p[i] = k;

        if (p[i] > maxLen) {
            maxLen = p[i];
            centre = i / 2;
        }
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    cout << s.substr(centre - (maxLen / 2), maxLen);
    return 0;
}