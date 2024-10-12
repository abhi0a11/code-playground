#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];

    int left = low, right = high;
    while (left < right) {
        while (left <= high && pivot >= arr[left])   left++;
        while (right >= low && pivot < arr[right])  right--;

        if (left < right)    swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);

    return right;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if (low > high) return;

    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}
/*
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {

        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right place
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part sambhal lete h

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partition
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p - 1);

    // right wala part sort karo
    quickSort(arr, p + 1, e);
}

*/
int main()
{
    int arr[5] = { 2, 4, 1, 6, 9 };
    vector<int> sort = { 2, 4, 1, 6, 9 };
    int n = 5;

    quickSort(sort, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << sort[i] << " ";
    }
    cout << endl;
    return 0;
}