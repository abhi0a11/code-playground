#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool BinarySearchRecursion(int arr[], int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] > key)
        {
            // s = mid + 1;
            return BinarySearchRecursion(arr, s, mid - 1, key);
        }
        else
        {
            // e = mid - 1;
            return BinarySearchRecursion(arr, mid + 1, e, key);
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 11};
    // int ans = BinarySearchRecursionIndex(arr, 5, 8);
    // cout << ans << endl;
    bool ans = BinarySearchRecursion(arr, 0, 5, 10);
    if (ans)
    {
        cout << "element found" << endl;
    }
    else
        cout << "Element not found" << endl;
    return 0;
}