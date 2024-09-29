#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char toLowercase(char ch)
{
    if (ch <= 'z' && ch >= 'a')
    {
        return ch;
    }
    else
    {

        char lowerCase = ch - 'A' + 'a';
        return lowerCase;
    }
}

char maxCount(string s)
{
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        count[(toLowercase(s[i]) - 'a')]++;
    }

    int maxi = INT_MIN, maxIndex = 0;
    ;

    for (int i = 0; i < 26; i++)
    {
        if (maxi < count[i])
        {
            maxi = count[i];
            maxIndex = i;
        }
    }

    char ans = maxIndex + 'a';
    return ans;
}

void replaceString(string s)
{
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ans.push_back(s[i]);
        }
        else
        {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
    }

    cout << ans << endl;
}

void replceAllOccuSubstring(string s, string substr)
{

    while (s.length() != 0 && s.find(substr) < s.length())
    {
        s.erase(s.find(substr), substr.length());
    }

    cout << s << endl;
}

void checkPermutation(string s1, string s2)
{
    int counts1[26] = {0};
    int counts2[26] = {0};

    bool ispermutation = true;

    for (int i = 0; i < s1.length(); i++)
    {
        counts1[(toLowercase(s1[i]) - 'a')]++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        counts2[(toLowercase(s2[i]) - 'a')]++;
    }

    for (int j = 0; j < s1.length(); j++)
    {
        if (counts1[j] >= 1 && counts2[j] < counts1[j])
        {
            ispermutation = false;
        }
    }

    if (ispermutation)
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
}

void removeDuplicates(string s)
{
    string str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = 0;
        }
    }

    cout << s << endl;
}

void compress(string s)
{
    int i = 0;
    int j = 0;

    string output;

    while (i < s.length())
    {
        int count = 0;

        while (s[i] == s[j])
        {
            count++;
            j++;
        }


        string str = to_string(count);
        output.push_back(s[i]);
        int k = 0;
        while (k < str.length() && count > 1)
        {
            output.push_back(str[k]);
            k++;
        }


        i = j;
    }
    cout << output << endl;
}

int main()
{
    string s = "daabcbaabcbc";
    string sub = "abc";
    // cout << maxCount(s) << endl;

    // replceAllOccuSubstring(s,sub);

    // checkPermutation("ab","csdfababab");

    compress("aabcccccccccccccccccccccccc");
    return 0;
}