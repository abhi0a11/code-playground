#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            // ch ya toh ')' hai or lowercase letter

            if (ch == ')')
            {
                bool isRedundant = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    s.pop();
                }
                if(isRedundant)     return true;
                s.pop();
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}