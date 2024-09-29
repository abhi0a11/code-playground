#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> nums;
    int cnt = 1;
    for(int i=0;i<n; i++){
        int a;cin>>a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());

    for(int i=1; i<n; i++){
        if(nums[i-1] != nums[i])    cnt++;
    }
    cout<<cnt;
    return 0;
}