#include <iostream>
using namespace std;

int binarySearchFirstOcc(int arr[], int size, int key)
{
    int s = 0, e = size - 1, m, ans = -1;
    for (int i = 0; s <= e; i++)
    {
        m = s + (e - s) / 2;
        if (key == arr[m])
        {
            ans = m;
            e = m - 1;
        }
        if (key > arr[m])
        {
            s = m + 1;
        }
        if (key < arr[m])
        {
            e = m - 1;
        }
    }
    return ans;
}
int binarySearchLastOcc(int arr[], int size, int key)
{
    int s = 0, e = size - 1, m, ans = -1;
    for (int i = 0; s <= e; i++)
    {
        m = s + (e - s) / 2;
        if (key == arr[m])
        {
            ans = m;
            s = m + 1;
        }
        if (key > arr[m])
        {
            s = m + 1;
        }
        if (key < arr[m])
        {
            e = m - 1;
        } 
    }

    return ans;
}

int totalNumberOfOccu(int arr[], int size, int key)
{

    return binarySearchLastOcc(arr, size, key) - binarySearchFirstOcc(arr, size, key) + 1;
}

int peak(int arr[], int n)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2;
    for (int i = 0; s < e; i++)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

//  time complexity is O(n)

// int pivotIndex(int arr[], int n)
// {
//     int left = 0, right, sum = 0;
//     for (int j = 0; j < n; j++)
//     {
//         sum = sum + arr[j];
//     }
//     right = sum;
//     for (int i = 0; i < n; i++)
//     {
//         right= right- arr[i];
//         if (left == right)
//         {
//             return i;
//         }
//         left = left + arr[i];
//     }
//    return -1;
// }

//  O(log n) time complexity pivot in mountain array
int binarySearch(int arr[], int s, int e, int key)
{
    int m, ans = -1;
    for (int i = 0; s <= e; i++)
    {
        m = s + (e - s) / 2;
        if (key == arr[m])
        {
            ans = m;
            e = m - 1;
        }
        if (key > arr[m])
        {
            s = m + 1;
        }
        if (key < arr[m])
        {
            e = m - 1;
        }
    }
    return ans;
}
int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

// search in rotated sorted array

int findPosition(int arr[],int n,int k){
    int pivot= getPivot(arr,n);
    if (k >= arr[pivot] && k <= arr[n-1])
    {
        return binarySearch(arr,pivot,n-1,k);
    }
    else {
        return binarySearch(arr,0,pivot-1,k);
    }
}
int main()
{
    int arr[5] = {3, 8, 10, 17, 1};
    // cout << binarySearchFirstOcc(arr, 10, 66);
    // cout << binarySearchLastOcc(arr, 10, 66) << endl;
    // cout << totalNumberOfOccu(arr, 10, 66);
    // cout << peak(arr, 10);
    // cout << pivotIndex(arr, 3);
    // cout << getPivot(arr, 5);
    cout<<findPosition(arr,5,1);
    return 0;
}