#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// you can only use stack as an auxillary space

void print(queue<int> q)
{
    queue<int> qq = q;

    while (!qq.empty())
    {
        int val = qq.front();
        cout << val << " ";
        qq.pop();
    }
    cout << endl;
}
/* // method 1
queue<int> modifyQueue(queue<int> &q)
{
    stack<int> s;

    int size = q.size();
    int i = size / 2;
    while (i-- > 0)
    {
        s.push(q.front());
        q.pop();
    }

    //reverse elements of stack by pushing in queue and again pop out
    while (!s.empty())
    {
        int val = s.top();
        s.pop();

        q.push(val);
    }

    // place front half of queue at end
    for (int i = 0; i < size - size / 2; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    i = size / 2;
    while (i-- > 0)
    {
        s.push(q.front());
        q.pop();
    }


    while (!s.empty())
    {
        int val = s.top();
        s.pop();

        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}
*/



// method 2
void insertAtBottom(stack<int>& s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int num = s.top();
    s.pop();

    insertAtBottom(s,val);
    s.push(num);
}
void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int val = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,val);
}

queue<int> modifyQueue(queue<int> &q)
{
    stack<int> s;

    int size = q.size();
    int i = size / 2;
    while (i-- > 0)
    {
        s.push(q.front());
        q.pop();
    }

    reverse(s);

    while (!s.empty())
    {
        int val = s.top();
        s.pop();

        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    print(q);
    modifyQueue(q);
    print(q);
    return 0;
}