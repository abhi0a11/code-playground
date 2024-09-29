#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
        x ^ x == 0
        X ^ 0 == x

        a ^ b ^ c == b ^ a ^ c == c ^ b ^ a
*/
void swap(int a, int b)
{
    a = a ^ b;
    b = a ^ b; // b =  (a ^ b) ^ b == (b ^ b) ^ a == (0) ^ a == a
    a = a ^ b; // similarly a = b

    cout << a << " " << b;
}

int countOdd(int arr[], int n)
{
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    // int temp = arr[i];
    // for (int j = 0; j < n; j++)
    // {
    //     if (temp == arr[j])
    //     {
    //         count++;
    //     }
    // }
    // if (count & 1)
    // {
    //     return arr[i];
    // }
    // count = 0;
    // }
    // return -1;

    int i=0, temp =0;
    while (i<n)
    {
        temp = temp ^ arr[i];
        i++;
        
    }
    return temp;
}
int main()
{
    // swap(4,6);

    // int arr[9] = {2, 4, 6, 7, 7, 4, 2, 2, 2};
    // cout << countOdd(arr, 9);

    int k =0;
    
    return 0;
}