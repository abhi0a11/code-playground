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
int solve(vector<vector<int>>& nums) {
    int n = nums.size();
    int m = nums[0].size();

    int ans = 0;
    vector<vector<int>> maxi(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                maxi[i][j] = nums[i][j];
            }
            else
                maxi[i][j] = max(maxi[i + 1][j], nums[i + 1][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1) {
                maxi[i][j] = max(maxi[i][j], nums[i][j]);
            }
            else
                maxi[i][j] = max(maxi[i][j + 1], nums[i][j]);
        }
    }

    int maxiAns = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxiAns = max(maxi[i][j] - nums[i][j], maxiAns);
        }
    }

    return maxiAns;
}
int main() {
    vector<vector<int>> nums = { {1,2,13,0},{15,26,7,48},{99,86,11,12},{92,89,0,99} };
    cout << solve(nums);
    return 0;
}