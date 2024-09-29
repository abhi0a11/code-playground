#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmaller(vector<int> arr, int size) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(size);

    for (int i = size - 1; i >= 0; i--) {
        while (s.top() != -1 && s.top() >= arr[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main() {
    vector<int> small{ 3,0,0,2,0,4 };
    small = nextSmaller(small, 6);
    for (auto i : small) {
        cout << i << " ";
    }
    return 0;
}