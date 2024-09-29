#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)  cin>>arr[i];

    sort(arr.begin(), arr.end());

    long sum  = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > sum){
            cout<<sum;
            return 0;
        }

        sum += arr[i];
    }
    cout<<sum;
    return 0;
}