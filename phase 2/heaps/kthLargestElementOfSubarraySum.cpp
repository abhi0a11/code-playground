#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int kthlargestSumOfAllSubarray(vector<int> a,int k){

    priority_queue<int,vector<int>,greater<int>> pq;

    int n = a.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(pq.size() < k){
                pq.push(sum);
            }
            else{
                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}

int main(){
    
    return 0;
}