#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int isSorted=1;
    for (int i = 0; i < n -1; i++)
    {
        for (int j = 0; j < n-i-1; j++) // j < n-1    work for both
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSorted=0;
            }
        }
        if (isSorted)
        {
            break;
        }
        
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 13,  15,22,32};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    display(arr, n);
    return 0;
}