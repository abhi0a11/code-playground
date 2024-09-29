#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void updateByValue(int m)
{
    m++;
}
void updateByReference(int &m)
{
    m++;
}
int getSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{

    /*
        int i = 5;
        int &j = i; // same memory different name

        cout << i << endl;
        i++;
        cout << i << endl;
        j++;
        cout << j << endl;
    */

    /*
        int m = 5;
        cout<<"Before update"<<endl;
        cout<<m<<endl;
        updateByValue(m);
        cout<<"After update by Call by Value"<<endl;
        cout<<m<<endl;
        updateByReference(m);
        cout<<"After update by Call by Reference"<<endl;
        cout<<m<<endl;
    */

    /*
    int n;
    cin >> n;

    // variable size array
    int *arr = new int[n];

    // taking input in array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = getSum(arr,n);
    cout<< "answer is "<<ans<<endl;
    delete []arr;
    */


   /*
   in static allocation memory automatically gets cleard 

   in dynamic memory allocation memory needs to be cleared manually by delete keyword

   int* i = new int ;
   delete i;

   int* arr = new int[50] ;
   delete []arr;
   */

    return 0;
}