#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    // algo
    // step 1: pop first k element from Q and put into stack
    stack<int> s;
    int n = q.size();
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main()
{

    return 0;
}