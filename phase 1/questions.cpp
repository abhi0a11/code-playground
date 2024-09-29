#include <iostream>
using namespace std;
void reverseArray(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void mergeSortedArray(int arr1[], int size1, int arr2[], int size2, int arr3[])
{
    int a = 0, b = 0, c = 0;

    for (int i = 0; a < size1 && b < size2; i++)
    {
        if (arr1[a] > arr2[b])
        {
            arr3[c] = arr2[b];
            c++;
            b++;
        }
        if (arr1[a] <= arr2[b])
        {
            arr3[c] = arr1[a];
            c++;
            a++;
        }
    }

    for (int i = b; i < size2; i++)
    {
        arr3[c] = arr2[b];
        c++;
    }

    for (int i = a; i < size1; i++)
    {
        arr3[c] = arr2[a];
        c++;
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void merge(int num1[], int m, int num2[], int n)
{
    int i = 0, j = 0, temp = 0;
    while (i < m && j < n)
    {
        if (num1[i] > num2[j])
        {
            swap(num1[i], num2[j]);
            bubbleSort(num2, n);
        }
        else
        {
            i++;
        }
    }
    while (i < (m + n) && j < n)
    {
        num1[i] = num2[j];
        j++;
        i++;
    }
}

void moveZeroes(int arr[], int n)
{
    // int s=0,e=n-1;
    // while (s<=e)
    // {
    //     while (arr[e]==0)
    //     {
    //         e--;
    //     }

    //     if (arr[s]==0)
    //     {
    //         swap(arr[s],arr[e]);
    //         s++;
    //         e--;
    //     }
    //     else{s++;}
    // }

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

void Rotate2dArrayBy90Degree(int arr[][3], int row, int col)
{
    int startingRow = 0;
    int endingRow = row - 1;
    int startingCol = 0;
    int endingCol = col - 1;
    while (startingRow != endingRow)
    {
        while (startingCol != endingCol)
        {
            swap(arr[startingRow][startingCol], arr[endingRow][endingCol]);
            startingCol++;
            endingRow--;
        }
        startingRow++;
        endingCol--;
        endingRow = row - 1;
        startingCol = 0;
    }
    endingRow = row - 1;
    startingRow = 0;
    startingCol = 0;
    endingCol = col - 1;
    while (endingCol >= 0)
    {
        while (startingRow <= endingRow)
        {
            swap(arr[startingRow][endingCol], arr[endingRow][endingCol]);
            startingRow++;
            endingRow--;
        }
        endingRow = row - 1;
        startingRow = 0;
        endingCol--;
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void display2dArray(int arr[][3], int row, int col)
{
    cout << "Printing the array" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void toSum(int arr[], int size, int sum)
{
    int i = 0;
    while (i < size)
    {
        if ((arr[i] + arr[i + 1]) == sum)
        {
            cout << i << "and " << i + 1 << endl;
            break;
        }
        
        i++;
    }
}



int reverseInteger(int n)
{
    int rev = 0;
    while (n)
    {
        int digit = n % 10;
        // condition to detect overflow
        if ((rev > (INT_MAX / 10)) || (rev < (INT_MIN / 10)))
        {
            return 0;
        }

        rev = rev * 10 + digit;
        n = n / 10;
    }
    return rev;
}

void compliment(int n)
{
    int m = n;

    for (int i = 0; m != 0; i++)
    {
        cout << (((n >> i) & 1) ^ 1);
        m = m >> 1;
    }
}

// method 2

int complimentValue(int n)
{
    int m = n;
    int mask = 0;

    // edge case
    if (n == 0)
    {
        return 1;
    }

    while (m != 0)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;
    return ans;
}

int PowerOf2(int n)
{
    // method 1

    /*
        while (n != 1)
        {
            if ((n % 2) != 0)
            {
                return 0;
            }
            n = n >> 1;
        }
        return 1;
    */

    // method 2

    /*
        for (int i = 0; i <= 30; i++)
        {
            int ans = pow(2,i);

            if(ans == n){
                return true;
            }
        }
        return false;
    */

    // method 3

    /*
    int ans = 1;
    for (int i = 0; i <= 30; i++)
    {

        if (ans == n)
        {
            return true;
        }

    }
    return false;
    */

    // method 4-  if it contains only 1 set bit then it is a power of two
    int count = 0;
    while (n != 0)
    {
        if ((n >> 1) & 1)
        {
            count++;
        }
        n = n >> 1;
    }

    return count;
}

int ElementPresentTwice(int arr[], int n)
{

    // method 1

    /*
    int s = 0, e = n - 1;
    int temp = 0, count = 1;
    while (s < n - 1)
    {
        temp = arr[s];
        count = 1;
        for (int j = 0; j < n; j++)
        {
            if (temp == arr[j])
            {
                count++;
            }
            if (count >= 3)
            {
                break;
            }
        }
        if (count == 2)
        {
            return temp;
        }
        s++;
    }
    return -1;
    */

    // method 2

    /*
    XOR:  a^a = 0
          a^0 = a
    */

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int findDuplicate(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        ans = (ans ^ arr[i] ^ i);
    }
    return ans;
}

void swapAlternate(int arr[], int n)
{

    for (int i = 0; i < n; ++ ++i)
    {
        if (i + 1 < n)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void sort01(int arr[], int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        while (arr[s] == 0)
        {
            s++;
        }
        while (arr[e] == 1)
        {
            e--;
        }
        if (s < e)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
}

void sort012(int arr[], int n)
{
    int s = 0, e = n - 1;

    while (s < e)
    {
        while (arr[s] == 0)
        {
            s++;
        }
        while (arr[e] != 0)
        {
            e--;
        }
        if (s < e)
        {
            swap(arr[s], arr[e]);
        }
    }
    e = n-1;
    while (s < e)
    {
        while (arr[s] == 1)
        {
            s++;
        }
        while (arr[e] == 2)
        {
            e--;
        }
        if (s < e)
        {
            swap(arr[s], arr[e]);
            
        }
    }
}
void print(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    // int arr[] = {1, 21, 34, 88, 77, 58, 78, 66, 45, 36, 24};
    // int size = sizeof(arr) / sizeof(int);
    // display(arr, size);
    // reverseArray(arr, size);
    // display(arr, size);

    // int arr1[] = {1, 21, 24, 34, 36, 45, 58, 66, 77, 88, 89};
    // int size1 = sizeof(arr1) / sizeof(int);

    // int arr2[] = {14, 16, 18, 21, 24, 25, 77, 78, 98};
    // int size2 = sizeof(arr2) / sizeof(int);

    // int arr3[20] = {0};

    // mergeSortedArray(arr1, size1, arr2, size2, arr3);
    // display(arr3, 20);

    // int num1[6] = {1, 2, 3, 0, 0, 0};
    // int num2[3] = {2, 5, 6};
    // merge(num1, 3, num2, 3);
    // display(num1,6);

    // int movezero[7] = {2, 0, 1, 3, 0, 0, 7};
    // moveZeroes(movezero, 7);
    // display(movezero, 7);

    // int arr[3][3];

    // cout << "Enter the elements of array" << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // display2dArray(arr, 3, 3);
    // Rotate2dArrayBy90Degree(arr, 3, 3);
    // display2dArray(arr, 3, 3);

    int arrrr[5] = {1,3,4,2,2};
    cout<<"h"<<ElementPresentTwice(arrrr,5);
    return 0;
}

