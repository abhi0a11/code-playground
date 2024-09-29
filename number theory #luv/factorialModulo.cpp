#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fact(int n, int m)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact = (fact * i) % m;
    }
    cout << fact;
}

int main()
{
    int n, m;
    cin >> n >> m;
    fact(n,m);
    return 0;
}