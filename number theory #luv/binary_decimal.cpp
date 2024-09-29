#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void decimalToBinary(int n)
{
    // int digit, rev = 0, i = 0;
    // while (n > 0)
    // {
    //     digit = n & 1;
    //     rev = (digit * pow(10, i)) + rev;  // or rev = (rev*10) +digit;
    //     n = n >>1;
    //     i++;
    // }
    // cout << rev<<endl;

    for (int i = 7; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
}
int main()
{
    decimalToBinary(29);

    return 0;
}