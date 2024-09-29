#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    TwoStack(int s)
    {
        this->size = s;
        this->top1 = -1;
        this->top2 = s;
        arr = new int[s];
    }

    // push on stack 1
    void push1(int num)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    // push in stack 2
    void push2(int num)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    // pop from stack 1 and return popped element
    int pop1()
    {
        if (top1 >= 0)
        {
            int val = arr[top1];
            top1--;
            return val;
        }
        else
        {
            return -1;
        }
    }
    // pop from stack 2 and return popped element
    int pop2()
    {
        if (top2 < size)
        {
            int val = arr[top2];
            top2++;
            return val;
        }
        else
        {
            return -1;
        }
    }

    
};
int main()
{
    TwoStack s(10);

    s.push1(12);
    s.push1(2);
    s.push1(31);
    s.push2(8);
    s.push2(14);


    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    return 0;
}