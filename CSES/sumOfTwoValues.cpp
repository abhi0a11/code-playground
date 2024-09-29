#include<bits/stdc++.h>
using namespace std;

int main(){
    long n,k;
    cin>>n>>k;
    vector<pair<long,long>> arr(n);
    for(int i=0; i<n; i++){
        int val; cin>>val;

        arr[i] = {val,i};       
    }
    sort(arr.begin(), arr.end());

    int i=0, j=n-1;
    while(i<j){
        if(arr[i].first + arr[j].first == k){
            int a = arr[i].second+1;
            int b =  arr[j].second+1;
            if(a > b) swap(b,a);
            cout<<a<<" "<<b;
            return 0;
        }
        else if(arr[i].first + arr[j].first > k){
            j--;
        }
        else    i++;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}