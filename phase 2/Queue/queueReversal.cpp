#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    return q;
}

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int val = q.front();
    q.pop();

    reverse(q);
    q.push(val);
}

void print(queue<int> q)
{
    queue<int> newq = q;
    int n = newq.size();
    for (int i = 0; i < n; i++)
    {
        cout << newq.front() << " ";
        newq.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(2);
    q.push(3);
    q.push(1);
    q.push(5);
    q.push(6);

    print(q);
    reverse(q);
    print(q);

    return 0;
}