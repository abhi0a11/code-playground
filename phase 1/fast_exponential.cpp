#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fastExpo(int x, int n)
{
    int res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            res = 1LL*(res * x); // 1LL type case to long long int
        }
        x = 1LL*(x * x);
        n = n >> 1;    
    }
    return res;
}
int main()
{
    cout<<fastExpo(9,1000);
    return 0;
}