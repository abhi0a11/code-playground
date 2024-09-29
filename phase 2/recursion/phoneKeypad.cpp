#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    // base case
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = (digits[index] - '0');
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits)
{
    vector<string> ans;
    string output ="";

    if(digits.length() == 0){
        return ans;
    }

    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, ans, mapping);

    return ans;
}

int main()
{
    string s = "23";
    vector<string> seq = letterCombination(s);
    for (auto it : seq)
    {
        cout << it << endl;
    }
    return 0;
}