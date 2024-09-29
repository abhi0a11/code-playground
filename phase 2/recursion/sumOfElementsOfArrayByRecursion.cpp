#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sumRecursion(int arr[], int size)
{

    static int sum = 0;
    if (size == 0)
    {
        return sum;
    }

    else
    {
        sum = sum + arr[0];
        return sumRecursion(arr + 1, size - 1);
    }
}
int main()
{
    int arr[5] = {3, 2, 5, 1, 6};
    int sum = sumRecursion(arr, 5);
    cout << sum << endl;

    return 0;
}