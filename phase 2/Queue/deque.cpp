#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool pushFront(int x)
    {
        if (isFull())
        {
            return false;
        }

        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
            front--;

        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }

        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear = size - 1 && front != 0)
        {
            rear = 0;
        }
        else
            rear++;

        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    int popRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }

        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
            return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
            return arr[rear];
    }
    int isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
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
            cout << " Deque is empty" << endl;

        else
            cout << "Deque is not empty" << endl;

    */
    return 0;
}