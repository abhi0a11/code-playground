#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(string s, vector<string> &ans, string output, int index)
{
    // base case
    if (index >= s.length())
    {
        if (output.length() >= 0)
        {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(s, ans, output, index + 1);

    // include
    output.push_back(s[index]);
    solve(s, ans, output, index + 1);
    output.pop_back();
}

vector<string> subsequences(string &s)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(s, ans, output, index);
    return ans;
}

int main()
{
    string s = "igigee";
    vector<string> str = subsequences(s);
    for(auto st:str){
        cout<<st<<endl;
    }
    return 0;
}