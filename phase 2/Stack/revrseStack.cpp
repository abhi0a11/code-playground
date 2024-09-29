#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int element)
{
    // base case
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int> &s)
{
    if(s.empty()){
        return;
    }

    int element = s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s,element);
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(9);

    // cout<<s.top()<<endl;

    print(s);
    reverseStack(s);

   print(s);
    return 0;
}