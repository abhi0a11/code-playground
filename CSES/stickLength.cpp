#include<bits/stdc++.h>
using namespace std;
long getLen(vector<int>& arr, int k){
    long ans = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        ans += abs(arr[k] - arr[i]);
    }
    return ans;
}
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)  cin>>arr[i];
    sort(arr.begin(), arr.end());

    long ans = 0;
    if(n%2 == 1){
      int mid = (n-1)/2;
      ans =  getLen(arr,mid);
    }
    else{
        int m1 = (n-1)/2;
        int m2 = m1 + 1;
        
        ans = min(getLen(arr,m1) , getLen(arr,m2));
    }
    cout<<ans;

    return 0;
}