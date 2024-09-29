#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // properties
    int *arr;
    int top;
    int size;

public:
    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << " Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    /*
        //using stl
        stack<int> s;

        s.push(5);
        s.push(3);

        s.pop();

        cout << "printitng top of Stack " << s.top() << endl;

        if (s.empty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }

        cout<<"Size of Stack is "<< s.size()<<endl;
    */
    
  

    Stack st(5);

    st.push(22);
    st.push(42);
    st.push(34);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    return 0;
}