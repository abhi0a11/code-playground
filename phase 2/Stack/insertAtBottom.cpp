#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s, int element)
{
    //base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s,element);

    s.push(num);


}
int main()
{
    stack<int> s;
    return 0;
}