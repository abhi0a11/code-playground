#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void reverse(int n)
{
    int digit, rev = 0;
    while (n > 0)
    {
        digit = n % 10;
        rev = (rev * 10) + digit; // or rev = (rev*10) +digit;
        n = n / 10;
    }
    cout << rev << endl;
}
int main()
{
    reverse(122);
    return 0;
}