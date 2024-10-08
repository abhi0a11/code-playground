// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool isPalindrome(const string& s) {
//     int left = 0, right = s.size() - 1;
//     while (left < right) {
//         if (s[left] != s[right]) return false;
//         ++left;
//         --right;
//     }
//     return true;
// }

// int maxConcatenatedPalindrome(int wordsCount, vector<string> words) {
//     unordered_map<string, int> countMap;
//     for (const string& word : words) {
//         countMap[word]++;
//     }

//     int maxLength = 0;
//     int singlePalindromeMaxLength = 0;
//     bool hasOddPalindrome = false;

//     for (const auto& entry : countMap) {
//         string word = entry.first;
//         string reversedWord = word;
//         reverse(reversedWord.begin(), reversedWord.end());

//         if (countMap.find(reversedWord) != countMap.end()) {
//             if (word == reversedWord) {
//                 // Handling words that are palindromes themselves
//                 int pairs = countMap[word] / 2;
//                 maxLength += pairs * 2 * word.length();
//                 if (countMap[word] % 2 == 1) {
//                     singlePalindromeMaxLength = max(singlePalindromeMaxLength, (int)word.length());
//                     hasOddPalindrome = true;
//                 }
//             }
//             else if (countMap[word] > 0 && countMap[reversedWord] > 0) {
//                 int pairs = min(countMap[word], countMap[reversedWord]);
//                 maxLength += pairs * 2 * word.length();
//                 countMap[reversedWord] -= pairs;
//                 countMap[word] -= pairs;
//             }
//         }
//     }

//     // If there's any odd-length palindrome word, add its length once
//     if (hasOddPalindrome) {
//         maxLength += singlePalindromeMaxLength;
//     }

//     return maxLength;
// }

// int main() {
//     vector<string> words = { "ab", "ba", "xyx","xyx","xyx", "de" };
//     int wordsCount = words.size();
//     cout << "Maximum length of concatenated palindrome: " << maxConcatenatedPalindrome(wordsCount, words) << endl;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> solve(int n, vector<vector<string>>& Messages) {
    map<ll, string> mp;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        ll ind = stoll(Messages[i][0]);
        string ch = Messages[i][1];

        mp[ind] = ch;
        ll idx = ind;
        bool left = 0, right = 0;
        string l = "", r = "";


        if (ch != "*") {
            while (mp.find(idx - 1) != mp.end()) {
                if (mp[idx - 1] == "*") {
                    left = 1;
                    break;
                }
                l = mp[idx - 1] + l;
                idx--;
            }
            idx = ind;
            while (mp.find(idx + 1) != mp.end()) {
                if (mp[idx + 1] == "*") {
                    right = 1;
                    break;
                }
                r += mp[idx + 1];
                idx--;
            }

            if (left && right) {
                ans.push_back(l + mp[ind] + r);
            }
        }
        else {
            idx = ind - 1;
            if (mp.find(idx) != mp.end() && mp[idx] != "*") {
                l = mp[idx] + l;
                while (mp.find(idx - 1) != mp.end()) {
                    if (mp[idx - 1] == "*") {
                        left = 1;
                        break;
                    }
                    l = mp[idx - 1] + l;
                    idx--;
                }
                if (left)    ans.push_back(l);
            }
            idx = ind + 1;
            if (mp.find(idx) != mp.end() && mp[idx] != "*") {
                r += mp[idx];
                while (mp.find(idx + 1) != mp.end()) {
                    if (mp[idx + 1] == "*") {
                        right = 1;
                        break;
                    }
                    r += mp[idx + 1];
                    idx++;
                }

                if (right)    ans.push_back(r);
            }

        }

    }
    return ans;
}
int main() {
    while (1) { cout << "chinti bahar nikal"; };

    // vector<vector<int>> nums = { {1,2,13,0},{15,26,7,48},{99,86,11,12},{92,89,0,99} };
    // cout << solve(nums);
    return 0;
}