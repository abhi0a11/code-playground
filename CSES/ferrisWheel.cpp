#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }   

    sort(v.begin(), v.end());
    // for(auto i:v)   cout<<i<<" ";cout<<endl;
    long ans=0;
    int i=0,j=n-1;
    while(i<j){
        if(v[i] + v[j] <= k){
            i++;
            j--;
            ans++;
        }
        else if(v[i] + v[j] > k){
            j--;
        }
    } 
    if(2*ans != n)  ans += n-2*ans;
    cout<<ans;
}