#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    
    vector<int> start(n) , end(n);
    for(int i=0; i<n; i++){
        cin>>start[i];
    }
    for(int i=0; i<n; i++){
        cin>>end[i];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i=0, j=0;
    long cnt = 0;
    long maxi = LONG_MIN;
    while(i<n && j<n){
        if(start[i] < end[j]){
            cnt++;
            i++;
            maxi = max(cnt,maxi);
        }
        else{
            maxi = max(cnt,maxi);
            cnt--;
            j++;
        }
    }
    cout<<maxi;
    return 0;
}