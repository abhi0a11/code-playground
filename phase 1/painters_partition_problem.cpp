#include <iostream>
using namespace std;

bool isPossible(int arr[], int size, int k, int mid)
{
    int boardSum = 0, painterCount = 1;
    for (int i = 0; i < size; i++)
    {
        if (boardSum + arr[i] <= mid)
        {
            boardSum += arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount > k || arr[i] > mid)
            {
                return false;
            }
            boardSum=arr[i];
        }
    }
    return true;
}
int boardAllocation(int arr[], int size, int k)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int s = 0, ans = -1;
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(arr, size, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int arr[]={10,20,30,40};
    cout<<boardAllocation(arr,4,2);
    return 0;
}