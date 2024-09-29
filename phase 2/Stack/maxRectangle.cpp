#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int* arr, int size)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(size);

    for (int i = size - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(int *arr, int size)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(size);

    for (int i = 0; i < size; i++)
    {
        while (s.top() != -1 && arr[s.top()] > arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestAreaRectangle(int *heights, int n)
{
    // int n = heights.size();
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(int M[][5], int n, int m){
    
    //compute area for first row
    int area = largestAreaRectangle(M[0],m);

    for (int i = 1; i < n; i++)
    {
        for(int j=0; j<m; j++){

            // row update: by adding previous row's value
            if(M[i][j] != 0)
                M[i][j] = M[i][j] + M[i-1][j];

            else    M[i][j] = 0;
        }

        //entire row is updated now
        int newArea = largestAreaRectangle(M[i],m);
        area = max(area,newArea);
    }
    return area;
}
int main(){
    
    return 0;
}