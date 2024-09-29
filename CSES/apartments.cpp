#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desire(n);
    for(int i=0; i<n; i++){
        cin>>desire[i];
    }   
    vector<int> arr(m);
    for(int i=0; i<m; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    sort(desire.begin(), desire.end());
    
    int cnt=0,i=0,j=0;
    while(i<n && j<m){
        if(desire[i]-k <= arr[j] && arr[j] <= desire[i]+k){
            cnt++;
            i++;
            j++;
        }
        else if(arr[j] > desire[i]+k){
            i++;
        } 
        else{
            j++;
        }
    }
    cout<<cnt;
    return 0;
}