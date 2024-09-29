#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int modularExponential(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {

        if (n & 1)
        {
            res = (1LL * res * ((x) % m)) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;
    }
    return res;
}
int main()
{
    cout << modularExponential(26, 2, 1e9 + 7);
    return 0;
}