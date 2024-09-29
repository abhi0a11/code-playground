#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reachHome(int src, int dest)
{
    cout << "Source " << src << " Destination " << dest << endl;
    // base case
    if (src == dest)
    {
        cout << "Pahunch gaya" << endl;
        return;
    }

    // processing - ek step aage badhao
    src++;

    // recursive call
    reachHome(src, dest);
}

void fibonacciNthTerm(int n)
{
    if (n == 0)
    {
        cout << "0";
    }
    if (n == 1)
    {
        cout << "1";
    }
    if (n > 1)
    {
        int a = 0;
        int b = 1;
        int sum = a + b;
        cout << a << " " << b << " " << sum << " ";
        n = n - 2;
        while (n >= 0)
        {
            a = b;
            b = sum;
            sum = a + b;

            cout << sum << " ";
            n--;
        }
    }
}
void fibonacci(int n)
{
    if (n == 0)
    {
        cout << "0";
    }
    if (n == 1)
    {
        cout << "1";
    }
    if (n > 1)
    {
        int a = 0;
        int b = 1;
        int sum = a + b;
        cout << a << " " << b << " " << sum << " ";
        n = n - 2;
        int count = 0;
        while (count != n)
        {
            a = b;
            b = sum;
            sum = a + b;
            // if(count == n-1) to find nth term
            cout << sum << " ";
            count++;
        }
    }
}

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return (fibo(n - 1) + fibo(n - 2));
}

int sum(int arr[], int size)
{

    int sumArray = 0;
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return (arr[0]);
    }

    int remainingPart = sum(arr + 1, size - 1);
    sumArray = arr[0] + remainingPart;
    return sumArray;
}

int main()
{
    int dest = 10, src = 1;

    // reachHome(src, dest);
    fibonacciNthTerm(0);
    cout << endl
         << endl;
    fibonacci(2);
    cout << endl
         << endl;
    int ans = fibo(2);
    cout << ans;
    return 0;
}