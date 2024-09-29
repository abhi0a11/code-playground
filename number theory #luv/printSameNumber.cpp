#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printSameNumber(int n)
{
    int digit, ans = 0, i = 0;
    while (n > 0)
    {
        digit = n % 10;
        ans = (digit * pow(10, i)) + ans; // or rev = (rev*10) +digit;
        n = n / 10;
        i++;
    }
    cout << ans << endl;
}
int main()
{
    printSameNumber(122);
    return 0;
}