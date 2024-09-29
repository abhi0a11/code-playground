#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string str, int i, int j)
{
    if (i > j)
        return true;

    else
    {
        if (str[i] == str[j])
        {
            return checkPalindrome(str, i+1, j-1);
        }
        else
            return false;
    }
}
int main()
{
    string s = "abcba";
    bool ans = checkPalindrome(s, 0, (s.length() - 1));
    if (ans)
    {
        cout << "Palindrome" << endl;
    }
    else
        cout << "Not Palindrome" << endl;
    return 0;
}