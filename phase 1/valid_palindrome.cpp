#include <iostream>
using namespace std;
class solution
{
private:
    bool isValid(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return 1;
        }
        return 0;
    }
    char toLowercase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return ch;
        }
        else
        {
            return ch - 'A' + 'a';
        }
    }
    bool checkPalindrome(string s)
    {
        int st = 0;
        int e = s.length() - 1;
        for (int i = 0; st < e; i++)
        {
            if (s[st] = s[e])
            {
                st++;
                e--;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }

public:
    string temp = "";
    bool isPalindrome(string s)
    {
        // faltu characters hatado
        for (int i = 0; i < s.length(); i++)
        {
            if (isValid(s[i]))
            {
                temp.push_back(toLowercase(s[i]));
            }
        }
        return checkPalindrome(temp);
    }
};
int main()
{
    solution c1;
    string str;
    getline(cin,str);
    if (c1.isPalindrome(str))
    {
        cout<<"Yes";
    }
    else cout<<"No";
    
    
    return 0;
}