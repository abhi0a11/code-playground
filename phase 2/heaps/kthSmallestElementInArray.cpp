#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    // s = starting index of array
    // e = ending index of array
int kthSmallest(int arr[],int s,int e,int k){
    priority_queue<int> pq;
    
    //step 1
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    //step 2
    for(int i=k;i<=e; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    //ans = pq.top()
    int ans = pq.top();
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,6,7,8,9,10};
    cout<<kthSmallest(arr,0,8,5);
    return 0;
}