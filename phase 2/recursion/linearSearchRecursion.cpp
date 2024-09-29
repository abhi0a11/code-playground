#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int linearSearchRecursion(int arr[], int size, int key)
{
    static int count = 0;

    if (size == 0)
    {
        return -1;
    }
    else
    {
        if (key == arr[0])
        {

            return count;
        }
        else
        {
            count++;
        }
        return linearSearchRecursion(arr + 1, size - 1, key);
    }
}


int main()
{
    int arr[] = {3, 5, 1, 2, 6};
    int ans = linearSearchRecursion(arr, 5, 6);
    if (ans == -1)
    {
        cout << "Element not found" << endl;
    }
    else
        cout << "Element is found at index " << ans << endl;
    return 0;
}