#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> temp(n);

    for (int i = 0; i < a.size(); i++)
    {
        temp[(i + k) % n] = a[i];
    }

    a = temp;

    for (auto it : a)
    {
        cout << it << " ";
    }
}

bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    if (nums[n - 1] > nums[0])
        count++;

    return count <= 1;
}

long long int sum(int arr1[], int n1, int arr2[], int n2)
{

    int num1 = 0, num2 = 0;

    for (int i = 0; i < n1; i++)
    {
        num1 = num1 * 10 + arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        num2 = num2 * 10 + arr2[i];
    }

    long long int sum = num1 + num2;

    return sum;
}

vector<int> findArraySum(vector<int>&a,int n,vector<int>&b, int m){
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;

    while(i>=0 && j>=0){
        int val1 = a[i];
        int val2 = b[j];

        int sum 
    }
}
int main()
{
    // vector<int> a={1,2,3,4,5,6,7};
    // rotateArray(a,3);

    int num1[] = {1, 2, 3, 4};
    int num2[] = {6};
    int n1 = sizeof(num1) / sizeof(int);
    int n2 = sizeof(num2) / sizeof(int);
    cout << sum(num1, n1,num2,n2) << endl;
    return 0;
}