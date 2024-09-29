#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& ans,int n, int i){
    
    int left = 2*i +1;
    int right = 2*i+2;
    int largest =i;
    
    if(left<n && ans[largest] < ans[left]){
        largest = left;
    }
    if(right < n && ans[largest] < ans[right]){
        largest = right;
    }

    if( largest != i){
       swap(ans[i] , ans[largest]);
        heapify(ans,n,largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){
    vector<int> ans;

    for(auto i: a){
        ans.push_back(i);
    }
    for(auto i: b){
        ans.push_back(i);
    }

    for(int i=n/2 -1; i>=0; i--){
        heapify(ans,n+m,i);
    }

    return ans;
}
int main(){
    
    return 0;
}