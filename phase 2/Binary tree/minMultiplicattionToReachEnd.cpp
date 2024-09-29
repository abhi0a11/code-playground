#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 100000;
int minMultiplications(vector<int>&arr, int start, int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    
    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto it:arr){
            int num = (it * node) % mod;
            if(num == end)  return steps+1;
            q.push({num,steps+1});
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {3,4,65};
   cout<< minMultiplications(arr,7,66175);

    return 0;
}