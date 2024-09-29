#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int pow(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return 2 * pow(n - 1);
}

int count(int n)
{
    if (n == 1)
    {
        return 1;
    }
    cout << n << endl;
    return count(n - 1);
}
void sayDigit(int n)
{

    map<int, string> mp{{0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

    if (n < 0)
    {
        cout << "negative ";
        n = n * (-1);
    }

    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigit(n);

    cout << mp[digit] << " ";
}
int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    // int ans = factorial(n);
    // cout << ans << endl;

    // int power = pow( n);
    // cout<< power <<endl;

    int power = count(n);
    cout << power << endl;

    return 0;
}