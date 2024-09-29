#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    long sum = 0;
    long maxi = LONG_MIN;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxi = max(maxi, sum);

        if(sum < 0)    sum = 0;
    } 
    cout<<maxi;
    return 0;
}