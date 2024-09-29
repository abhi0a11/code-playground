#include <iostream>
using namespace std;
void linearSearch(int arr[], int size, int key)
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index " << i << endl;
            found = 1;
        }
    }
    if (found == 0)
        cout << "Element not found";
}
int binarySearch(int arr[], int size, int key)
{
    int start = 0, end = size - 1, mid;

    for (int i = 0; start <= end; i++)
    {
        mid = (start) + (end - start) / 2;
        if (key == arr[mid])
        {
            cout << "Element found at index ";
            return mid;
        }
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}


int main()
{
    int arr[10] = {1, 3, 5, 7, 8, 14, 15, 19, 74, 88};
    // linearSearch(arr, 10, 33);
   

    cout << binarySearch(arr, 10, 7);
    return 0;
}