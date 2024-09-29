#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &M, int a,int b, int n){
    if(M[a][b] == 1)    return true;
    else    return false;
}

int celebrityProblem(vector<vector<int>> &M, int n)
{

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step2: get 2 elements ans compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M,a, b,n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    // step3: single element in stack is potential candidate
    // so verify it

    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }

    // all zeroes
    if (zeroCount != n)
        return -1;

    // col check
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans])
        {
            oneCount++;
        }
    }

    // all ones
    if (oneCount != n - 1)
        return -1;

    return ans;
}

int main()
{

    return 0;
}