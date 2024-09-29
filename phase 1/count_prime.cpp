#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return 0;
    for (int j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
            return 0;
    }
    return 1;
}
// sieve algorithm --- important
int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    return cnt;
}
int main()
{

    int n;
    cin >> n;
    cout << countPrimes(n);
    return 0;
}

// segmented sieve