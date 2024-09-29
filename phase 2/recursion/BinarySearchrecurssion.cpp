#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int BinarySearchRecursionIndex(int arr[], int size, int key)
{
    static int start = 0;
    int end = size - 1;
    int mid = end - (end - start) / 2;

    if (arr[mid] == key)
    {
        // end = mid-1;
        return mid;
    }
    if (arr[mid] > key)
    {
        // end = mid-1;
        return BinarySearchRecursionIndex(arr, size - mid, key);
    }
    else
    {
        start = mid;
        return BinarySearchRecursionIndex(arr, size, key);
    }
}
bool BinarySearchRecursion(int arr[], int start, int end, int key)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return false;
    }
    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] > key)
    {
        return BinarySearchRecursion(arr, start, mid - 1, key);
    }
    else
    {
        return BinarySearchRecursion(arr, mid+1, end, key);
    }
}
int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    // int ans = BinarySearchRecursionIndex(arr, 5, 8);
    // cout << ans << endl;
    bool ans = BinarySearchRecursion(arr, 0, 4, 9);
    if (ans)
    {
        cout << "element found" << endl;
    }
    else
        cout << "Element not found" << endl;
    return 0;
}