#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// taking space of O(N)
void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
            // count++ //inversion counter
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;
    // base case
    if (s >= e)
    {
        return;
    }

    // left part sort krna h
    mergeSort(arr, s, mid);

    // right part sort krna h
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

/*
void merge(vector<int>& arr, int s, int mid, int e){
    vector<int> temp;

    int left = s;
    int right = mid+1;

    while(left <= mid && right <= e){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= e){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=s; i<= e; i++){
        arr[i] = temp[i];
    }
}
void mS(vector<int>& arr, int s, int e){
    if(s>=e)    return ;
    int mid = s + (e-s)/2;

    mS(arr,s,mid);
    mS(arr,mid+1,e);
    merge(arr,s,mid,e);
}
void mergeSort(vector<int>& arr, int n){
    mS(arr,0,n-1);
}

*/

// in-place merge sort
/*
void merge(int arr[],int s,int e,int& count){
    int mid = s + (e-s)/2;

    int left = s;
    int right = mid+1;

    if(arr[mid] <= arr[right]){
        return;
    }

    while(left <= mid && right <= e){
        if(arr[left] <= arr[right])   left++;

        else{
            int val = arr[right];
            int index = right;

            while( index != left)  {
                count++;
                arr[index] = arr[index-1];
                index--;
            }

            arr[left] = val;
            left++;
            mid++;
            right++;
        }
    }

}

void mergeSort(int arr[], int s,int e,int& count){

    if(s>=e)    return;

    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid,count);
    mergeSort(arr,mid+1,e,count);
    merge(arr,s,e,count);
}
*/
int main()
{
    int arr[5] = { 2, 5, 1, 6, 9 };
    int n = 5;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// HW - inversion count problem