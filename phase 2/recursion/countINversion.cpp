#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int merge(long long arr[], int s,int mid, long long e){
    long long len1 = mid - s + 1;
    long long len2 = e - mid;

    long long *first = new long long[len1];
    long long *second = new long long[len2];

    // copy values
    long long mainArrayIndex = s;
    for (long long i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (long long i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    long long index1 = 0;
    long long index2 = 0;
    mainArrayIndex = s;

    long long cnt = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
            cnt += len1-index1; //inversion counter
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

    return cnt;
}
int mergeSort(long long arr[], long long s, long long e){
    long long cnt = 0;
    if(s>=e) return cnt;

    long long mid = s + (e-s)/2;
    cnt += mergeSort(arr,s,mid);
    cnt += mergeSort(arr,mid+1,e);
    
    cnt += merge(arr,s,mid,e);

    return cnt;
}
    
long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr,0,N-1);
    
}

int main(){
    long long arr[] = {5,3,2,1,4};
    cout<<inversionCount(arr,5);
    return 0;
}
