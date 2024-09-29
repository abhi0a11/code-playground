#include <iostream>
using namespace std;
bool isPresent(int arr[][4], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

void rowWiseSum(int arr[][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << " Sum of row " << i + 1 << " is " << sum << endl;
        sum = 0;
    }
}
void colWiseSum(int arr[][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << " Sum of row " << i + 1 << " is " << sum << endl;
        sum = 0;
    }
}

void largestRowSum(int arr[][4], int row, int col)
{
    int maxi = INT_MIN;
    int maxRowIndex;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        if (maxi < sum)
        {
            maxi = sum;
            maxRowIndex = i;
        }
    }
    cout << "Sum of row " << maxRowIndex + 1 << " is maximum and is equal to " << maxi << endl;
}

void printInSineWave(int arr[][4], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0) // ( i & 1) --> will give 1 if odd and 0 if even
        {

            for (int j = 0; j < row; j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for (int k = row - 1; k >= 0; k--)
            {
                cout << arr[k][i] << " ";
            }
        }
    }
}

void spiralPrint(int arr[][4], int row, int col)
{
    int count = 0;
    int total = row * col;

    int startingRow = 0;
    int endingRow = row - 1;
    int startingCol = 0;
    int endingCol = col - 1;
    while (count < total)
    {

        for (int i = startingCol; count < total && i <= endingCol; i++)
        {
            cout << arr[startingRow][i] << " ";
            count++;
        }
        startingRow++;
        for (int j = startingRow; count < total && j <= endingRow; j++)
        {
            cout << arr[j][endingCol] << " ";
            count++;
        }
        endingCol--;
        for (int k = endingCol; count < total && k >= startingCol; k--)
        {
            cout << arr[endingRow][k] << " ";
            count++;
        }
        endingRow--;
        for (int l = endingRow; count < total && l >= startingRow; l--)
        {
            cout << arr[l][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
}

// searching in 2d array

int searchInTwoDimensionalArray(int arr[][4], int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid / col][mid % col] == target)
        {
            return 1;
        }
        if (arr[mid / col][mid % col] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}
int main()
{
    int arr[3][4];

    // int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12}; // row wise input

    // int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}}; // user decide which row should get what value

    // taking input row wise
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    // taking input column wise
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[j][i];
    //     }
    // }

    // print
    cout << "Printing the array" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    /*
        cout << "Enter the element to search: ";
        int target;
        cin >> target;

        if (isPresent(arr, 3, 4, target))
        {
            cout << "Element found!" << endl;
        }
        else
        {
            cout << "Element not found!";
        }
    */
    // rowWiseSum(arr,3,4);
    // colWiseSum(arr, 3, 4);
    // largestRowSum(arr, 3, 4);
    // printInSineWave(arr, 3, 4);
    // spiralPrint(arr, 3, 4);
    cout<<endl<<searchInTwoDimensionalArray(arr,3,4,7);
    return 0;
}