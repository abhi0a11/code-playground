#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue(int size)
    {
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            if (rear < size)
            {
                arr[rear] = data;
                rear++;
            }
        }
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qfront == rear)
            return -1;
        else
            return arr[qfront];
    }

    bool isEmpty()
    {
        if (qfront == rear)
            return true;
        else
            return false;
    }
};

int main()
{
    /*
        queue<int> q;
        q.push(11);
        cout<<"qfront of queue: "<<q.qfront()<<endl;
        q.push(15);
        cout<<"qfront of queue "<<q.qfront()<<endl;
        q.push(13);
        cout<<"qfront of queue "<<q.qfront()<<endl;

        cout << "Size of queue is : " << q.size() << endl;

        q.pop();
        q.pop();

        cout << "Size of queue is : " << q.size() << endl;

        if (q.empty())
            cout << " Queue is empty" << endl;

        else
            cout << "Queue is not empty" << endl;

    */
    return 0;
}