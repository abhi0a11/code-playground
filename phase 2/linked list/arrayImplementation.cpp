#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    vector<int> arr;

    node()
    {
    }

    int get(int index)
    {
        if (index < arr.size() && index >= 0)
        {
            return arr[index];
        }
        else
            return -1;
    }

    void addAtHead(int val)
    {
        arr.insert(arr.begin(), val);
    }

    void addAtTail(int val)
    {
        arr.push_back(val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < arr.size())
        {
            arr.insert(arr.begin() + index, val);
        }
        else if (index == arr.size())
        {
            arr.push_back(val);
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < arr.size())
        {
            arr.erase(arr.begin() + index);
        }
    }
};
int main()
{

    return 0;
}