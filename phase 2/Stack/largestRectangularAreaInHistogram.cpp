#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> arr, int size)
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
vector<int> prevSmallerElement(vector<int> arr, int size)
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
int largestAreaRectangle(vector<int> &heights)
{
    int n = heights.size();
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

int main()
{
    vector<int> heights = {3,0,0,2,0,4};
   cout<< largestAreaRectangle(heights);

    return 0;
}