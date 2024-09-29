#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define PI 3.14 // will replace PI with 3.14 before compilation with no extra storage

/*
In inline functions , function body is replaced by function in compile time.

Function calls are reduced.

Code readability improves.


*/
inline int getMax(int &a, int &b)
{
    return (a > b) ? a : b;
}

void print(int arr[], int n, int start = 0 /* default argument */)
{
    for (int i = start; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{

    // int r = 5;

    // double area = PI * r * r;
    // cout << "Area is " << area << endl;
    /*
        int a = 2, b = 1;
        int ans = 0;

        ans = getMax(a, b);
        cout<<ans<<endl;
        a = a + 2;
        b = b + 1;

        ans = getMax(a, b);
        cout<<ans<<endl;
    */

    int arr[5] = {1, 4, 7, 8, 9};
    int size = 5;
    print(arr, size);
    cout<<endl;
    print(arr, size, 2);
    return 0;
}

/*
Homework - GFG article macros
*/