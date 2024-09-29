#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (j; arr[j] > temp && j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
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
    int arr[] = {33, 32, 42, 13, 22, 11};
    int n = sizeof(arr) / sizeof(int);
    insertionSort(arr, n);
    display(arr, n);

    return 0;
}